//
// Created by ryan on 5/6/2023.
//

#include <iostream>
#include <memory>
#include "AsteroidsGame.h"

AsteroidsGame::AsteroidsGame(SDL_Renderer *renderer) {
    shipTex.loadFromFile(renderer, "../assets/Ship.png");
    asteroidTex.loadFromFile(renderer, "../assets/asteroid.png");

    auto player = std::make_unique<Player>(&shipTex, this);
    collisionSystem.addToPhysicsSystem(player->getCollider());
    gameObjects.push_back(std::move(player));

    std::unique_ptr<Asteroid> asteroid;
    asteroid = std::make_unique<Asteroid>(&asteroidTex, Vector2f(200.0f, 200.0f), Vector2f(0.05f, 0.1f));
    collisionSystem.addToPhysicsSystem(asteroid->getBoxCollider());
    gameObjects.push_back(std::move(asteroid));

    asteroid = std::make_unique<Asteroid>(&asteroidTex, Vector2f(500.0f, 100.0f), Vector2f(0.1f, 0.05f));
    collisionSystem.addToPhysicsSystem(asteroid->getBoxCollider());
    gameObjects.push_back(std::move(asteroid));

    asteroid = std::make_unique<Asteroid>(&asteroidTex, Vector2f(400.0f, 300.0f), Vector2f(0.05f, -0.1f));
    collisionSystem.addToPhysicsSystem(asteroid->getBoxCollider());
    gameObjects.push_back(std::move(asteroid));
}

void AsteroidsGame::update() {
    for(auto i = gameObjects.begin(); i != gameObjects.end();) {
        auto ptr = i->get();
        if(ptr->shouldDelete()) {
            i = gameObjects.erase(i);
        } else {
            ptr->update();
            ++i;
        }
    }

    if(newObj != nullptr) {
        gameObjects.push_back(std::move(newObj));
        newObj = nullptr;
    }

    moveObjectsWithinBounds();
    collisionSystem.update();
}

void AsteroidsGame::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    for(auto& i : gameObjects) {
        i->render(renderer);
    }

    SDL_RenderPresent(renderer);
}

void AsteroidsGame::handleEvent(const SDL_Event& event) {
    for(auto& i : gameObjects) {
        i->handleEvent(event);
    }
}

void AsteroidsGame::spawnLaser(Vector2f position, Vector2f velocity) {
    auto laser = std::make_unique<Laser>(position, velocity);
    collisionSystem.addToPhysicsSystem(laser->getBoxCollider());
    newObj = std::move(laser);
}

void AsteroidsGame::moveObjectsWithinBounds() {
    for(auto& i : gameObjects) {
        auto& pos = i->position;

        if(pos.x < 0) {
            pos.x = 640;
        } else if (pos.x > 640) {
            pos.x = 0;
        }

        if(pos.y < 0) {
            pos.y = 360;
        } else if (pos.y > 360) {
            pos.y = 0;
        }
    }
}