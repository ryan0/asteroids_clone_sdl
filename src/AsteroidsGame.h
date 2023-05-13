//
// Created by ryan on 5/6/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_ASTEROIDS_GAME_H
#define ASTEROIDS_CLONE_SDL_ASTEROIDS_GAME_H

#include <SDL.h>
#include <vector>
#include "Scene.h"
#include "GameObject.h"
#include "CollisionSystem.h"
#include "Player.h"
#include "Asteroid.h"
#include "Laser.h"
#include "Texture.h"
#include "SoundEffect.h"

class AsteroidsGame : public Scene {
public:
    explicit AsteroidsGame(SDL_Renderer* renderer);

    void update() override;
    void render(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& event) override;

    void spawnLaser(Vector2f position, Vector2f velocity);
    void spawnAsteroids(std::vector<std::unique_ptr<Asteroid>> asteroids);

private:
    CollisionSystem collisionSystem;

    using gameObjPtr = std::unique_ptr<GameObject>;
    std::vector<gameObjPtr> gameObjects;

    std::vector<gameObjPtr> spawnedObjects;

    Texture shipTex;
    Texture asteroidTex;

    SoundEffect laserSound;
    SoundEffect largeBangSound;

    void moveObjectsWithinBounds();
};


#endif //ASTEROIDS_CLONE_SDL_ASTEROIDS_GAME_H
