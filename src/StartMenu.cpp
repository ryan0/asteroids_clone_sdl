//
// Created by ryan on 5/6/2023.
//

#include <SDL.h>
#include <iostream>
#include "StartMenu.h"

StartMenu::StartMenu(SDL_Renderer* renderer, const std::function<void(void)>& goToGame) {
    backgroundTexture.loadFromFile(renderer, "../assets/asteroids-bg.png");

    startButton.setOnClick([goToGame]() {
        std::cout<<"Go To Game!"<<std::endl;
        goToGame();
    });
}

void StartMenu::update() {}

void StartMenu::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, backgroundTexture.getTextureRef(), NULL, NULL);

    startButton.render(renderer);

    SDL_RenderPresent(renderer);
}

void StartMenu::handleEvent(const SDL_Event& event) {
    startButton.handleEvent(event);
}