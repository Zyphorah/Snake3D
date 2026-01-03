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
    src/CubeRenderer.cpp
    src/GameMenu.cpp
    src/GameState.cpp
    src/ScoreDisplay.cpp
    src/control/CommandRegistry.cpp
    src/control/InputHandler.cpp
    src/matrix/RotationMatrixX.cpp
    src/matrix/RotationMatrixY.cpp
    src/logic/snake/Snake.cpp
    src/logic/snake/SnakeMovement.cpp
    src/logic/snake/SnakeCollision.cpp
    src/logic/snake/SnakeController.cpp
)

target_link_libraries(Snake3D
    sfml-graphics
    sfml-window
    sfml-system
)
