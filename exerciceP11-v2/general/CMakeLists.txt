add_executable(testParticules
  Particule/testParticules.cc
  Particule/Particule.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  Plan/Plan.cc
  Obstacle/Obstacle.cc
  ParticuleNeige/ParticuleNeige.cc
  ParticuleRoche/ParticuleRoche.cc
)
target_compile_options(testParticules PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(exerciceP9_v1_P11-v2
  exerciceP9_v1.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Aleatoire/Aleatoire.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  ParticuleNeige/ParticuleNeige.cc
  ParticuleRoche/ParticuleRoche.cc
  Plan/Plan.cc
  Source/Source.cc
  Systeme/Systeme.cc
)
)
target_compile_options(exerciceP9_v1_P11-v2 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(exerciceP9_v2_P11-v2
  exerciceP9_v2.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Aleatoire/Aleatoire.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  ParticuleNeige/ParticuleNeige.cc
  ParticuleRoche/ParticuleRoche.cc
  Plan/Plan.cc
  Source/Source.cc
  Systeme/Systeme.cc
)
target_compile_options(exerciceP9_v2_P11-v2 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(chute_libre_P11-v2
  chute_libre.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Aleatoire/Aleatoire.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  ParticuleNeige/ParticuleNeige.cc
  ParticuleRoche/ParticuleRoche.cc
  Plan/Plan.cc
  Source/Source.cc
  Systeme/Systeme.cc
)
target_compile_options(chute_libre_P11-v2 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testSourceP11-v2
  Source/testSource.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Aleatoire/Aleatoire.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  ParticuleNeige/ParticuleNeige.cc
  ParticuleRoche/ParticuleRoche.cc
  Plan/Plan.cc
  Source/Source.cc
  Systeme/Systeme.cc
)
target_compile_options(testSourceP11-v2 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testSystemeP11-v2
  Systeme/testSysteme.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Aleatoire/Aleatoire.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  ParticuleNeige/ParticuleNeige.cc
  ParticuleRoche/ParticuleRoche.cc
  Plan/Plan.cc
  Source/Source.cc
  Systeme/Systeme.cc
)
target_compile_options(testSystemeP11-v2 PRIVATE ${PROJECT_WARNING_FLAGS})