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
#ifndef __AUL_SOURCE_HPP__
#define __AUL_SOURCE_HPP__



namespace aul {
    
class Device;

    
/**
* Audio Source
*/
class Source
{
public:
    enum PlayType { BLOCK, ASYNC };
    
    
    /**
    * Create new Audio Source
    */
    Source(Device* dev);
    
    /**
    * Destructs Audio Source
    */
    ~Source();
    
    /**
    * Open File
    */
    void open(const char* file);
    
    /**
    * Update Source
    */
    void update();
    
    /**
    * Play Source
    */
    void play();
    
    /**
    * Pause Source
    */
    void pause();
    
    /**
    * Stop Source
    */
    void stop();
    
    //loop 
    //blocking play
    
    //statuc
    
private:
    class Impl;
    Impl* impl;
};
    
    
} // end namespace aul

#endif // __AUL_SOURCE_HPP__