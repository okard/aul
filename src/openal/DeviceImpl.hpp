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
#ifndef __AUL_DEVICEIMPL_HPP__
#define __AUL_DEVICEIMPL_HPP__

#include <aul/Exception.hpp>
#include <aul/Device.hpp>

#include <stdio.h>
#include <stdlib.h>

#include <AL/al.h>
#include <AL/alc.h>

namespace aul {

/**
* OpenAL Device Implementation
*/
class Device::Impl 
{
private:
    /// OpenAL Device
    ALCdevice *dev;
    
    /// OpenAL Context
    ALCcontext *ctx;

public:
    /// Create new OpenAL Device
    Impl()
    {
        dev = alcOpenDevice(NULL);
        if(!dev)
        {
            throw aul::Exception("alcOpenDevice failed");
        }
        
        // clear error code
        alGetError(); 
        
        ctx = alcCreateContext(dev, NULL);
        if(!ctx)
        {
            throw aul::Exception("alcCreateContext failed");
        }
        
        alcMakeContextCurrent(ctx);
    }
    
    /// Destroy OpenAL Device
    ~Impl()
    {
        alcMakeContextCurrent(NULL);
        alcDestroyContext(ctx);
        alcCloseDevice(dev);
    }
    
};

} // end namespace aul

#endif // __AUL_DEVICEIMPL_HPP__