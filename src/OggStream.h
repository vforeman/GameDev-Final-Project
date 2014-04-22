#ifndef OGGSTREAM_H
#define OGGSTREAM_H

#include <AL/al.h>
#include <AL/alut.h>
#include <ogg/ogg.h>
#include <vorbis/codec.h>
#include <vorbis/vorbisenc.h>
#include <vorbis/vorbisfile.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

const unsigned int NUM_BUFFERS = 3;
const unsigned int BUFFER_SIZE = 4096*8;

class OggStream
{
    public:
        static OggStream& getInstance();
        bool playback();            //Play Ogg Stream
        bool playing();
        bool update();              //Update the stream
        void open(const char*);     //Obtain file handle
        void open(std::string);
        void release();             //Release the file
        void stop();        
    protected:
        bool stream(ALuint buffer);         //Reloads buffer
        std::string errorString(int code);
        void check();                       //Empties the queue
        void empty();               
    private:
        OggStream();                
        OggStream& operator= (const OggStream);
        OggStream(const OggStream&);
        FILE* oggFile;
        OggVorbis_File oggStream;
        vorbis_info* vorbisInfo;
        vorbis_comment* vorbisComment;
        ALuint buffers[2];
        ALuint source;
        ALenum format;
};

#endif
