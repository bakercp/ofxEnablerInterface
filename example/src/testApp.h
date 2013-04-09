#pragma once

#include "ofMain.h"

#include "MyClass.h"

class testApp : public ofBaseApp {
public:
    void setup();
    void exit();
    void draw();
    
    void keyPressed(int key);
    
    void myClassEnabled(const void* sender, bool& value);
    // or simply:
    // void myClassEnabled(bool& value);
    
private:
    MyClass myClass;
    string  lastState;
    int     faderAlpha;
};
