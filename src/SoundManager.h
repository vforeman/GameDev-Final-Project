#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_

#include <unistd.h>
#include <pthread.h>
#include "OggStream.h"

class SoundManager
{
    public:
        static SoundManager& getInstance();
        bool running = false;
        void close();
        void start(const char*);
        void start(std::string);
        void stop();
    private:
        SoundManager();
        SoundManager(const SoundManager&);
        SoundManager& operator= (const SoundManager&);
        void* status;
        pthread_t player;
};


#endif
