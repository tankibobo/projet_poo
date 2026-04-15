add_library(TextViewer5 text_viewer.h text_viewer.cc)
target_compile_options(TextViewer5 PRIVATE ${PROJECT_WARNING_FLAGS})
target_include_directories(TextViewer5 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../general)
target_link_libraries(TextViewer5 Dessin5)

add_executable(exemple5_text main_text.cc)
target_compile_options(exemple5_text PRIVATE ${PROJECT_WARNING_FLAGS})
target_link_libraries(exemple5_text TextViewer5)