//
// Created by ryan on 5/6/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_START_MENU_H
#define ASTEROIDS_CLONE_SDL_START_MENU_H

#include <functional>
#include "Texture.h"
#include "Scene.h"
#include "Button.h"

class StartMenu : public Scene {
public:
    explicit StartMenu(SDL_Renderer* renderer, const std::function<void(void)>& goToGame);
    void update() override;
    void render(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& event) override;

private:
    Texture backgroundTexture = Texture();
    Button startButton = Button(IntRect(100, 200, 100, 50));
};


#endif //ASTEROIDS_CLONE_SDL_START_MENU_H
