//
// Created by ryan on 5/7/2023.
//

#include "Sprite.h"

Sprite::Sprite() = default;

Sprite::Sprite(Texture *textureRef) : textureRef(textureRef), srcRect({0, 0, textureRef->getWidth(), textureRef->getHeight()}) {}

void Sprite::render(SDL_Renderer *renderer) {
    SDL_Rect src = srcRect.getSDL_Rect();
    SDL_FRect dest = destRect.getSDL_FRect();
    SDL_RenderCopyExF(renderer, textureRef->getTextureRef(), &src, &dest, (double) rotation, nullptr, SDL_FLIP_NONE);
}

void Sprite::setSrcRect(const IntRect &rect) {
    srcRect = rect;
}

void Sprite::setDestRect(const FloatRect &rect) {
    destRect = rect;
}

void Sprite::setRotation(const float &rot) {
    rotation = rot;
}