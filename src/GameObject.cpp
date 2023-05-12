//
// Created by ryan on 5/12/2023.
//

#include "GameObject.h"


GameObject::GameObject(Vector2f position) : position(position) {}

void GameObject::update() {}

void GameObject::render(SDL_Renderer *renderer) {}

void GameObject::handleEvent(const SDL_Event &event) {}

bool GameObject::shouldDelete() const {
    return false;
}