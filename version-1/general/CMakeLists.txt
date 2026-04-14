add_executable(testVecteur3D
  Vecteur3D/testVecteur3D.cc
  Vecteur3D/Vecteur3D.cc
)
target_compile_options(testVecteur3D PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testParticule
  Particule/testParticule.cc
  Particule/Particule.cc
  Vecteur3D/Vecteur3D.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
)
target_compile_options(testParticule PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testPlan
  Plan/testPlan.cc
  Plan/Plan.cc
  Vecteur3D/Vecteur3D.cc
  Obstacle/Obstacle.cc
)
target_compile_options(testPlan PRIVATE ${PROJECT_WARNING_FLAGS})


add_executable(testSource
  Source/testSource.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Particule/Particule.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
)
target_compile_options(testSource PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testSysteme
  Systeme/testSysteme.cc
  Systeme/Systeme.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Particule/Particule.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
)
target_compile_options(testSysteme PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(exerciceP9_v1
  exerciceP9_v1.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  Systeme/Systeme.cc
)
target_compile_options(exerciceP9_v1 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(exerciceP9_v2
  exerciceP9_v2.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  Systeme/Systeme.cc
)
target_compile_options(exerciceP9_v2 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(chute_libre
  chute_libre.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  Systeme/Systeme.cc
)
target_compile_options(chute_libre PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testP5
  testP5.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  Systeme/Systeme.cc
)
target_compile_options(testP5 PRIVATE ${PROJECT_WARNING_FLAGS})
