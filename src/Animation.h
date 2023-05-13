//
// Created by ryan on 5/13/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_ANIMATION_H
#define ASTEROIDS_CLONE_SDL_ANIMATION_H

#include <vector>
#include <SDL.h>
#include "Sprite.h"
#include "Rect.h"

class Animation {
public:
    explicit Animation(const Sprite& spriteRef);

    void update();
    void render(SDL_Renderer* renderer);
    void setDestRect(const FloatRect& rect);
    void setRotation(float rot);

    void addFrame(const IntRect& frame);

private:
    std::vector<IntRect> frames;
    Sprite spriteRef;

    int currentFrame = 0;
    static const int frameTime = 8;
    int timer = 0;

};


#endif //ASTEROIDS_CLONE_SDL_ANIMATION_H
