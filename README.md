# README – Projet POO C++

**Auteurs :** Romain Levard (romain.levard@epfl.ch), Tancrède Bohbot (tancrede.bohbot@epfl.ch)

Nous avons complété toutes les étapes du projet (P1-P13) ainsi que plusieurs extensions.
Les extensions implémentées incluent : obstacles (Brique, Cylindre), affichage d'énergie
en temps réel, et trois simulations d'extension (Galton, enclos multi-sources, rebond).
Nous avons choisi « l'algorithme 2 » pour modéliser le déplacement des particules.

Nous avons une partie graphique. On utilise Raylib 5.5, la bibliothèque est détectée
automatiquement par CMake via `find_package(raylib)`. Si elle n'est pas installée
localement, elle est téléchargée et compilée automatiquement depuis GitHub via FetchContent.

Par personne, nous avons passé en moyenne **2,5h** par semaine.

---

## I. Description

Le projet a pour but de simuler le comportement d'un amas de particules de neiges et de
roches dans un milieu avec des obstacles. Le programme prend en compte les forces de
frottements, de gravité, d'attractions et de collisions par les modèles de Lennard-Jones et
de Weeks-Chandler-Anderson et permet la création de particules par des sources. La
simulation de l'amas des particules peut être imprimée dans un fichier texte, visualisée en
2 ou 3 dimensions après leur déplacement sur un intervalle `dt`, ou visualisée en 3
dimensions en direct.

---

## II. Architecture du projet

### II.1 Fichiers

Le projet est rigoureusement structuré. Les fichiers sont les suivants :

- **`version-1`** : première version (semaines 1 à 9). Contient un système, des particules,
  des obstacles, des sources, une simulation texte et sur gnuplot.
- **`exerciceP10`** : semaine 10, basé sur v-1. Contient une simulation raylib en plus.
- **`exerciceP11-revisiteP9`** : semaine 11, basé sur v-1. Contient une ParticuleNeige en plus.
- **`exerciceP11-v2`** : basé sur exerciceP11-revisiteP9 avec une ParticuleRoche en plus.
- **`ex_P12-P13_et_extensions`** : semaines 11 à 13, basé sur exerciceP11-v2. Contient
  toutes les extensions, une simulation raylib et l'utilisation de grilles sous forme de
  `map` ou de `vector`.
- **`commun`** : classes partagées par différents exercices.

### II.2 Classes

- *(modèle des particules)* : Agent, Particule, ParticuleNeige, ParticuleRoche
- *(modèles des obstacles)* : Obstacle, Plan, Dalle, Brique, Cylindre
- *(modèle des sources)* : Source
- *(Système)* : Systeme
- *(modèles graphique/texte)* : Dessinable, SupportADessin, raylibRender, TextViewer
- *(calcul et implémentation des grilles)* : Calcul, CalculGrille, CalculNaif, Grille, Triplet
- *(outils mathématiques)* : Aleatoire, Vecteur3D

---

## III. Compilation

Ce projet utilise CMake (MIN VER 3.21) comme système de build. CMake génère les Makefiles
adaptés à votre machine, puis `make` compile.

Raylib est détecté automatiquement. Si le logiciel n'est pas installé localement, il est
téléchargé et compilé depuis GitHub (depuis Raylib lui-même).

Pour construire le projet, veuillez suivre les étapes :

```bash
mkdir build && cd build
cmake ..
make
```

Tous les exécutables sont générés dans `build/bin/`. Pour compiler une cible spécifique :

```bash
make nom_cible
make nom_test
```

Toute exécution textuelle et graphique se fait de même. Depuis la branche générale du
projet, faites :

```bash
./build/bin/nom_de_l_executable
```

**Voici les listes de tous les exécutables du projet :**

- **Simulations graphiques :** `exerciceP10_raylib`, `enclos_sources_differentes`,
  `extension_galton`, `extension_energie`

- **Simulations textes :** `chute_libreP11`, `chute_libreP12`, `chute_libreP13`,
  `chute_libre_P11-v2`, `chute_libre_v1`, `exerciceP10_text`, `exerciceP9_v1_P11`,
  `exerciceP9_v1_P11-v2`, `exerciceP9_v1_P12`, `exerciceP9_v1_P13`, `exerciceP9_v2`,
  `exerciceP9_v2_P11`, `exerciceP9_v2_P11-v2`, `exerciceP9_v2_P12`, `exerciceP9_v2_P13`

- **Tests :** `testGrilleP12`, `testGrilleP13`, `testP5_P11`, `testP5_P12`, `testP5_P13`,
  `testParticule`, `testParticuleNeige`, `testParticuleP10`, `testParticules`,
  `testPlanCommun`, `testSource`, `testSourceP10`, `testSourceP11`, `testSourceP11-v2`,
  `testSourceP12-P13`, `testSysteme`, `testSystemeP10`, `testSystemeP11`,
  `testSystemeP11-v2`, `testSystemeP12`, `testSystemeP13`, `testVecteur3DCommun`

---

## IV. Simulations

### IV.1 Texte

Tout objet `O` est affichable par l'opérateur d'affichage habituel : `std::cout << O`, ou
par l'instanciation d'un `TextViewer`, puis l'utilisation de la méthode
`dessine_sur(TextViewer)` d'un objet de la simulation. L'exécutable `exerciceP9_v1_{P?}`
(`_P?` à compléter par l'exercice de votre choix) vous en donne un premier aspect.

### IV.2 gnuPlot en 2D (`plot`)

À chaque pas de l'évolution du système que vous souhaitez plot, imprimez-le par la méthode
`O.dessine_sur(TextViewer)`. Puis, faites un `std::endl`. Dans votre terminal, dans votre
fichier `build`, mettez :

```bash
./bin/{fichier_execution} | grep 'Pos:' | awk '{gsub(/[(),]/, ""); print $3, $4, $5}' > plot.txt
```

Puis, lancez gnuplot :

```gnuplot
set xlabel "x (mm)"; set ylabel "z (mm)"
set title "{titre}"
set key bottom left
plot "plot.txt" u 1:3 w lp pt 7 title "simulation"
```

Voici un exemple des commandes gnuplot pour le `chute_libre.cc` de `version-1` :

```bash
./bin/chute_libre_v1 | grep 'Pos:' | awk '{gsub(/[(),]/, ""); print $3, $4, $5}' > chute_libre.txt
```

```gnuplot
set xlabel "x (mm)"; set ylabel "z (mm)"
set title "Chute libre"
set key bottom left
plot "chute_libre.txt" u 1:3 w lp pt 7 title "simulation", \
     1.4*x - 196.2*x*x title "parabole théorique (sans frottement)"
```

### IV.3 gnuPlot en 3D (`splot`)

Les exécutables pouvant être `splot` sont tous les `exerciceP11`. Voici les commandes
(dans votre fichier `build`) :

```bash
./bin/{fichier_executables} | grep 'Pos:' > output.txt
awk '{gsub(/[(),]/, ""); print $3, $4, $5}' output.txt > particules-pos.txt
for i in $(seq 4); do awk "NR % 4 == $i % 4" particules-pos.txt > particule${i}_clean.txt; done
```

Puis dans gnuplot :

```gnuplot
set xlabel "x (mm)"; set ylabel "y (mm)"; set zlabel "z (mm)"
set title "Trajectoires P9"
splot "particule1_clean.txt" u 1:2:3 w lp pt 7 title "p1", \
      "particule2_clean.txt" u 1:2:3 w lp pt 7 title "p2", \
      "particule3_clean.txt" u 1:2:3 w lp pt 7 title "p3", \
      "particule4_clean.txt" u 1:2:3 w lp pt 7 title "p4"
```

### IV.4 Contrôle de la simulation graphique

Pour passer la caméra en mode libre, appuyez sur la touche `L`. Vous pourrez ensuite vous
déplacer avec les touches WASD et la souris. Pour repasser en mode fixe, rappuyez sur `L`.
Pour changer l'état des sources (on / off), appuyez sur la touche `O`. Pour augmenter le
débit des sources de 10, appuyez sur la flèche du haut et pour le baisser de 10, appuyez
sur la flèche du bas. Le débit ne descend plus lorsqu'il atteint 0.
