include_directories(.)

add_executable(testVecteur3DCommun
  Vecteur3D/testVecteur3D.cc
  Vecteur3D/Vecteur3D.cc
)
target_compile_options(testVecteur3DCommun PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testPlanCommun
  Plan/testPlan.cc
  Plan/Plan.cc
  Vecteur3D/Vecteur3D.cc
  Obstacle/Obstacle.cc
)
target_compile_options(testPlanCommun PRIVATE ${PROJECT_WARNING_FLAGS})