//
// Created by ryan on 5/8/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_ASTEROID_H
#define ASTEROIDS_CLONE_SDL_ASTEROID_H

#include <SDL.h>
#include <memory>
#include "GameObject.h"
#include "Vector2.h"
#include "Sprite.h"
#include "BoxCollider.h"
#include "SoundEffect.h"

class AsteroidsGame;

class Asteroid : public GameObject {
public:
    enum SIZE {
        LARGE,
        MEDIUM,
        SMALL,
    };

    Asteroid();
    Asteroid(AsteroidsGame* game, Texture* texture, SoundEffect* largeBang, Vector2f position, Vector2f velocity);
    Asteroid(AsteroidsGame* game, SIZE size, Texture* texture, SoundEffect* largeBang, Vector2f position, Vector2f velocity);

    void update() override;
    void render(SDL_Renderer* renderer) override;
    [[nodiscard]] bool shouldDelete() const override;

    std::shared_ptr<BoxCollider> getBoxCollider();

private:
    Sprite sprite;
    Vector2f velocity;
    std::shared_ptr<BoxCollider> collider;

    AsteroidsGame* gameRef{};
    SoundEffect* largeBangSoundRef{};
    Texture* textureRef{};

    float rotationSpeed = 0.5f;
    float rotation = 0.0f;
    bool isHitByLaser = false;
    SIZE size = LARGE;

    void checkCollisionSignals();
    void breakUp();

    static FloatRect getCollisionRectAtSize(SIZE size);
    static float getDrawPixels(SIZE size);
};

#endif //ASTEROIDS_CLONE_SDL_ASTEROID_H
