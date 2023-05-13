//
// Created by ryan on 5/13/2023.
//

#include "Animation.h"

Animation::Animation(const Sprite& spriteRef) : spriteRef(spriteRef) {}

void Animation::update() {
    if(timer < frameTime) {
        timer++;
    } else {
        timer -= frameTime;
        currentFrame = currentFrame < frames.size() - 1 ? currentFrame + 1 : 0;
    }
}

void Animation::addFrame(const IntRect &frame) {
    frames.push_back(frame);
}

void Animation::setDestRect(const FloatRect &rect) {
    spriteRef.setDestRect(rect);
}

void Animation::setRotation(float rot) {
    spriteRef.setRotation(rot);
}

void Animation::render(SDL_Renderer *renderer) {
    spriteRef.setSrcRect(frames[currentFrame]);
    spriteRef.render(renderer);
}