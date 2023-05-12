//
// Created by ryan on 5/6/2023.
//

template<typename T>
Rect<T>::Rect() = default;

template<typename T>
Rect<T>::Rect(T x, T y, T width, T height) : position(x, y), width(width), height(height) {}

template<typename T>
Rect<T>::Rect(Vector2<T> position, T width, T height) : position(position.x, position.y), width(width), height(height) { }

template<typename T>
Rect<T> Rect<T>::getTranslated(const Vector2f &offset) const {
    return {position + offset, width, height};
}


template<typename T>
bool Rect<T>::contains(const Vector2<T> &point) {

    const T minX = position.x;
    const T maxX = position.x + width;
    const T minY = position.y;
    const T maxY = position.y + height;

    return (point.x >= minX) && (point.x <= maxX) && (point.y >= minY) && (point.y <= maxY);
}

template<typename T>
bool Rect<T>::intersects(const Rect<T> &rect) {
    if (position.x > rect.position.x + rect.width) return false;  // This box is to the right of the other box
    if (position.x + width < rect.position.x) return false;        // This box is to the left of the other box
    if (position.y > rect.position.y + rect.height) return false; // This box is below the other box
    if (position.y + height < rect.position.y) return false;       // This box is above the other box

    return true;
}

template<typename T>
SDL_Rect Rect<T>::getSDL_Rect() const {
    SDL_Rect r = {position.x, position.y, width, height};
    return r;
}

template<typename T>
SDL_FRect Rect<T>::getSDL_FRect() const {
    SDL_FRect r = {position.x, position.y, width, height};
    return r;
}