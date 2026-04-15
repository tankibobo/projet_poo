add_executable(exemple1 main_ex1.cc)
target_compile_options(exemple1 PRIVATE ${PROJECT_WARNING_FLAGS})
target_link_libraries(exemple1 raylib)