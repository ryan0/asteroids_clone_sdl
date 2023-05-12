//
// Created by ryan on 5/6/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_WINDOW_H
#define ASTEROIDS_CLONE_SDL_WINDOW_H

#include <SDL.h>
#include <string>

class Window {

public:
    Window(std::string title, int width, int height);
    void open();
    void close();
    bool createRenderer(int logicalWidth, int logicalHeight, Uint32 flags);
    SDL_Renderer* getRenderer();
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;

private:
    int width = 0;
    int height = 0;
    std::string title = "A Window";
    SDL_Window* windowRef = nullptr;
    SDL_Renderer* rendererRef = nullptr;

};


#endif //ASTEROIDS_CLONE_SDL_WINDOW_H
