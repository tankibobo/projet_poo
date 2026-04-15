add_library(RayRender raylib_render.h raylib_render.cc)
target_compile_options(RayRender PRIVATE ${PROJECT_WARNING_FLAGS})
target_include_directories(RayRender PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../general)
target_link_libraries(RayRender raylib Dessin)

add_executable(exemple2_raylib main_raylib.cc)
target_compile_options(exemple2_raylib PRIVATE ${PROJECT_WARNING_FLAGS})
target_link_libraries(exemple2_raylib RayRender)
