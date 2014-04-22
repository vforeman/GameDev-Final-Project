#include "src/SoundManager.h"

SoundManager::SoundManager()
{
}

SoundManager& SoundManager::getInstance()
{
    static SoundManager instance;
    return instance;
}

void* play(void* name)
{
    OggStream::getInstance();

    char* songName;
    songName = (char*) name;
    bool valid = true;

    while(valid) //continuosly loop background music
    {
        try
        {
            OggStream::getInstance().open(songName);

            if(!OggStream::getInstance().playback())
                throw std::string("Ogg Refused to Play");

            while(OggStream::getInstance().update())
            {
                if(!OggStream::getInstance().playing())
                {
                    if(!OggStream::getInstance().playback())
                        throw std::string("Ogg Stopped");
                    else
                        printf("Ogg Stream Interrupted\n");
                }
            }
        }
        catch(std::string error)
        {
            printf("DANGER ZONE\n");
            printf("%s\n", error.c_str());
            valid = false;
        }
    }
    pthread_exit(NULL);
}

void SoundManager::close()
{
    OggStream::getInstance().release();
}

void SoundManager::start(const char* title)
{
    OggStream::getInstance();

    int creation;
    creation = pthread_create(&player, NULL, play, (void *) title);

    if(creation)
    {
        printf("FAILED: Thread Creation\n");
    }
}

void SoundManager::start(std::string title)
{
    this->start(title.c_str());
}

void SoundManager::stop()
{
    pthread_cancel(player);
    OggStream::getInstance().stop();
}
