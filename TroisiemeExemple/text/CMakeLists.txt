add_library(TextViewer3 text_viewer.h text_viewer.cc)
target_compile_options(TextViewer3 PRIVATE ${PROJECT_WARNING_FLAGS})
target_include_directories(TextViewer3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../general)
target_link_libraries(TextViewer3 Dessin3)

add_executable(exemple3_text main_text.cc)
target_compile_options(exemple3_text PRIVATE ${PROJECT_WARNING_FLAGS})
target_link_libraries(exemple3_text TextViewer3)