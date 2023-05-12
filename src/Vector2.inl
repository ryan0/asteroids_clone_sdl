//
// Created by ryan on 5/6/2023.
//

template<typename T>
Vector2<T>::Vector2() = default;

template<typename T>
Vector2<T>::Vector2(T x, T y) : x(x), y(y) {}

template <typename T>
Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x + right.x, left.y + right.y);
}

template <typename T>
Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x - right.x, left.y - right.y);
}