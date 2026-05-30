include_directories(. ../commun/)
add_subdirectory(exerciceP12)
add_subdirectory(exerciceP13)

add_executable(testSourceP12-P13
  Source/testSource.cc
  ../commun/Vecteur3D/Vecteur3D.cc
  ../commun/Aleatoire/Aleatoire.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  Source/Source.cc
  ParticuleNeige/ParticuleNeige.cc
)
target_compile_options(testSourceP12-P13 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testSystemeP12
  Systeme/testSystemeP12.cc
  Systeme/Systeme.cc
  ../commun/Vecteur3D/Vecteur3D.cc
  ../commun/Aleatoire/Aleatoire.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  Calcul/CalculNaif.cc
  Source/Source.cc
  ParticuleNeige/ParticuleNeige.cc
  ParticuleRoche/ParticuleRoche.cc
  exerciceP12/general/CalculGrille/CalculGrille.cc
  exerciceP12/general/Grille/Grille.cc
)
target_compile_options(testSystemeP12 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testSystemeP13
  Systeme/testSystemeP12.cc
  Systeme/Systeme.cc
  ../commun/Vecteur3D/Vecteur3D.cc
  ../commun/Aleatoire/Aleatoire.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  ParticuleNeige/ParticuleNeige.cc
  ParticuleRoche/ParticuleRoche.cc
  Calcul/CalculNaif.cc
  Source/Source.cc
  exerciceP13/general/CalculGrille/CalculGrille.cc
  exerciceP13/general/Grille/Grille.cc
)
target_compile_options(testSystemeP13 PRIVATE ${PROJECT_WARNING_FLAGS})