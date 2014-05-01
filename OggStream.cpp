#include "src/OggStream.h"

OggStream::OggStream()
{
}

OggStream& OggStream::getInstance()
{
    static OggStream instance;
    return instance;
}

bool OggStream::playback()
{
    if(playing())
        return true;

    if(!stream(buffers[0]))
        return false;

    if(!stream(buffers[1]))
        return false;

    alSourceQueueBuffers(source, 2, buffers);
    alSourcePlay(source);

    return true;
}

bool OggStream::playing()
{
    ALenum state;

    alGetSourcei(source, AL_SOURCE_STATE, &state);

    return (state == AL_PLAYING);
}

bool OggStream::update()
{
    int processed;
    bool active = true;

    alGetSourcei(source, AL_BUFFERS_PROCESSED, &processed);

    while(processed--)
    {
        ALuint buffer;

        alSourceUnqueueBuffers(source, 1, &buffer);
        check();

        active = stream(buffer);

        alSourceQueueBuffers(source, 1, &buffer);
        check();
    }

    return active;
}

void OggStream::open(const char* path)
{
    int result;

    if(!(oggFile = fopen(path, "rb")))
    {
        throw std::string("Could not open Ogg file");
    }

    if((result = ov_open(oggFile, &oggStream, NULL, 0)) < 0)
    {
        fclose(oggFile);
        throw std::string("Could not open ogg stream")+errorString(result);
    }

    vorbisInfo = ov_info(&oggStream, -1);
    vorbisComment = ov_comment(&oggStream, -1);

    if(vorbisInfo->channels == 1)
        format = AL_FORMAT_MONO16;
    else
        format = AL_FORMAT_STEREO16;

    //Extract OpenAL enumerator based on channels
    alGenBuffers(2, buffers);
    check();
    alGenSources(1, &source);

    //2D BACKGROUND SOUND
    alSource3f(source, AL_POSITION, 0.0f, 0.0f, 0.0f);
    alSource3f(source, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
    alSource3f(source, AL_DIRECTION, 0.0f, 0.0f, 0.0f);

    alSourcef(source, AL_ROLLOFF_FACTOR, 0.0f);
    alSourcei(source, AL_SOURCE_RELATIVE, AL_TRUE);
}

void OggStream::open(std::string path)
{
    open(path.c_str());
}

void OggStream::release()
{       
    alSourceStop(source);
    empty();
    alDeleteSources(1, &source);
    check();
    alDeleteBuffers(1, buffers);
    check();
    
    ov_clear(&oggStream);   
}

void OggStream::stop()
{
    alSourceStop(source);
}

bool OggStream::stream(ALuint  buffer)
{
    char data[BUFFER_SIZE];
    int section;
    int result;
    unsigned int size = 0;

    while(size < BUFFER_SIZE)
    {
        result = ov_read(&oggStream, data + size, BUFFER_SIZE-size, 
                         0, 2, 1, &section);

        if(result > 0)
            size += result;
        else
            if(result < 0)
            {
                throw errorString(result);
            }
            else
                break;

    }
    
    if(size == 0)
        return false;

        alBufferData(buffer, format, data, size, vorbisInfo->rate);
        check();

        return true;    
}

std::string OggStream::errorString(int code)
{
    switch(code)
    {
        case OV_EREAD:
            return std::string("Read from media");
        case OV_ENOTVORBIS:
            return std::string("Not vorbis data");
        case OV_EVERSION:
            return std::string("Vorbis version mismatch");
        case OV_EBADHEADER:
            return std::string("Invalid Vorbis Header");
        case OV_EFAULT:
            return std::string("Internal Logic Fault(Heap/Stack Corruption)");
        default:
            return std::string("Danger Zone");
    }
}

void OggStream::check()
{
    int error = alGetError();

    if(error != AL_NO_ERROR)
        switch(error)
        {
            case AL_INVALID_NAME:
                throw std::string("OpenAL error");
            case AL_INVALID_ENUM:
                throw std::string("OpenAL error");
            case AL_INVALID_VALUE:
                throw std::string("OpenAL error");
            case AL_INVALID_OPERATION:
                throw std::string("OpenAL error");
            case AL_OUT_OF_MEMORY:
                throw std::string("OpenAL error");
            default:
                throw std::string("OpenAL error");
        }
}

void OggStream::empty()
{
    int queued;

    alGetSourcei(source, AL_BUFFERS_QUEUED, &queued);

    while(queued--)
    {
        ALuint buffer;

        alSourceUnqueueBuffers(source, 1, &buffer);
        check();
    }
}
