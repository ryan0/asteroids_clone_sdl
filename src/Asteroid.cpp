//
// Created by ryan on 5/8/2023.
//
#include <iostream>
#include "Asteroid.h"

Asteroid::Asteroid() = default;

Asteroid::Asteroid(Texture *texture, Vector2f position, Vector2f velocity)
    : GameObject(position), sprite(texture), velocity(velocity),
    collider(std::make_shared<BoxCollider>(4, 4, 25, 25))
{
    collider->setOutSignal("Asteroid");
}

void Asteroid::update() {
    position = position + velocity;
    collider->setOffset(position);
    rotation += rotationSpeed;

    checkCollisionSignals();
}

void Asteroid::render(SDL_Renderer *renderer) {
    sprite.setDestRect({position, 32, 32});
    sprite.setRotation(rotation);
    sprite.render(renderer);
    collider->render(renderer);
}

std::shared_ptr<BoxCollider> Asteroid::getBoxCollider() {
    return collider;
}

void Asteroid::checkCollisionSignals() {
    for(const std::string& s : collider->getReceivedSignals()) {
        if(s == "Asteroid") {
            std::cout<<"Asteroid hit An Asteroid!!!"<<std::endl;
        }
        if(s == "Laser") {
            std::cout<<"Laser hit An Asteroid!!!"<<std::endl;
            isHitByLaser = true;
        }
    }
}

bool Asteroid::shouldDelete() const {
    return isHitByLaser;
}