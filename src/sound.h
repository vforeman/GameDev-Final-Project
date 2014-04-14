#ifndef SOUND_H
#define SOUND_H

int audio_rate = 22050;
Uint16 audio_format = AUDIO_S16SYS;
int audio_channels = 2;
int audio_buffers = 4096;

Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers)

Mix_Chunk *sound = NULL;

sound = Mix_LoadWAV("sound.wav");

#endif
