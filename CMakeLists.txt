cmake_minimum_required(VERSION 3.10.0)
project(afterthought VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 23)

set(RL_DIR src/thirdparty/raylib)
add_subdirectory(${RL_DIR})

set(RG_DIR src/thirdparty/raygui)

add_executable(${PROJECT_NAME} 
								src/rsrc/font_SpaceMono.c
								src/entities/george.c
								src/impl.c
								src/drawing.c
								src/pathfinding.c
								src/menu.c
								src/world.c
								src/tile.c
								src/settlement.c
								src/citizen.c
								src/ingame.c
								src/main.c
)

target_include_directories(${PROJECT_NAME} PUBLIC src)
target_include_directories(${PROJECT_NAME} PUBLIC ${RL_DIR}/src)
target_include_directories(${PROJECT_NAME} PUBLIC ${RG_DIR}/src)

target_link_libraries(${PROJECT_NAME} raylib)