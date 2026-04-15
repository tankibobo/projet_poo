add_library(SimulationP10 STATIC
    Vecteur3D/Vecteur3D.cc
    Aleatoire/Aleatoire.cc
    Obstacle/Obstacle.cc
    Plan/Plan.cc
    Particule/Particule.cc
    Source/Source.cc
    Systeme/Systeme.cc
)

target_include_directories(SimulationP10 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(SimulationP10 PRIVATE ${PROJECT_WARNING_FLAGS})
