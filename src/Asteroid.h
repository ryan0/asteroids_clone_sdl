//
// Created by ryan on 5/8/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_ASTEROID_H
#define ASTEROIDS_CLONE_SDL_ASTEROID_H

#include <SDL.h>
#include <memory>
#include "GameObject.h"
#include "Vector2.h"
#include "Sprite.h"
#include "BoxCollider.h"

class Asteroid : public GameObject {
public:
    Asteroid();
    explicit Asteroid(Texture* texture, Vector2f position, Vector2f velocity);

    void update() override;
    void render(SDL_Renderer* renderer) override;
    [[nodiscard]] bool shouldDelete() const override;

    std::shared_ptr<BoxCollider> getBoxCollider();

private:
    Sprite sprite;
    Vector2f velocity;
    std::shared_ptr<BoxCollider> collider;

    float rotationSpeed = 0.5f;
    float rotation = 0.0f;
    bool isHitByLaser = false;

    void checkCollisionSignals();
};

#endif //ASTEROIDS_CLONE_SDL_ASTEROID_H
