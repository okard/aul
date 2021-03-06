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
#ifndef __AUL_OGGSTREAM_HPP__
#define __AUL_OGGSTREAM_HPP__

#include <aul/Stream.hpp>

#include <ogg/ogg.h>
#include <vorbis/codec.h>
#include <vorbis/vorbisenc.h>
#include <vorbis/vorbisfile.h>

namespace aul {
 
/**
* Represents a OGG Stream
*/    
class OggStream : public Stream, public StreamFacCreator<OggStream>
{
private:
    /// File Handle
    FILE*           oggFile; 
    /// OGG Stream Handle
    OggVorbis_File  oggStream;    
    /// Vorbis Info
    vorbis_info*    vorbisInfo;   
    /// Vorbis Comment
    vorbis_comment* vorbisComment; 
    
public:
    /**
    * Create new OGG stream
    */
    OggStream();
    
    /**
    * Destructs OGG stream
    */
    ~OggStream ();
    
    /**
    * Open a file as ogg stream
    */
    void open(const char* file);
    
    /**
    * Read from stream
    */
    virtual void read(char* buffer, size_t bufferSize);
    
    /// Get format
    virtual Format format();
    
    /// Get Rate
    virtual long rate();
};
    
      
} //end namespace aul

#endif // __AUL_OGGSTREAM_HPP__