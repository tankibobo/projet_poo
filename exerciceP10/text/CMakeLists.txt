add_executable(exerciceP10_text
    main_text.cc
)

target_include_directories(exerciceP10_text PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(exerciceP10_text PRIVATE SimulationP10)
target_compile_options(exerciceP10_text PRIVATE ${PROJECT_WARNING_FLAGS})
