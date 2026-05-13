add_executable(testParticuleNeige
  ParticuleNeige/testParticuleNeige.cc
  Particule/Particule.cc
  Vecteur3D/Vecteur3D.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  ParticuleNeige/ParticuleNeige.cc
)
target_compile_options(testParticule PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testSource_v2
  Source/testSource.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Particule/Particule.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  ParticuleNeige/ParticuleNeige.cc
)
target_compile_options(testSource PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testSysteme_v2
  Systeme/testSysteme.cc
  Systeme/Systeme.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Particule/Particule.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  ParticuleNeige/ParticuleNeige.cc
)
target_compile_options(testSysteme PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(exerciceP9_v1_v2
  exerciceP9_v1.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  Systeme/Systeme.cc
    ParticuleNeige/ParticuleNeige.cc
)
target_compile_options(exerciceP9_v1 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(exerciceP9_v2_v2
  exerciceP9_v2.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  Systeme/Systeme.cc
    ParticuleNeige/ParticuleNeige.cc
)
target_compile_options(exerciceP9_v2 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(chute_libre_v2
  chute_libre.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  Systeme/Systeme.cc
  ParticuleNeige/ParticuleNeige.cc
)
target_compile_options(chute_libre PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testP5_v2
  testP5.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  Systeme/Systeme.cc
  ParticuleNeige/ParticuleNeige.cc
)
target_compile_options(testP5 PRIVATE ${PROJECT_WARNING_FLAGS})
