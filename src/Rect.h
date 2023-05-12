//
// Created by ryanm on 5/6/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_RECT_H
#define ASTEROIDS_CLONE_SDL_RECT_H

#include <SDL_rect.h>
#include "Vector2.h"

template<typename T>
class Rect {
public:
    Vector2<T> position{};
    T width{};
    T height{};

    Rect();
    Rect(T x, T y, T width, T height);
    Rect(Vector2<T>, T width, T height);

    Rect<T> getTranslated(const Vector2f& offset) const;

    bool contains(const Vector2<T>& point);
    bool intersects(const Rect<T>& rect);

    [[nodiscard]] SDL_Rect getSDL_Rect() const;
    [[nodiscard]] SDL_FRect getSDL_FRect() const;
};

typedef Rect<float> FloatRect;
typedef Rect<int> IntRect;

#include "Rect.inl"

#endif //ASTEROIDS_CLONE_SDL_RECT_H
