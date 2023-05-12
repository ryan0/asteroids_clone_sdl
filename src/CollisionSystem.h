//
// Created by ryan on 5/10/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_COLLISION_SYSTEM_H
#define ASTEROIDS_CLONE_SDL_COLLISION_SYSTEM_H

#include <vector>
#include <memory>
#include "BoxCollider.h"

class CollisionSystem {
public:
    void update();
    void addToPhysicsSystem(std::shared_ptr<BoxCollider> collider);
private:
    std::vector<std::weak_ptr<BoxCollider>> colliders{};
};


#endif //ASTEROIDS_CLONE_SDL_COLLISION_SYSTEM_H
