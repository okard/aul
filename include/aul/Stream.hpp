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
#ifndef __AUL_STREAM_HPP__
#define __AUL_STREAM_HPP__

#include <cstddef>

namespace aul {
    
class Source;

/**
* Represents a audio stream
*/
class Stream
{
public:
    enum Format {MONO8, MONO16, STEREO8, STEREO16};
    
    ///Create new Stream
    Stream(){}
    /// Destruct Stream
    virtual ~Stream(){}
    
    /// open
    virtual void open(const char* file){};
    
    /// Read Data
    virtual void read(char* buffer, size_t bufferSize){};
    
    /// Get format
    virtual Format format(){};
    
    /// Get Rate
    virtual long rate(){};
    
    //empty
    //reset
    //size?
};


template<class T>
class StreamFacCreator
{
public:
    ///Create new Instance of Class
    static Stream* create()
    {
        return new T();
    }
};

/**
* Stream Factory
* Create Streams for specific file types
*/
class StreamFactory
{
public:
    friend class aul::Source;
    typedef Stream* (*StreamCreator)();
    
public:
    /**
    * register stream type
    */
    static void reg(const char* fileExtension, StreamCreator createStream );
    
    /**
    * Create a new stream for given file
    */
    static Stream* create(const char* file);
};
  
} //end namespace aul
    
#endif