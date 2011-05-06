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
#include "OggStream.hpp"

#include <aul/Exception.hpp>

using aul::OggStream;

/**
* Create new OGG stream
*/
OggStream::OggStream()
{
}

/**
* Distructs OGG stream
*/
OggStream::~OggStream()
{
}

/**
* Open a file as ogg stream
*/
void OggStream::open(const char* file)
{
    //TODO Error Checks
    
    oggFile = fopen(file, "rb");
    int result = ov_open(oggFile, &oggStream, NULL, 0);
    
    vorbisInfo = ov_info(&oggStream, -1);
    vorbisComment = ov_comment(&oggStream, -1);
}


/**
* Read from stream
*/    
void OggStream::read(char* buffer, size_t bufferSize)
{
    int  size = 0;
    int  section;
    int  result;
 
    //try to read
    while(size < bufferSize)
    {
        result = ov_read(&oggStream, buffer + size, bufferSize - size, 0, 2, 1, & section);
    
        if(result > 0)
            size += result;
        else
            if(result < 0)
                //TODO error constants from ogg
                throw aul::Exception("Error while reading ogg");
            else
                break;
    }
}
