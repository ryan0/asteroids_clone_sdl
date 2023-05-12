//
// Created by ryan on 5/7/2023.
//
#include <complex>
#include "Vector2.h"

Vector2f rotatedBy(const Vector2f& vec2, float degrees) {

    const float PI = 3.14159265358;
    float radians = degrees * (PI / 180.0f);

    float cos = std::cos(radians);
    float sin = std::sin(radians);

    return {(cos * vec2.x) - (sin * vec2.y), (sin * vec2.x) + (cos * vec2.y)};
}
