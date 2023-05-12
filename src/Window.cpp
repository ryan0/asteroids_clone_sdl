//
// Created by ryan on 5/6/2023.
//

#include "Window.h"

#include <utility>
#include <iostream>

Window::Window(std::string title, int width, int height) : title(std::move(title)), width(width), height(height) {}

bool Window::createRenderer(int logicalWidth, int logicalHeight, Uint32 flags) {
    bool createSuccess = false;

    if(windowRef == nullptr) {
        std::cout<<"Failed to create Renderer, window not yet opened!";
    } else if(rendererRef != nullptr) {
        std::cout<<"Failed to create Renderer, renderer already exists for window!";
    } else {
        rendererRef = SDL_CreateRenderer(windowRef, -1, flags);
        if(rendererRef == nullptr) {
            std::cout<<"Failed to create Renderer! SDL Error";
        } else {
            SDL_RenderSetLogicalSize(rendererRef, logicalWidth, logicalHeight);
            createSuccess = true;
        }
    }

    return createSuccess;
}

SDL_Renderer *Window::getRenderer() {
    return rendererRef;
}

void Window::open() {
    if(windowRef != nullptr) {
        std::cout<<"Failed to open window! SDL window reference already initialized";
    } else {
        windowRef = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
                                     SDL_WINDOW_SHOWN);
        if (windowRef == nullptr) {
            std::cout<<"Failed to open window! SDL Error";
        }
    }
}

void Window::close() {
    if(rendererRef != nullptr) {
        SDL_DestroyRenderer(rendererRef);
        rendererRef = nullptr;
    }
    SDL_DestroyWindow(windowRef);
    windowRef = nullptr;
}

int Window::getWidth() const {
    return width;
}

int Window::getHeight() const {
    return height;
}