set(P11V2_SOURCES
    ../general/Obstacle/Obstacle.cc
    ../general/Particule/Particule.cc
    ../general/ParticuleNeige/ParticuleNeige.cc
    ../general/ParticuleRoche/ParticuleRoche.cc
    ../general/Plan/Plan.cc
    ../general/Source/Source.cc
    ../general/Systeme/Systeme.cc
    ../general/Boite/Boite.cc
    ../../commun/Vecteur3D/Vecteur3D.cc
    ../../commun/Aleatoire/Aleatoire.cc
)

add_library(RayRenderP11v2 STATIC
    raylib_render.cc
    ${P11V2_SOURCES}
)

target_include_directories(RayRenderP11v2 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/exerciceP11-v2/general
    ${CMAKE_SOURCE_DIR}/commun
)
target_link_libraries(RayRenderP11v2 PUBLIC raylib)
target_compile_options(RayRenderP11v2 PRIVATE ${PROJECT_WARNING_FLAGS})

add_executable(exerciceP11v2_raylib
    main_raylib.cc
)
target_link_libraries(exerciceP11v2_raylib PRIVATE RayRenderP11v2)
target_compile_options(exerciceP11v2_raylib PRIVATE ${PROJECT_WARNING_FLAGS})
