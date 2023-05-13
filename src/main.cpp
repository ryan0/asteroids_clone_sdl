#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Window.h"
#include "StartMenu.h"
#include "AsteroidsGame.h"

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    SDL_Init(SDL_INIT_AUDIO);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048);

    Window window("Asteroids", 1920, 1080);
    window.open();
    window.createRenderer(640, 360, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    { //Block to deconstruct scenes before close window
        Scene* currentScene = nullptr;
        AsteroidsGame game(window.getRenderer());
        StartMenu menu(window.getRenderer(), [&currentScene, &game](){
            //TODO implement scene manager class if more scenes
            currentScene = &game;
        });
        currentScene = &menu;

        SDL_Event event;
        bool running = true;
        while (running) {
            while (SDL_PollEvent(&event) != 0) { //process events
                if (event.type == SDL_QUIT) {
                    running = false;
                }
                currentScene->handleEvent(event);
            }
            currentScene->update();
            currentScene->render(window.getRenderer());
        }
    }

    window.close();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}
