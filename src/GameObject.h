//
// Created by ryan on 5/12/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_GAME_OBJECT_H
#define ASTEROIDS_CLONE_SDL_GAME_OBJECT_H

#include <SDL.h>
#include "Vector2.h"

class GameObject {
public:
    Vector2f position{0.0f, 0.0f};

    virtual void update() = 0;
    virtual void handleEvent(const SDL_Event& event);
    virtual void render(SDL_Renderer* renderer);
    [[nodiscard]] virtual bool shouldDelete() const;
    virtual ~GameObject() = default;

protected:
    GameObject() = default;
    explicit GameObject(Vector2f position);

};

#endif //ASTEROIDS_CLONE_SDL_GAME_OBJECT_H
