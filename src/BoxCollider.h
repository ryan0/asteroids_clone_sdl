//
// Created by ryan on 5/9/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_BOX_COLLIDER_H
#define ASTEROIDS_CLONE_SDL_BOX_COLLIDER_H

#include <SDL.h>
#include <vector>
#include <string>
#include "Rect.h"

class BoxCollider {
public:
    BoxCollider(float x, float y, float width, float height);
    explicit BoxCollider(FloatRect rect);

    void setOffset(const Vector2f& offset);
    void checkCollision(BoxCollider* collisionBox);
    void setOutSignal(const std::string& signal);
    const std::vector<std::string>& getReceivedSignals();
    void clearSignals();
    void render(SDL_Renderer* renderer) const;
    [[nodiscard]] float getWidth() const;
    [[nodiscard]] float getHeight() const;

private:
    std::string outSignal = "Default";
    std::vector<std::string> receivedSignals{};
    Vector2f translation{0.0f, 0.0f};
    FloatRect rect;
};


#endif //ASTEROIDS_CLONE_SDL_BOX_COLLIDER_H
