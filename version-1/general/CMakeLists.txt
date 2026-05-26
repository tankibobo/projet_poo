include_directories(. ../../commun)

add_executable(testParticule
  Particule/testParticule.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Plan/Plan.cc
  ../../commun/Obstacle/Obstacle.cc
  Particule/Particule.cc
)
target_compile_options(testParticule PRIVATE ${PROJECT_WARNING_FLAGS})


add_executable(testSource
  Source/testSource.cc
  ../../commun/Aleatoire/Aleatoire.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Plan/Plan.cc
  ../../commun/Obstacle/Obstacle.cc
  Particule/Particule.cc
  Source/Source.cc
)
target_compile_options(testSource PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testSysteme
  Systeme/testSysteme.cc
  ../../commun/Aleatoire/Aleatoire.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Plan/Plan.cc
  ../../commun/Obstacle/Obstacle.cc
  Particule/Particule.cc
  Source/Source.cc
  Systeme/Systeme.cc
)
target_compile_options(testSysteme PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(chute_libre_v1
  chute_libre.cc
  ../../commun/Aleatoire/Aleatoire.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Plan/Plan.cc
  ../../commun/Obstacle/Obstacle.cc
  Particule/Particule.cc
  Source/Source.cc
  Systeme/Systeme.cc
)
target_compile_options(chute_libre_v1 PRIVATE ${PROJECT_WARNING_FLAGS})
