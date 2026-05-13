add_executable(testParticules
  Particule/testParticules.cc
  Particule/Particule.cc
  Vecteur3D/Vecteur3D.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  ParticuleNeige/ParticuleNeige.cc
  ParticuleRoche/ParticuleRoche.cc
)
target_compile_options(testParticule PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(exerciceP9_v1_v3
  exerciceP9_v1.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  Systeme/Systeme.cc
  ParticuleNeige/ParticuleNeige.cc
  ParticuleRoche/ParticuleRoche.cc
)
target_compile_options(exerciceP9_v1 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(exerciceP9_v2_v3
  exerciceP9_v2.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  Systeme/Systeme.cc
  ParticuleNeige/ParticuleNeige.cc
  ParticuleRoche/ParticuleRoche.cc
)
target_compile_options(exerciceP9_v2 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(chute_libre_v3
  chute_libre.cc
  Source/Source.cc
  Vecteur3D/Vecteur3D.cc
  Aleatoire/Aleatoire.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  Systeme/Systeme.cc
  ParticuleNeige/ParticuleNeige.cc
  ParticuleRoche/ParticuleRoche.cc
)
target_compile_options(chute_libre PRIVATE ${PROJECT_WARNING_FLAGS})