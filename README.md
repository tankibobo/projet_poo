# projet_poo
Projet POO - Simulation de neige mouillée

Tuto pour faire fonctionner l'execution en graphique:

en 3D (splot):
cd build dans le terminal, après:
./bin/[fichier_exec] | grep 'Pos:' > output.txt
awk '{gsub(/[(),]/, ""); print $3, $4, $5}' output.txt > particules-pos.txt
for i in $(seq 4); do awk "NR % 4 == $i % 4" particules-pos.txt > particule${i}_clean.txt; done

puis dans gnuplot (terminal toujours):
set xlabel "x (mm)"; set ylabel "y (mm)"; set zlabel "z (mm)"
set title "Trajectoires P9"
splot "particule1_clean.txt" u 1:2:3 w lp pt 7 title "p1", \
      "particule2_clean.txt" u 1:2:3 w lp pt 7 title "p2", \
      "particule3_clean.txt" u 1:2:3 w lp pt 7 title "p3", \
      "particule4_clean.txt" u 1:2:3 w lp pt 7 title "p4"

en 2D (plot):
cd build dans le terminal, après:
./bin/[fichier_exec] | grep 'Pos:' | awk '{gsub(/[(),]/, ""); print $3, $4, $5}' > chute_libre.txt

puis dans gnuplot (terminal toujours):
set xlabel "x (mm)"; set ylabel "z (mm)"
set title "Chute libre"
set key bottom left
plot "chute_libre.txt" u 1:3 w lp pt 7 title "simulation", \
     1.4*x - 196.2*x*x title "parabole théorique (sans frottement)"

pour le git:

git add .
git commit -m "modifs"
git push

ton truc qui empeche la compilation:
add_subdirectory(PremierExemple)
add_subdirectory(DeuxiemeExemple)
add_subdirectory(TroisiemeExemple)
add_subdirectory(CinquiemeExemple)
add_subdirectory(exerciceP10)

# MacPorts prefix pour trouver raylib
list(APPEND CMAKE_PREFIX_PATH /opt/local)
find_package(raylib REQUIRED)