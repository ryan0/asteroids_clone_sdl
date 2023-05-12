//
// Created by ryan on 5/6/2023.
//

#include <iostream>
#include "Player.h"
#include "AsteroidsGame.h"

Player::Player() = default;

Player::Player(Texture* shipTexRef, AsteroidsGame* gameRef)
    : shipSprite(shipTexRef), gameRef(gameRef),
      collider(std::make_shared<BoxCollider>(4, 4, 25, 25))
{
    collider->setOutSignal("Player");
}

void Player::update() {
    checkKeyStates();
    position = position + velocity;
    collider->setOffset(position);

    if(fireTimer > 0) {
        fireTimer -= 1;
    }

    checkCollisionSignals();
}

void Player::handleEvent(const SDL_Event& event) {
    static bool spaceUp = true;

    if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE) {
        spaceUp = true;
    }
    else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE && fireTimer == 0 && spaceUp) {
        fireTimer = fireCoolDown;
        spaceUp = false;

        Vector2f laserVel = rotatedBy({5.0f, 0.0f}, rotation) + velocity;
        Vector2f laserPos = {position.x + 14, position.y + 14};
        gameRef->spawnLaser(laserPos, laserVel);
    }
}

void Player::checkCollisionSignals() {
    for(const std::string& s : collider->getReceivedSignals()) {
        if(s == "Asteroid") {
            std::cout<<"Player hit An Asteroid!!!"<<std::endl;
        }
    }
}

void Player::checkKeyStates() {
    Vector2f direction = rotatedBy({.05f, 0.0f}, rotation);
    const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);

    if(currentKeyStates[SDL_SCANCODE_W]) {
        velocity = velocity + direction;
    }
    if(currentKeyStates[SDL_SCANCODE_S]) {
        velocity = velocity - direction;
    }
    if(currentKeyStates[SDL_SCANCODE_D]) {
        rotation += 2;
    }
    if(currentKeyStates[SDL_SCANCODE_A]) {
        rotation -= 2;
    }
}

void Player::render(SDL_Renderer* renderer) {
    shipSprite.setDestRect({position.x, position.y, 32, 32});
    shipSprite.setRotation(rotation);
    shipSprite.render(renderer);

    collider->render(renderer);
}

std::shared_ptr<BoxCollider> Player::getCollider() {
    return collider;
}