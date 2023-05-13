//
// Created by ryan on 5/12/2023.
//

#include <iostream>
#include "SoundEffect.h"

SoundEffect::SoundEffect() = default;

bool SoundEffect::loadFromFile(const std::string& filename) {
    free();

    bool success = false;
    chunkRef = Mix_LoadWAV(filename.c_str());
    if(chunkRef == nullptr) {
        std::cout<<"Error loading sound effect "<<Mix_GetError()<<std::endl;
    } else {
        success = true;
    }

    return success;
}

void SoundEffect::play() {
    channel = Mix_PlayChannel(-1, chunkRef, 0);
}

void SoundEffect::loop() {
    if(!isPlaying) {
        channel = Mix_PlayChannel(-1, chunkRef, -1);
        isPlaying = true;
    }
}

void SoundEffect::stop(int fade) {
    if(isPlaying) {
        Mix_FadeOutChannel(channel, fade);
        isPlaying = false;
    }
}

bool SoundEffect::isPLaying() {
    return isPlaying;
}

void SoundEffect::free() {
    Mix_FreeChunk(chunkRef);
    chunkRef = nullptr;
}

SoundEffect::~SoundEffect() {
    free();
}