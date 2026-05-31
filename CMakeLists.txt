# CMakeLists.txt général

cmake_minimum_required(VERSION 3.21)

project(projet_poo)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_WARNING_FLAGS
    -pedantic
    -Wall
    -Wextra
    -Wold-style-cast
    -Woverloaded-virtual
    -Wfloat-equal
    -Wshadow
    -Wwrite-strings
    -Wpointer-arith
    -Wcast-qual
    -Wcast-align
    -Wconversion
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # pour l'IDE (IntelliSense)

# --- Raylib (doit être installé manuellement, ex: sudo port install raylib) ---
list(APPEND CMAKE_PREFIX_PATH /opt/local)
find_package(raylib REQUIRED)

add_subdirectory(version-1)
add_subdirectory(commun)
add_subdirectory(exerciceP10)
add_subdirectory(ex_P12-P13_et_extensions)
add_subdirectory(exerciceP11-revisiteP9)
add_subdirectory(exerciceP11-v2)
