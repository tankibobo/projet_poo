add_executable(testVecteur3D
  testVecteur3D.cc
  Vecteur3D.cc
)
target_compile_options(testVecteur3D PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(testParticule
  testParticule.cc
  Particule.cc
  Vecteur3D.cc
)
target_compile_options(testParticule PRIVATE ${PROJECT_WARNING_FLAGS})