add_executable(exerciceP9_v1_P13
  exerciceP9_v1.cc
  ../../../commun/Vecteur3D/Vecteur3D.cc
  ../../../commun/Aleatoire/Aleatoire.cc
  ../../Plan/Plan.cc
  ../../Obstacle/Obstacle.cc
  ../../Particule/Particule.cc
  Systeme/Systeme.cc
  ../../Source/Source.cc
  Grille/Grille.cc
  CalculGrille/CalculGrille.cc
  ../../Calcul/CalculNaif.cc
    ../../ParticuleNeige/ParticuleNeige.cc
        ../../ParticuleRoche/ParticuleRoche.cc
)
target_compile_options(exerciceP9_v1_P13 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(exerciceP9_v2_P13
  exerciceP9_v2.cc
  ../../../commun/Vecteur3D/Vecteur3D.cc
  ../../../commun/Aleatoire/Aleatoire.cc
  ../../Plan/Plan.cc
  ../../Obstacle/Obstacle.cc
  ../../Particule/Particule.cc
  Systeme/Systeme.cc
  ../../Source/Source.cc
  Grille/Grille.cc
  CalculGrille/CalculGrille.cc
  ../../Calcul/CalculNaif.cc
    ../../ParticuleNeige/ParticuleNeige.cc
        ../../ParticuleRoche/ParticuleRoche.cc
)
target_compile_options(exerciceP9_v2_P13 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(chute_libreP13
  chute_libre.cc
  ../../../commun/Vecteur3D/Vecteur3D.cc
  ../../../commun/Aleatoire/Aleatoire.cc
  ../../Plan/Plan.cc
  ../../Obstacle/Obstacle.cc
  ../../Particule/Particule.cc
  Systeme/Systeme.cc
  ../../Source/Source.cc
  Grille/Grille.cc
  CalculGrille/CalculGrille.cc
  ../../Calcul/CalculNaif.cc
    ../../ParticuleNeige/ParticuleNeige.cc
        ../../ParticuleRoche/ParticuleRoche.cc
)
target_compile_options(chute_libreP13 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testP5_P13
  testP5.cc
  ../../../commun/Vecteur3D/Vecteur3D.cc
  ../../../commun/Aleatoire/Aleatoire.cc
  ../../Plan/Plan.cc
  ../../Obstacle/Obstacle.cc
  ../../Particule/Particule.cc
  Systeme/Systeme.cc
  ../../Source/Source.cc
  Grille/Grille.cc
  CalculGrille/CalculGrille.cc
  ../../Calcul/CalculNaif.cc
    ../../ParticuleNeige/ParticuleNeige.cc
)
target_compile_options(testP5_P13 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testGrilleP13
  Grille/testGrille.cc
  ../../../commun/Vecteur3D/Vecteur3D.cc
  ../../../commun/Aleatoire/Aleatoire.cc
  ../../Plan/Plan.cc
  ../../Obstacle/Obstacle.cc
  ../../Particule/Particule.cc
  ../../Calcul/CalculNaif.cc
  Systeme/Systeme.cc
  ../../Source/Source.cc
  Grille/Grille.cc
  CalculGrille/CalculGrille.cc
    ../../ParticuleNeige/ParticuleNeige.cc
        ../../ParticuleRoche/ParticuleRoche.cc
)
