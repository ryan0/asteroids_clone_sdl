//
// Created by ryan on 5/6/2023.
//

#include <iostream>
#include "Player.h"
#include "AsteroidsGame.h"


Player::Player(Texture* shipTexRef, SoundEffect* laserSoundRef, SoundEffect* thrustSound, AsteroidsGame* gameRef)
    : shipSprite(shipTexRef), shipThrustAni(shipSprite), gameRef(gameRef),
      laserSoundRef(laserSoundRef), thrustSoundRef(thrustSound),
      collider(std::make_shared<BoxCollider>(4, 4, 25, 25))
{
    shipSprite.setSrcRect({0, 0, 32, 32});

    for(int i = 0; i < 8; i++) {
        shipThrustAni.addFrame({i* 32, 32, 32, 32});
    }

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
        laserSoundRef->play();
    }
}

void Player::checkCollisionSignals() {
    for(const std::string& s : collider->getReceivedSignals()) {
        if(s == "Asteroid") {
            hitAsteroid = true;
            thrustOn = false;
            thrustSoundRef->stop(200);
        }
    }
}

bool Player::shouldDelete() const {
    return hitAsteroid;
}

void Player::checkKeyStates() {
    Vector2f direction = rotatedBy({.02f, 0.0f}, rotation);
    const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);

    thrustOn = false;

    if(currentKeyStates[SDL_SCANCODE_W]) {
        velocity = velocity + direction;
        thrustOn = true;
        thrustSoundRef->loop();
    } else{
        thrustSoundRef->stop(500);
    }

    if(currentKeyStates[SDL_SCANCODE_D]) {
        rotation += 2;
    }
    if(currentKeyStates[SDL_SCANCODE_A]) {
        rotation -= 2;
    }
}

void Player::render(SDL_Renderer* renderer) {
    if(thrustOn) {
        shipThrustAni.update();
        shipThrustAni.setDestRect({position.x, position.y, 32, 32});
        shipThrustAni.setRotation(rotation);
        shipThrustAni.render(renderer);
    } else {
        shipSprite.setDestRect({position.x, position.y, 32, 32});
        shipSprite.setRotation(rotation);
        shipSprite.render(renderer);
    }

//    collider->render(renderer);
}

std::shared_ptr<BoxCollider> Player::getCollider() {
    return collider;
}