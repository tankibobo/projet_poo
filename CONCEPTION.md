# CONCEPTION — Points importants du projet POO

## 1. Architecture générale

Le projet est organisé en dossiers séparés par étape (`version-1`, `commun`, `exerciceP10`,
`exerciceP11-revisiteP9`, `exerciceP11-v2`, `ex_P12-P13_et_extensions`). Une bibliothèque
partagée `commun` est compilée une seule fois et linkée à tous les exécutables. Chaque classe
est isolée dans son propre sous-dossier avec son `.h` et son `.cc`. La configuration CMake
gère les dépendances entre les modules.

---

## 2. Hiérarchie des classes et polymorphisme

```
Particule (abstraite)          Obstacle (abstraite)
├── ParticuleSimple            ├── Plan
├── Balle (exerciceP10)        ├── Brique
├── ParticuleNeige             └── Cylindre
└── ParticuleRoche
```

`Particule` est abstraite car `dessine_sur()` est virtuelle pure. Il est donc impossible
d'instancier une particule sans préciser son type concret, ce qui garantit le bon
fonctionnement du double dispatch. De même, `Obstacle` est abstraite via `PointPlusProche()`
et `affiche()`.

---

## 3. Pattern Visiteur — double dispatch

C'est le mécanisme central du rendu. Problème : comment appeler la bonne méthode de dessin
selon le type réel d'un objet, sans `dynamic_cast` ou `if/else` dans le moteur de rendu ?

**Solution — double dispatch :**
- `Dessinable` : interface avec `virtual void dessine_sur(SupportADessin&) = 0`
- `SupportADessin` : interface avec des overloads `dessine(Particule const&)`,
  `dessine(Obstacle const&)`, `dessine(Source const&)`, `dessine(Systeme const&)`
- Chaque classe concrète implémente `dessine_sur` en appelant `support.dessine(*this)`

Le type de `*this` est connu statiquement dans chaque `dessine_sur` (type concret),
donc le bon overload de `dessine` est choisi à la compilation. Le choix de l'objet appelant
est résolu dynamiquement (vtable), puis le choix de l'overload statiquement : deux niveaux
de dispatch.

Deux supports sont implémentés : `TextViewer` (affichage textuel) et `raylibRender`
(affichage 3D). Ajouter un nouveau support ne nécessite pas de modifier les classes de
particules.

---

## 4. Forces de Lennard-Jones et intégration

La force entre deux particules i et j est dérivée du potentiel :

    V(r) = 4ε [ (σ/r)^12 − (σ/r)^6 ]

avec σ_eff = (σ_i + σ_j)/2 et ε_eff = sqrt(ε_i · ε_j) pour les paires mixtes.

Un cutoff à r > 2σ annule la force pour éviter des calculs inutiles entre particules éloignées.
L'intégration est faite par la méthode d'Euler explicite avec un pas de temps dt configurable.
La gravité est ajoutée comme force constante selon −z.

---

## 5. Obstacles — deux mécanismes de contrainte

Chaque obstacle implémente deux mécanismes complémentaires :

**Force LJ (douce)** : via `PointPlusProche(xi)` qui retourne le point de l'obstacle
le plus proche de la particule. La distance à ce point sert à calculer une force répulsive
LJ, exactement comme entre deux particules. Cela assure une répulsion progressive.

**Collision géométrique (dure)** : via `collision(Particule&)` qui détecte si la
particule est à l'intérieur de l'obstacle et corrige sa vitesse par rebond instantané.
La loi de rebond est : `v' = v − (1+e)(v·n̂)n̂` avec e ∈ [0,1] le coefficient de
restitution (1 = élastique, 0 = parfaitement inélastique). Le coefficient est clampé
à 1 si une valeur hors plage est fournie.

**Remarque sur le Plan** : `Plan` n'implémente pas de `collision()` géométrique — il
repose uniquement sur la force LJ douce. À très haute vitesse, des particules peuvent
traverser le plan entre deux pas de temps (tunneling numérique). Ce comportement est
connu et accepté dans notre conception.

---

## 6. Grille d'optimisation des interactions (P12/P13)

Sans grille, le calcul des forces LJ est en O(n²). La grille réduit à O(n) en moyenne.

**Principe** : la taille de case est égale à σ (rayon de coupure). Une particule n'interagit
qu'avec les particules dans les 27 cases voisines en 3D (rayon 1 case dans chaque direction).

**P12 — Grille tableau** (`vector<vector<Particule*>>`) :
- Indexation directe : `indice = ix + nx*(iy + ny*iz)`
- Taille fixe allouée à l'initialisation ; la fonction `agrandirGrille` redimensionne
  si une particule sort des bornes
- Accès O(1), mémoire O(nx·ny·nz) même pour les cases vides

**P13 — Grille map** (`map<array<int,3>, vector<Particule*>>`) :
- Seules les cases occupées existent en mémoire → adapté aux systèmes épars
- Accès O(log n) par clé, mais mémoire proportionnelle aux cases occupées uniquement
- Les entrées vides sont supprimées explicitement après `retirerParticule` pour éviter
  une accumulation de cases fantômes dans la map

---

## 7. Source de particules

La `Source` génère des particules à chaque pas de temps selon un débit (particules/seconde).
Les rayons et les vitesses initiales sont tirés selon une loi normale (classe `Aleatoire`,
basée sur `std::normal_distribution`). Le modèle de particule est stocké par référence
constante dans la `Source` : la `Source` ne possède pas la particule modèle, elle la clone.
La copie de `Source` est désactivée pour éviter des problèmes de durée de vie du générateur.

---

## 8. Gestion mémoire

Les `Particule*`, `Obstacle*` et `Source*` stockés dans `Systeme` sont alloués dynamiquement
(`new`) par l'utilisateur et détruits dans le **destructeur de Systeme** par des `delete`
explicites. La copie de `Systeme` est désactivée (`= delete`) pour éviter les double-free.
Les particules supprimées en cours de simulation (hors des bornes) sont retirées du vecteur
et `delete`-ées immédiatement dans `Systeme::evolue()`.

---

## 9. Version graphique — raylib

**Changement de repère** : le simulateur utilise Z comme axe vertical, raylib utilise Y.
La conversion `simToRay(x,y,z) → {x, z, y}` est appliquée à toutes les positions.

**Détection des types** : `raylibRender::dessine(Particule const&)` utilise `dynamic_cast`
pour choisir la couleur selon le type concret (Neige = bleu, Roche = marron). De même pour
les obstacles (`Brique`, `Cylindre`, `Plan`) dans `dessine(Obstacle const&)` — ce centralise
la logique de rendu dans le renderer sans polluer les classes de données.

**Interactivité** : L = caméra libre (WASD + souris), O = sources on/off,
UP/DOWN = débit ±10 particules/s.

**Compatibilité** : raylib est cherchée localement en premier (`find_package`), puis
téléchargée et compilée automatiquement via `FetchContent` si non trouvée (VMs de l'école).
