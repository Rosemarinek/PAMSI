cmake_minimum_required(VERSION 3.16)
# set the projectX name to the name of your project
project(game)

set(CMAKE_CXX_STANDARD 17)
# set(SOURCE_FILES main.cpp)

include_directories(include)
add_executable(game src/main.cpp include/Game.hpp src/Game.cpp src/GameDesign.cpp
        include/GameDesign.hpp src/Menu.cpp include/Menu.hpp src/MainBoard.cpp include/MainBoard.hpp src/Player.cpp include/Player.hpp src/MinMax.cpp include/MinMax.hpp)
#add_executable(Game ${SOURCE_FILES})


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif ()
