/*
    Audio Utility Library

    Copyright (c) 2011 okard

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/
#ifndef __AUL__SOURCEIMPL_HPP__
#define __AUL__SOURCEIMPL_HPP__

#include <stdio.h>
#include <stdlib.h>

#include <AL/al.h>
#include <AL/alc.h>

#include <aul/Source.hpp>
#include <aul/Device.hpp>
#include <aul/Stream.hpp>

namespace aul {

/**
* OpenAL Audio Source Implementation
*/
class Source::Impl
{
private:
    /// OpenAL Buffer
    ALuint buffer;

    /// OpenAL Audio Source
    ALuint source;
    
    /// Audio Stream
    Stream* stream;
    
    /// Is AudioStream Open
    bool streamOpen;

public:
    /// Create OpenAL Audio Source
    Impl(Device* dev)
        : stream(0)
    {
        // Load wav data into a buffer.
        alGenBuffers(1, &buffer);
        if (alGetError() != AL_NO_ERROR)
        {
            fprintf(stderr, "alGenBuffers failed\n");
            return;
        }
        
        // Bind buffer with a source.
        alGenSources(1, &source);
        if (alGetError() != AL_NO_ERROR)
        {
            fprintf(stderr, "alGenSources failed\n");
            return;
        }
        
        // Position of the source sound.
        ALfloat SourcePos[] = { 0.0, 0.0, 0.0 };
        // Velocity of the source sound.
        ALfloat SourceVel[] = { 0.0, 0.0, 0.0 };

        //initial configuraton for source
        alSourcei (source, AL_BUFFER,   buffer   );
        alSourcef (source, AL_PITCH,    1.0f     );
        alSourcef (source, AL_GAIN,     1.0f     );
        alSourcefv(source, AL_POSITION, SourcePos);
        alSourcefv(source, AL_VELOCITY, SourceVel);
        alSourcei (source, AL_LOOPING,  false     );
    }
    
    /// Destructs a openal audio source
    ~Impl()
    {
        stop();
        alDeleteBuffers(1, &buffer);
        alDeleteSources(1, &source);
    }
    
    /// Open a file for play
    void open(const char* file)
    {
        if(stream)
        {
            delete stream;
            stream = 0;
        }
        
        stream = StreamFactory::create(file);
        update();
    }
    
    /**
    * Update Buffer
    */
    void update()
    {     
        ALenum format;
        ALsizei size;
        ALvoid* data;
        ALsizei freq;
        ALboolean loop;
        
        //read from stream to buffer
        //alBufferData(Buffer, format, data, size, freq);
    }
    
    
    /// Play audio 
    void play()
    {   
        alSourcePlay(source);
    }
    
    /// Pause audio
    void pause()
    {
         alSourcePause(source);
    }
    
    /// Stop audio
    void stop()
    {
         alSourceStop(source);
    }
    
    /*
        ALenum state;
        alGetSourcei(source, AL_SOURCE_STATE, &state);
        return (state == AL_PLAYING); 
    */
};
    
    

} //end namespace aul

#endif