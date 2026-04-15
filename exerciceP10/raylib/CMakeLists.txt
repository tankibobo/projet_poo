add_library(RayRenderP10 STATIC
    raylib_render.cc
)

target_include_directories(RayRenderP10 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(RayRenderP10 PUBLIC SimulationP10 raylib)
target_compile_options(RayRenderP10 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(exerciceP10_raylib
    main_raylib.cc
)

target_link_libraries(exerciceP10_raylib PRIVATE RayRenderP10)
target_compile_options(exerciceP10_raylib PRIVATE ${PROJECT_WARNING_FLAGS})
