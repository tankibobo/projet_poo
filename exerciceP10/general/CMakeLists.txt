add_library(SimulationP10 STATIC
    ../../commun/Vecteur3D/Vecteur3D.cc
    ../../commun/Aleatoire/Aleatoire.cc
    ../../commun/Obstacle/Obstacle.cc
    ../../commun/Plan/Plan.cc
    Particule/Particule.cc
    Source/Source.cc
    Systeme/Systeme.cc
)

target_include_directories(SimulationP10 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(SimulationP10 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testParticuleP10
  Particule/testParticule.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Plan/Plan.cc
  ../../commun/Obstacle/Obstacle.cc
  Particule/Particule.cc
)
target_compile_options(testParticuleP10 PRIVATE ${PROJECT_WARNING_FLAGS})


add_executable(testSourceP10
  Source/testSource.cc
  ../../commun/Aleatoire/Aleatoire.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Plan/Plan.cc
  ../../commun/Obstacle/Obstacle.cc
  Particule/Particule.cc
  Source/Source.cc
)
target_compile_options(testSourceP10 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testSystemeP10
  Systeme/testSysteme.cc
  ../../commun/Aleatoire/Aleatoire.cc
  ../../commun/Vecteur3D/Vecteur3D.cc
  ../../commun/Plan/Plan.cc
  ../../commun/Obstacle/Obstacle.cc
  Particule/Particule.cc
  Source/Source.cc
  Systeme/Systeme.cc
)
target_compile_options(testSystemeP10 PRIVATE ${PROJECT_WARNING_FLAGS})
