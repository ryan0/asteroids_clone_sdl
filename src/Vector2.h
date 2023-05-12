//
// Created by ryan on 5/6/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_VECTOR2_H
#define ASTEROIDS_CLONE_SDL_VECTOR2_H

template <typename T>
class Vector2 {
public:
    T x{};
    T y{};

    Vector2();
    Vector2(T x, T y);
};

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;

template <typename T>
Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right);

Vector2f rotatedBy(const Vector2f& vec2, float angle);

#include "Vector2.inl"

#endif //ASTEROIDS_CLONE_SDL_VECTOR2_H
