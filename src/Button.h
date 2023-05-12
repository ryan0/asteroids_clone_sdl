//
// Created by ryan on 5/6/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_BUTTON_H
#define ASTEROIDS_CLONE_SDL_BUTTON_H

#include <functional>
#include "Texture.h"
#include "Vector2.h"
#include "Rect.h"

class Button {
public:
    Button();
    explicit Button(IntRect btnRect);

    void handleEvent(const SDL_Event& e);
    void render(SDL_Renderer* renderer);

    void setOnClick(std::function<void(void)> onClick);

private:
    std::function<void(void)> onClickCallBack{ [](){} };
    IntRect btnRect{};
    Texture btnImage{};
    bool hover{false};
};

#endif //ASTEROIDS_CLONE_SDL_BUTTON_H
