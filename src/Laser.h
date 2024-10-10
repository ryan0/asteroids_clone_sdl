//
// Created by ryan on 5/9/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_LASER_H
#define ASTEROIDS_CLONE_SDL_LASER_H


#include <memory>
#include <SDL_render.h>
#include "GameObject.h"
#include "Vector2.h"
#include "BoxCollider.h"

class Laser: public GameObject {
public:
    Laser(Vector2f position, Vector2f velocity);

    void update() override;
    void render(SDL_Renderer* renderer) override;
    [[nodiscard]] bool shouldDelete() const override;

    std::shared_ptr<BoxCollider> getBoxCollider();

private:
    Vector2f velocity;
    std::shared_ptr<BoxCollider> collider;

    int ticksLeft = 50;
};

#endif //ASTEROIDS_CLONE_SDL_LASER_H
