cmake_minimum_required(VERSION 3.10.0)
project(afterthought VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 20)

set(RL_DIR src/thirdparty/raylib)
add_subdirectory(${RL_DIR})

add_executable(${PROJECT_NAME} 
								src/main.c
)

target_include_directories(${PROJECT_NAME} PUBLIC src)
target_include_directories(${PROJECT_NAME} PUBLIC ${RL_DIR}/src)

target_link_libraries(${PROJECT_NAME} raylib)