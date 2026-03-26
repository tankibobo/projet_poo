add_executable(testVecteur3D
  testVecteur3D.cc
  Vecteur3D.cc
)
target_compile_options(testVecteur3D PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testParticule
  testParticule.cc
  Particule.cc
  Vecteur3D.cc
  Plan.cc
)
target_compile_options(testParticule PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testPlan
  testPlan.cc
  Plan.cc
  Vecteur3D.cc
)
target_compile_options(testPlan PRIVATE ${PROJECT_WARNING_FLAGS})


add_executable(testSource
  testSource.cc
  Source.cc
  Particule.cc
  Plan.cc
  Vecteur3D.cc
)
target_compile_options(testSource PRIVATE ${PROJECT_WARNING_FLAGS})
