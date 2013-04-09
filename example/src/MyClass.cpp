// =============================================================================
//
// Copyright (c) 2009-2013 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#include "MyClass.h"


//------------------------------------------------------------------------------
MyClass::MyClass(int x, int y, int width, int height)
:
_x(x),
_y(y),
_width(width),
_height(height),
lastMessage(""),
alpha(0.0f)
{

}

//------------------------------------------------------------------------------
MyClass::~MyClass()
{
    
}

//------------------------------------------------------------------------------
void MyClass::draw()
{
    alpha -= 4;
    if(alpha < 0) alpha = 0;
    
    ofPushStyle();
    ofEnableAlphaBlending();
    
    ofPushMatrix();
    ofTranslate(_x,_y);
    
    
    ofFill();
    ofSetColor(255,127);
    ofRect(0,0,_width,_height);

    ofSetColor(255,255,0,alpha);
    ofDrawBitmapString(lastMessage, 12,15);
    
    
    ofPopMatrix();
    
    ofPopStyle();
}

//------------------------------------------------------------------------------
void MyClass::onEnabled()
{
    lastMessage = "Enabled!";
    alpha = 255;
}

//------------------------------------------------------------------------------
void MyClass::onDisabled()
{
    lastMessage = "Disabled!";
    alpha = 255;
}