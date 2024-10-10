cmake_minimum_required(VERSION 3.25)
project(asteroids_clone_sdl)

set(CMAKE_CXX_STANDARD 17)

add_executable(asteroids_clone_sdl src/main.cpp src/Window.cpp src/Window.h src/StartMenu.cpp src/StartMenu.h src/Texture.cpp src/Texture.h src/Vector2.inl src/Vector2.h src/Button.cpp src/Button.h src/Rect.h src/Rect.inl src/AsteroidsGame.cpp src/AsteroidsGame.h src/Player.cpp src/Player.h src/Sprite.cpp src/Sprite.h src/Vector2.cpp src/Asteroid.cpp src/Asteroid.h src/Scene.h src/Laser.cpp src/Laser.h src/BoxCollider.cpp src/BoxCollider.h src/CollisionSystem.cpp src/CollisionSystem.h src/GameObject.cpp src/GameObject.h src/SoundEffect.cpp src/SoundEffect.h src/Animation.cpp src/Animation.h)

set(SDL2_INCLUDE_DIR "" CACHE PATH "Path to SDL2 include directory")
set(SDL2_LIB_DIR  "" CACHE PATH "Path to SDL2 lib directory")

set(SDL2_IMAGE_INCLUDE_DIR "" CACHE PATH "Path to SDL2_image include directory")
set(SDL2_IMAGE_LIB_DIR  "" CACHE PATH "Path to SDL2_image lib directory")

set(SDL2_MIXER_INCLUDE_DIR "" CACHE PATH "Path to SDL2_mixer include directory")
set(SDL2_MIXER_LIB_DIR  "" CACHE PATH "Path to SDL2_mixer lib directory")

target_include_directories(asteroids_clone_sdl PUBLIC
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
    ${SDL2_MIXER_INCLUDE_DIR}
)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)

target_link_libraries(asteroids_clone_sdl PUBLIC
        SDL2::SDL2main
        SDL2::SDL2
        SDL2_image::SDL2_image-static
        SDL2_mixer::SDL2_mixer-static
)
