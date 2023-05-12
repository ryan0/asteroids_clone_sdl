//
// Created by ryan on 5/10/2023.
//

#include "CollisionSystem.h"


void CollisionSystem::update() {
    for(auto it = colliders.begin(); it != colliders.end();) {
        if(it->expired()) {
            it = colliders.erase(it);
        } else {
            it->lock()->clearSignals();
            it++;
        }
    }

    for(int i = 0; i + 1 < colliders.size(); i++) {
        for (int j = i + 1; j < colliders.size(); j++) {
            auto ptr = colliders[i].lock();
            auto ptr2 = colliders[j].lock();
            ptr->checkCollision(ptr2.get());
        }
    }
}

void CollisionSystem::addToPhysicsSystem(std::shared_ptr<BoxCollider> collider) {
    colliders.push_back(collider);
}