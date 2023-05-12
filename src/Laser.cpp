//
// Created by ryan on 5/9/2023.
//

#include <iostream>
#include "Laser.h"

Laser::Laser(Vector2f position, Vector2f velocity)
    : GameObject(position), velocity(velocity),
    collider(std::make_shared<BoxCollider>(0, 0, 3, 3))
{
    collider->setOutSignal("Laser");
}

void Laser::update() {
    position = position + velocity;
    collider->setOffset(position);

    if(ticksLeft > 0) {
        ticksLeft -= 1;
    }
}

void Laser::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_FRect drawRect{position.x, position.y, 3, 3};
    SDL_RenderFillRectF(renderer, &drawRect);

    collider->render(renderer);
}

bool Laser::shouldDelete() const {
    return ticksLeft == 0;
}

std::shared_ptr<BoxCollider> Laser::getBoxCollider() {
    return collider;
}
