set(EXTENSIONS_SOURCES
    ../../Systeme/Systeme.cc
    ../../Calcul/CalculNaif.cc
    ../../exerciceP12/Grille/Grille.cc
    ../../exerciceP12/CalculGrille/CalculGrille.cc
    ../../Obstacle/Obstacle.cc
    ../../Particule/Particule.cc
    ../../ParticuleNeige/ParticuleNeige.cc
    ../../ParticuleRoche/ParticuleRoche.cc
    ../../Plan/Plan.cc
    ../../Source/Source.cc
    ../../Brique/Brique.cc
    ../../Cylindre/Cylindre.cc
    ../../../commun/Vecteur3D/Vecteur3D.cc
    ../../../commun/Aleatoire/Aleatoire.cc
)

add_library(RayRenderExtensions STATIC
    raylib_render.cc
    ${EXTENSIONS_SOURCES}
)

target_include_directories(RayRenderExtensions PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/ex_P12-P13_et_extensions
    ${CMAKE_SOURCE_DIR}/ex_P12-P13_et_extensions/exerciceP12/general
    ${CMAKE_SOURCE_DIR}/commun
)
target_link_libraries(RayRenderExtensions PUBLIC raylib)
target_compile_options(RayRenderExtensions PRIVATE ${PROJECT_WARNING_FLAGS})


add_executable(enclos_sources_differentes
    enclos_sources_differentes.cc
)
target_link_libraries(enclos_sources_differentes PRIVATE RayRenderExtensions)
target_compile_options(enclos_sources_differentes PRIVATE ${PROJECT_WARNING_FLAGS})


add_executable(extension_energie
    extension_energie.cc
)
target_link_libraries(extension_energie PRIVATE RayRenderExtensions)
target_compile_options(extension_energie PRIVATE ${PROJECT_WARNING_FLAGS})


add_executable(extension_galton
    extension_galton.cc
)
target_link_libraries(extension_galton PRIVATE RayRenderExtensions)
target_compile_options(extension_galton PRIVATE ${PROJECT_WARNING_FLAGS})
