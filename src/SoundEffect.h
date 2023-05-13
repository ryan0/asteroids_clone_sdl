//
// Created by ryan on 5/12/2023.
//

#ifndef ASTEROIDS_CLONE_SDL_SOUND_EFFECT_H
#define ASTEROIDS_CLONE_SDL_SOUND_EFFECT_H

#include <string>
#include <SDL_mixer.h>

class SoundEffect {
public:
    SoundEffect();
    bool loadFromFile(const std::string& filename);
    void play();
    void loop();
    bool isPLaying();
    void stop(int fade = 0);
    void free();
    ~SoundEffect();
private:
    bool isPlaying = false;
    Mix_Chunk* chunkRef = nullptr;
    int channel = 0;
};


#endif //ASTEROIDS_CLONE_SDL_SOUND_EFFECT_H
