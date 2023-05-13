//
// Created by ryan on 5/8/2023.
//
#include <iostream>
#include "Asteroid.h"
#include "AsteroidsGame.h"

FloatRect Asteroid::getCollisionRectAtSize(Asteroid::SIZE size) {
    switch (size) {
        case SMALL:  return { 4, 4, 12, 12};
        case MEDIUM: return { 8, 8, 24, 24};
        default:     return {15, 15, 35, 35};
    }
}

float Asteroid::getDrawPixels(Asteroid::SIZE size) {
    switch (size) {
        case SMALL:  return 20;
        case MEDIUM: return 40;
        default:     return 64;
    }
}

Asteroid::Asteroid() = default;

Asteroid::Asteroid(AsteroidsGame* game, Texture *texture, SoundEffect* largeBang, Vector2f position, Vector2f velocity)
    : GameObject(position), sprite(texture), largeBangSoundRef(largeBang),
    velocity(velocity), textureRef(texture), gameRef(game),
    collider(std::make_shared<BoxCollider>(getCollisionRectAtSize(LARGE)))
{
    collider->setOutSignal("Asteroid");
}

Asteroid::Asteroid(AsteroidsGame* game, Asteroid::SIZE size, Texture *texture, SoundEffect *largeBang, Vector2f position, Vector2f velocity)
    : GameObject(position), sprite(texture), largeBangSoundRef(largeBang),
    velocity(velocity), size(size), textureRef(texture), gameRef(game),
    collider(std::make_shared<BoxCollider>(getCollisionRectAtSize(size)))
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
    float imgSize = getDrawPixels(size);
    sprite.setDestRect({position, imgSize, imgSize});
    sprite.setRotation(rotation);
    sprite.render(renderer);
//    collider->render(renderer);
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
            largeBangSoundRef->play();
            breakUp();
        }
    }
}

bool Asteroid::shouldDelete() const {
    return isHitByLaser;
}

void Asteroid::breakUp() {
    std::vector<std::unique_ptr<Asteroid>> newAsteroids;
    std::unique_ptr<Asteroid> asteroid = nullptr;

    if (size == LARGE) {
        Vector2f positionOffset{10, 10};
        Vector2f velocityOffset{ 0.2f, 0.2f};

        asteroid = std::make_unique<Asteroid>(
                gameRef,
                MEDIUM,
                textureRef,
                largeBangSoundRef,
                position + positionOffset,
                velocity + velocityOffset);
        newAsteroids.push_back(std::move(asteroid));

        asteroid = std::make_unique<Asteroid>(
                gameRef,
                MEDIUM,
                textureRef,
                largeBangSoundRef,
                position - positionOffset,
                velocity - velocityOffset);
        newAsteroids.push_back(std::move(asteroid));
    } else if (size == MEDIUM) {
        Vector2f positionOffset{5, 5};
        Vector2f velocityOffset{ 0.1f, 0.1f};

        asteroid = std::make_unique<Asteroid>(
                gameRef,
                SMALL,
                textureRef,
                largeBangSoundRef,
                position + positionOffset,
                velocity + velocityOffset);
        newAsteroids.push_back(std::move(asteroid));

        asteroid = std::make_unique<Asteroid>(
                gameRef,
                SMALL,
                textureRef,
                largeBangSoundRef,
                position - positionOffset,
                velocity - velocityOffset);
        newAsteroids.push_back(std::move(asteroid));
    }

    gameRef->spawnAsteroids(std::move(newAsteroids));
}
