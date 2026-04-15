add_library(TextViewer text_viewer.h text_viewer.cc)
target_compile_options(TextViewer PRIVATE ${PROJECT_WARNING_FLAGS})
target_include_directories(TextViewer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../general)
target_link_libraries(TextViewer Dessin)

add_executable(exemple2_text main_text.cc)
target_compile_options(exemple2_text PRIVATE ${PROJECT_WARNING_FLAGS})
target_link_libraries(exemple2_text TextViewer)