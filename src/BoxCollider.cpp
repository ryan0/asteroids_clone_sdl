//
// Created by ryan on 5/9/2023.
//

#include <iostream>
#include "BoxCollider.h"

BoxCollider::BoxCollider(float x, float y, float width, float height) : rect(x, y, width, height) {}

BoxCollider::BoxCollider(FloatRect box) : rect(box) {}

void BoxCollider::setOffset(const Vector2f &offset) {
    translation = offset;
}

void BoxCollider::checkCollision(BoxCollider* collisionBox) {
    FloatRect transformed = rect.getTranslated(translation);
    FloatRect otherTransformed = collisionBox->rect.getTranslated(collisionBox->translation);

    if(transformed.intersects(otherTransformed)) {
        receivedSignals.push_back(collisionBox->outSignal);
        collisionBox->receivedSignals.push_back(outSignal);

        //std::cout<<outSignal<<std::endl;
        //std::cout<<collisionBox->outSignal<<std::endl;
    }
}

void BoxCollider::render(SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
    SDL_FRect drawRect = rect.getTranslated(translation).getSDL_FRect();
    SDL_RenderDrawRectF(renderer, &drawRect);
}

void BoxCollider::setOutSignal(const std::string &signal) {
    outSignal = signal;
}

const std::vector<std::string> &BoxCollider::getReceivedSignals() {
    return receivedSignals;
}

void BoxCollider::clearSignals() {
    receivedSignals.clear();
}
