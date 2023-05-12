//
// Created by ryan on 5/6/2023.
//

#include <utility>
#include "Button.h"

Button::Button() = default;

Button::Button(IntRect btnRect) : btnRect(btnRect) {}

void Button::handleEvent(const SDL_Event& e) {
    if (e.type == SDL_MOUSEMOTION) {
        btnRect.contains({e.motion.x, e.motion.y}) ? hover = true : hover = false;
    } else if (e.type == SDL_MOUSEBUTTONDOWN && hover ) {
        onClickCallBack();
    }
}

void Button::render(SDL_Renderer *renderer) {
    SDL_Rect drawRect = btnRect.getSDL_Rect();

    if (btnImage.getTextureRef() != nullptr) {

    } else {
        if (!hover) {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
        }
        SDL_RenderFillRect(renderer, &drawRect);
    }
}

void Button::setOnClick(std::function<void()> clickFunction) {
    this->onClickCallBack = std::move(clickFunction);
}