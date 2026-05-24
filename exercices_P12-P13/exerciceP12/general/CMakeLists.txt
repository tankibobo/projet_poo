add_executable(exerciceP9_v1_P12
  exerciceP9_v1.cc
  ../../../commun/Vecteur3D/Vecteur3D.cc
  ../../../commun/Aleatoire/Aleatoire.cc
  ../../../commun/Plan/Plan.cc
  ../../../commun/Obstacle/Obstacle.cc
  ../../Particule/Particule.cc
  ../../Systeme/Systeme.cc
  ../../Source/Source.cc
  Grille/Grille.cc
  CalculGrille/CalculGrille.cc
)
target_compile_options(exerciceP9_v1_P12 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(exerciceP9_v2_P12
  exerciceP9_v2.cc
  ../../../commun/Vecteur3D/Vecteur3D.cc
  ../../../commun/Aleatoire/Aleatoire.cc
  ../../../commun/Plan/Plan.cc
  ../../../commun/Obstacle/Obstacle.cc
  ../../Particule/Particule.cc
  ../../Systeme/Systeme.cc
  ../../Source/Source.cc
  Grille/Grille.cc
  CalculGrille/CalculGrille.cc
)
target_compile_options(exerciceP9_v2_P12 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(chute_libreP12
  chute_libre.cc
  ../../../commun/Vecteur3D/Vecteur3D.cc
  ../../../commun/Aleatoire/Aleatoire.cc
  ../../../commun/Plan/Plan.cc
  ../../../commun/Obstacle/Obstacle.cc
  ../../Particule/Particule.cc
  ../../Systeme/Systeme.cc
  ../../Source/Source.cc
  Grille/Grille.cc
  CalculGrille/CalculGrille.cc
)
target_compile_options(chute_libreP12 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testP5_P12
  testP5.cc
  ../../../commun/Vecteur3D/Vecteur3D.cc
  ../../../commun/Aleatoire/Aleatoire.cc
  ../../../commun/Plan/Plan.cc
  ../../../commun/Obstacle/Obstacle.cc
  ../../Particule/Particule.cc
  ../../Systeme/Systeme.cc
  ../../Source/Source.cc
  Grille/Grille.cc
  CalculGrille/CalculGrille.cc
)
target_compile_options(testP5_P12 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testGrilleP12
  Grille/testGrille.cc
  ../../../commun/Vecteur3D/Vecteur3D.cc
  ../../../commun/Aleatoire/Aleatoire.cc
  ../../../commun/Plan/Plan.cc
  ../../../commun/Obstacle/Obstacle.cc
  ../../Particule/Particule.cc
  ../../Calcul/CalculNaif.cc
  ../../Systeme/Systeme.cc
  ../../Source/Source.cc
  Grille/Grille.cc
  CalculGrille/CalculGrille.cc
)
target_compile_options(testGrilleP12 PRIVATE ${PROJECT_WARNING_FLAGS})