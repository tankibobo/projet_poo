add_library(RayRender5 raylib_render.h raylib_render.cc)
target_compile_options(RayRender5 PRIVATE ${PROJECT_WARNING_FLAGS})
target_include_directories(RayRender5 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../general)
target_link_libraries(RayRender5 raylib Dessin5)

add_executable(exemple5_raylib main_raylib.cc)
target_compile_options(exemple5_raylib PRIVATE ${PROJECT_WARNING_FLAGS})
target_link_libraries(exemple5_raylib RayRender5)
