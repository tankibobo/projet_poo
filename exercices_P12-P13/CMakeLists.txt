add_subdirectory(exerciceP12)
add_subdirectory(exerciceP13)
include_directories(. ../commun/)

add_executable(testSourceP12-P13
  Source/testSource.cc
  ../commun/Vecteur3D/Vecteur3D.cc
  ../commun/Aleatoire/Aleatoire.cc
  ../commun/Plan/Plan.cc
  ../commun/Obstacle/Obstacle.cc
  Particule/Particule.cc
  Source/Source.cc
)
target_compile_options(testSourceP12-P13 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testSystemeP12-P13
  Systeme/testSysteme.cc
  ../commun/Systeme/Systeme.cc
  ../commun/Vecteur3D/Vecteur3D.cc
  ../commun/Aleatoire/Aleatoire.cc
  ../commun/Plan/Plan.cc
  ../commun/Obstacle/Obstacle.cc
  Particule/Particule.cc
  Source/Source.cc
)
target_compile_options(testSystemeP12-P13 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testParticuleP12-P13
  Particule/testParticule.cc
  ../commun/Vecteur3D/Vecteur3D.cc
  ../commun/Plan/Plan.cc
  ../commun/Obstacle/Obstacle.cc
  Particule/Particule.cc
)
target_compile_options(testParticuleP12-P13 PRIVATE ${PROJECT_WARNING_FLAGS})