//
// Created by ryan on 5/6/2023.
//

#include <iostream>
#include <memory>
#include "AsteroidsGame.h"

AsteroidsGame::AsteroidsGame(SDL_Renderer *renderer) {
    shipTex.loadFromFile(renderer, "../assets/Ship-SpriteSheet.png");
    asteroidTex.loadFromFile(renderer, "../assets/asteroid.png");

    laserSound.loadFromFile("../assets/audio/fire.wav");
    thrustSound.loadFromFile("../assets/audio/thrust.wav");
    largeBangSound.loadFromFile("../assets/audio/bangLarge.wav");

    auto player = std::make_unique<Player>(&shipTex, &laserSound, &thrustSound, this);
    collisionSystem.addToPhysicsSystem(player->getCollider());
    gameObjects.push_back(std::move(player));

    std::unique_ptr<Asteroid> asteroid;
    asteroid = std::make_unique<Asteroid>(this, &asteroidTex, &largeBangSound, Vector2f(200.0f, 200.0f), Vector2f(0.03f, 0.11f));
    collisionSystem.addToPhysicsSystem(asteroid->getBoxCollider());
    gameObjects.push_back(std::move(asteroid));

    asteroid = std::make_unique<Asteroid>(this, &asteroidTex, &largeBangSound, Vector2f(500.0f, 100.0f), Vector2f(0.13f, 0.03f));
    collisionSystem.addToPhysicsSystem(asteroid->getBoxCollider());
    gameObjects.push_back(std::move(asteroid));

    asteroid = std::make_unique<Asteroid>(this, &asteroidTex, &largeBangSound, Vector2f(400.0f, 300.0f), Vector2f(0.06f, -0.1f));
    collisionSystem.addToPhysicsSystem(asteroid->getBoxCollider());
    gameObjects.push_back(std::move(asteroid));

    asteroid = std::make_unique<Asteroid>(this, &asteroidTex, &largeBangSound, Vector2f(300.0f, 30.0f), Vector2f(-0.07f, -0.09f));
    collisionSystem.addToPhysicsSystem(asteroid->getBoxCollider());
    gameObjects.push_back(std::move(asteroid));

    asteroid = std::make_unique<Asteroid>(this, &asteroidTex, &largeBangSound, Vector2f(50.0f, 200.0f), Vector2f(-0.02f, 0.13f));
    collisionSystem.addToPhysicsSystem(asteroid->getBoxCollider());
    gameObjects.push_back(std::move(asteroid));

    asteroid = std::make_unique<Asteroid>(this, &asteroidTex, &largeBangSound, Vector2f(550.0f, 60.0f), Vector2f(-0.18f, -0.03f));
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

    while (!spawnedObjects.empty()) {
        gameObjects.push_back(std::move(spawnedObjects.back()));
        spawnedObjects.pop_back();
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
    spawnedObjects.push_back(std::move(laser));
}

void AsteroidsGame::spawnAsteroids(std::vector<std::unique_ptr<Asteroid>> asteroids) {
    for(auto& i : asteroids) {
        collisionSystem.addToPhysicsSystem(i->getBoxCollider());
        spawnedObjects.push_back(std::move(i));
    }
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