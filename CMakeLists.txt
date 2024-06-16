cmake_minimum_required(VERSION 3.27)
project(Hanami_game)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS FALSE)
include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML
        GIT_TAG        2.6.1
)
FetchContent_MakeAvailable(SFML)
add_executable(Hanami_game main.cpp
        Game.cpp
        Game.h
        Game.h
        Player.cpp
        Player.h
        GameState.cpp
        GameState.h
        GameState.h
        Entity.cpp
        Entity.h
        Entity.h
        State.h
        State.cpp
        MainMenuState.cpp
        MainMenuState.h
        Button.cpp
        Button.h
        Map.cpp
        Map.h
        Map.h
        Movement.cpp
        Movement.h
        Animation.cpp
        Animation.h
        Animation.cpp
        Animation.cpp
        EditorState.cpp
        EditorState.h
        ComponentBox.cpp
        ComponentBox.h
        TileMap.cpp
        TileMap.h
        Tile.cpp
        Tile.h
        TileMap.cpp
        Monster.cpp
        Monster.h
        Monster.h
        AnimationManager.cpp
        AnimationManager.h
)
target_link_libraries(Hanami_game sfml-graphics)
