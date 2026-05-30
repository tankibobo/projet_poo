include_directories(. ../../commun)

add_executable(testParticuleNeige
  ParticuleNeige/testParticuleNeige.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  ParticuleNeige/ParticuleNeige.cc
  Plan/Plan.cc
)
target_compile_options(testParticuleNeige PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testSourceP11
  Source/testSource.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Aleatoire/Aleatoire.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  ParticuleNeige/ParticuleNeige.cc
  Plan/Plan.cc
  Source/Source.cc
)
target_compile_options(testSourceP11 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testSystemeP11
  Systeme/testSysteme.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Aleatoire/Aleatoire.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  ParticuleNeige/ParticuleNeige.cc
  Plan/Plan.cc
  Source/Source.cc
  Systeme/Systeme.cc
)
target_compile_options(testSystemeP11 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(exerciceP9_v1_P11
  exerciceP9_v1.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Aleatoire/Aleatoire.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  ParticuleNeige/ParticuleNeige.cc
  Plan/Plan.cc
  Source/Source.cc
  Systeme/Systeme.cc
)
target_compile_options(exerciceP9_v1_P11 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(exerciceP9_v2_P11
  exerciceP9_v2.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Aleatoire/Aleatoire.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  ParticuleNeige/ParticuleNeige.cc
  Plan/Plan.cc
  Source/Source.cc
  Systeme/Systeme.cc
)
target_compile_options(exerciceP9_v2_P11 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(chute_libreP11
  chute_libre.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Aleatoire/Aleatoire.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  ParticuleNeige/ParticuleNeige.cc
  Plan/Plan.cc
  Source/Source.cc
  Systeme/Systeme.cc
)
target_compile_options(chute_libreP11 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testP5_P11
  testP5.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Aleatoire/Aleatoire.cc
  Obstacle/Obstacle.cc
  Particule/Particule.cc
  ParticuleNeige/ParticuleNeige.cc
  Plan/Plan.cc
  Source/Source.cc
  Systeme/Systeme.cc
)
target_compile_options(testP5_P11 PRIVATE ${PROJECT_WARNING_FLAGS})
