//
// Created by ryan on 5/9/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_SCENE_H
#define ASTEROIDS_CLONE_SDL_SCENE_H

#include <SDL.h>

class Scene {
public:
    virtual void update() = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void handleEvent(const SDL_Event& event) = 0;
    virtual ~Scene() = default;
};


#endif //ASTEROIDS_CLONE_SDL_SCENE_H
