//
// Created by ryan on 5/6/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_PLAYER_H
#define ASTEROIDS_CLONE_SDL_PLAYER_H

#include <SDL.h>
#include <functional>
#include "GameObject.h"
#include "Vector2.h"
#include "Rect.h"
#include "Sprite.h"
#include "Animation.h"
#include "Laser.h"
#include "BoxCollider.h"
#include "SoundEffect.h"

class AsteroidsGame;

class Player : public GameObject {
public:
    Player(Texture* shipTexRef, SoundEffect* laserSoundRef, SoundEffect* thrustSound, AsteroidsGame* gameRef);

    void update() override;
    void handleEvent(const SDL_Event& event) override;
    void render(SDL_Renderer* renderer) override;
    [[nodiscard]] bool shouldDelete() const override;

    std::shared_ptr<BoxCollider> getCollider();

private:
    Vector2f velocity{0.0f, 0.0f};
    std::shared_ptr<BoxCollider> collider;
    Sprite shipSprite;
    Animation shipThrustAni;

    AsteroidsGame* gameRef = nullptr;
    SoundEffect* laserSoundRef = nullptr;
    SoundEffect* thrustSoundRef = nullptr;

    static const int fireCoolDown = 10;
    int fireTimer = 0;
    float rotation = 0;
    bool thrustOn = false;
    bool hitAsteroid = false;

    void checkKeyStates();
    void checkCollisionSignals();
};

#endif //ASTEROIDS_CLONE_SDL_PLAYER_H
