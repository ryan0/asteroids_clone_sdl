//
// Created by ryan on 5/7/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_SPRITE_H
#define ASTEROIDS_CLONE_SDL_SPRITE_H

#include "Texture.h"
#include "Rect.h"

class Sprite {
public:
    Sprite();
    Sprite(Texture* textureRef);

    void render(SDL_Renderer* renderer);

    void setSrcRect(const IntRect& rect);
    void setDestRect(const FloatRect &rect);
    void setRotation(const float &rot);

private:
    Texture* textureRef = nullptr;
    IntRect srcRect{};
    FloatRect destRect{};
    float rotation{0};
    Uint8 rMod{};
    Uint8 gMod{};
    Uint8 bMod{};
    Uint8 aMod{};
};


#endif //ASTEROIDS_CLONE_SDL_SPRITE_H
