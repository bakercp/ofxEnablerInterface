#include "testApp.h"

//------------------------------------------------------------------------------
void testApp::setup()
{
    ofSetFrameRate(60);
    
    lastState = ofToString(myClass.isEnabled());
    alpha = 0;
    
    ofAddListener(myClass.enabled, this, &testApp::myClassEnabled);
}

//------------------------------------------------------------------------------
void testApp::exit()
{
    ofRemoveListener(myClass.enabled, this, &testApp::myClassEnabled);
}

//------------------------------------------------------------------------------
void testApp::draw()
{
    ofBackground(0);
    
    alpha -= 3;
    if(alpha < 0) alpha =0;
    
    myClass.draw();
    
    ofFill();
    ofSetColor(255);
    
    ofDrawBitmapString("Press Spacebar to Toggle", 12,12);
    
    ofEnableAlphaBlending();
    
    ofSetColor(255,255,0,alpha);
    ofDrawBitmapString(lastState, 12,ofGetHeight() - 3);
    
    ofDisableAlphaBlending();
}

//------------------------------------------------------------------------------
void testApp::keyPressed(int key) {
    if(key == ' ') {
        myClass.toggleEnabled();
    }
}

//------------------------------------------------------------------------------
void testApp::myClassEnabled(const void* sender, bool& value) {
    if(value) {
        lastState = "MyClass was enabled.";
    } else {
        lastState = "MyClass was disabled.";
    }
    
    alpha = 255;
}
