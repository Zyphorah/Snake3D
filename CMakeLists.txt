cmake_minimum_required(VERSION 3.10)
project(Snake3D)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SFML
set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML")

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${SFML_DIR}
    ${SFML_DIR}/System
    ${SFML_DIR}/Window
    ${SFML_DIR}/Graphics
    ${SFML_DIR}/Audio
    ${SFML_DIR}/Network
)

link_directories(
    ${SFML_DIR}/lib
)

add_executable(Snake3D
    src/main.cpp
    src/Matrice3D.cpp
    src/keycontrole.cpp
    src/control/CommandRegistry.cpp
    src/control/InputHandler.cpp
    src/control/GameControls.cpp
)

target_link_libraries(Snake3D
    sfml-graphics
    sfml-window
    sfml-system
)
