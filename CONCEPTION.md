# CONCEPTION

## 1) Particules (classes Agent, Particule, ParticuleNeige, ParticuleRoche)

**Semaine 1 à 10 :** Seule la classe Particule existe dans la modélisation des particules. On
choisit de mettre tous les paramètres y compris celle de la masse volumique du milieu dans le
constructeur. La masse, elle, est déduite à partir de la masse volumique de la particule et de
son rayon.

**Après semaine 10 :** Particule est une sous-classe d'Agent. Particule et Agent sont abstraites,
on instancie seulement un certain type de particule : ParticuleNeige et ParticuleRoche. Ces
particules sont quasi-identiques, elles ont simplement des méthodes pour modéliser leurs
interactions entre elles, et leurs epsilon et sigma changent (conformément au modèle LLJ/WCA).
Pour calculer les interactions entre des particules de différents types (ie. avec des sigmas et
des epsilons différents), on fait une moyenne géométrique/arithmétique entre les sigmas et epsilons.

**Semaine 12/13 :** On ajoute aux particules des positions x, y, z correspondant à leurs positions
dans une grille potentielle. Même si cela relève d'une fuite d'abstraction, elle est assumée : elle
permet un gain de temps non-négligeable dans les méthodes de la classe Grille, notamment pour
accéder rapidement aux positions des particules ou pour accéder à leur position précédente dans
la grille.

---

## 2) Obstacles (classes Obstacle, Plan, Dalle, Brique, Cylindre)

**Semaine 1 à 10 :** Seules les classes Plan et Dalle existent. Les particules interagissent avec
surtout Plan dans l'exercice P10.

**Semaine complémentaire / extensions :** Ajout de la `Brique` (parallélépipède orientable) et du
`Cylindre` (cylindre droit d'axe quelconque), qui introduisent toutes deux le rebond géométrique dur.

La classe abstraite `Obstacle` impose `PointPlusProche()` (virtuelle pure, utilisée pour la force LJ)
et fournit une méthode `collision()` avec corps vide par défaut — seuls Brique et Cylindre la
surchargent.

- **Plan** : position + normale unitaire. 6 constructeurs disponibles (normale seule, position + normale,
  composantes séparées ou Vecteur3D). Repose uniquement sur LJ ; pas de rebond dur.
- **Dalle** (hérite de Plan) : plan de dimensions finies. Ajoute longueur, largeur, direction_longueur.
  La direction_largeur est déduite automatiquement par `~(normale ^ direction_longueur)`.
- **Brique** : centre, demi-dimensions (longueur, largeur, profondeur), deux directions (la troisième
  est déduite par produit vectoriel), coefficient de restitution ∈ [0,1] (clampé à 1 si hors plage).
  `collision()` identifie la face la plus proche et applique `v' = v − (1+e)(v·n̂)n̂`.
- **Cylindre** : centre, rayon, demi_hauteur, normale (axe), restitution, flag `avec_lj` (permet de
  désactiver la force LJ pour un cylindre utilisé en paroi seule). `PointPlusProche()` décompose la
  position en composante axiale et radiale pour traiter surface latérale et fond séparément.

---

## 3) Sources (classe Source)

La `Source` contient une position, une vitesse moyenne, des écarts-types (vitesse et rayon), un
débit (particules/seconde), un état (on/off), une **référence constante** vers une particule modèle
et une **référence** vers un générateur aléatoire. La copie de `Source` est désactivée car la
référence au générateur ne peut pas être réassignée.

### `creation()` et `copie()`

À chaque pas de temps, `creation()` calcule combien de particules émettre (`floor(debit * dt)`,
avec tirage aléatoire pour la partie fractionnaire). Pour chaque particule, elle appelle
`modele.copie()`, puis tire aléatoirement vitesse et rayon selon des lois normales.

`copie()` est **virtuelle pure** dans `Particule`, implémentée en une ligne dans chaque sous-classe :

```cpp
virtual Particule* copie() const override { return new ParticuleNeige(*this); }
```

Ce **clonage virtuel** permet à `Source` de dupliquer la particule modèle sans connaître son type
concret — pas besoin de `dynamic_cast` ni de factory explicite.

---

## 4) Système

**Semaine 1 à 11 :** Le système a plusieurs constructeurs, le plus important étant celui par défaut
(qui rend une liste vide, et met le temps à 0) et celui qui prend des listes d'agents (particule,
obstacle, source) en paramètre. Le système est maître du temps une fois que celui-ci est fixé, et
maître des agents : l'appelant passe en paramètre un pointeur vers un agent, et perd sa propriété.
C'est la classe qui le détruit. Un système ne peut pas être copié.

**Semaine 12/13 :** Ce qui change ici, c'est surtout le constructeur de Système. On ajoute un `bool`,
qui décide si le système utilise une grille ou non. Si c'est le cas, le système initialise un pointeur
vers un `CalculGrille`, qui lui initialise une grille avec les particules initialisées par le pointeur
(s'il y en a). La méthode `evolue()` utilise alors les méthodes de `CalculGrille`.

---

## 5) Calcul par les grilles (Calcul, CalculGrille, CalculNaif, Grille, Triplet)

Cette partie est sans aucun doute la plus complexe de notre code. Avant de s'attaquer aux cas
limites, on choisit une implémentation basique, où on ne traite pas les cas où les particules
dépassent les bornes de la grille. Le constructeur utilise les coordonnées maximales des particules
passées en argument pour initialiser la grille à une certaine taille. On crée la fonction
« troncature » qui arrondit les doubles vers le bas, car sinon, si on a des particules à
(-0.8, 0.9, -0.1) et (0.1, 0.2, 0.3) avant l'arrondi (ce qui implique qu'elles ne sont pas dans
la même case), elles finissent toutes les deux en [0][0][0] dans la grille car C++ arrondit vers 0.

On distingue deux façons pour une particule de dépasser les bornes de la grille :

1. En ayant un indice plus grand que la taille de la grille
2. En ayant une position négative dans la grille

Pour le cas 1), on agrandit la grille et on y ajoute les particules : on utilise pour cela la
fonction `resize()`.

Pour le cas 2), on décale toute la grille afin que les coordonnées des particules concernées
deviennent positives. Pour ce faire, on prend le minimum des coordonnées de toutes les particules
(c'est-à-dire le point le plus bas tel que tous les autres particules soient au-dessus), on
sauvegarde le décalage de l'origine vers ce point dans les attributs `decalage_{x,y,z}`, et on
vide et rerempli la grille avec les nouvelles coordonnées.

À la base, notre méthode `getParticules()` était très coûteuse et parcourait toute la grille, mais
on a ajouté un pointeur vers un système, pour que la grille puisse accéder aux particules du système
directement. Le double pointage entre Système et Grille (par CalculGrille) n'est pas problématique
puisque les trois sont tout le temps détruits en même temps : système détruit calcul qui détruit grille.

Avec la map (P13), on n'a pas le problème de dépassement d'indices et le code est beaucoup plus simple.

---

## 6) Outils Mathématiques (Vecteur3D, Aléatoire)

**Vecteur3D :**
