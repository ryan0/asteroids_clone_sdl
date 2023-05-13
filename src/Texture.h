//
// Created by ryan on 5/6/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_TEXTURE_H
#define ASTEROIDS_CLONE_SDL_TEXTURE_H

#include <SDL.h>
#include <string>

class Texture {

public:
    Texture();
    ~Texture();
    bool loadFromFile(SDL_Renderer* renderer,  std::string fileName);
    void free();
    SDL_Texture* getTextureRef();
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;

private:
    SDL_Texture* textureRef = nullptr;
    int width = 0;
    int height = 0;
};


#endif //ASTEROIDS_CLONE_SDL_TEXTURE_H
