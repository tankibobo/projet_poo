
add_executable(exerciceTEST
  exerciceTEST.cc
  Source.cc
  Vecteur3D.cc
  Aleatoire.cc
  Plan.cc
  Obstacle.cc
  Particule.cc
  Systeme.cc
)
target_compile_options(exerciceTEST PRIVATE ${PROJECT_WARNING_FLAGS})
