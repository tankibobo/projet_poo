add_library(RayRender3 raylib_render.h raylib_render.cc)
target_compile_options(RayRender3 PRIVATE ${PROJECT_WARNING_FLAGS})
target_include_directories(RayRender3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../general)
target_link_libraries(RayRender3 raylib Dessin3)

add_executable(exemple3_raylib main_raylib.cc)
target_compile_options(exemple3_raylib PRIVATE ${PROJECT_WARNING_FLAGS})
target_link_libraries(exemple3_raylib RayRender3)
