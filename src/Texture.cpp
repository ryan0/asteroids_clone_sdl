//
// Created by ryan on 5/6/2023.
//

#include <SDL_image.h>
#include <iostream>
#include "Texture.h"


Texture::Texture() : textureRef(nullptr), width(0), height(0) { }

Texture::~Texture() {
    free();
}

bool Texture::loadFromFile(SDL_Renderer *renderer, std::string fileName) {
    bool success = false;
    SDL_Surface* loadedSurface = IMG_Load(fileName.c_str());
    if(loadedSurface == nullptr) {
        std::cout << "Error loading image " << SDL_GetError();
    }
    else {
        textureRef = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (textureRef == nullptr) {
            std::cout << "Error creating texture " << SDL_GetError();
        } else {
            success = true;
            width = loadedSurface->w;
            height = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }
    return success;
}

void Texture::free() {
    if (textureRef != nullptr) {
        SDL_DestroyTexture(textureRef);
        width = 0;
        height = 0;
    }
}

SDL_Texture *Texture::getTextureRef() {
    return textureRef;
}

int Texture::getWidth() const {
    return width;
}

int Texture::getHeight() const {
    return height;
}