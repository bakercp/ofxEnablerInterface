#include "testApp.h"

//------------------------------------------------------------------------------
void testApp::setup()
{
    ofSetFrameRate(60);
    
    lastState = ofToString(myClass.isEnabled());
    faderAlpha = 0;
    
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
    
    faderAlpha -= 3;
    if(faderAlpha < 0) faderAlpha =0;
    
    myClass.draw();
    
    ofFill();
    ofSetColor(255);
    
    ofDrawBitmapString("Press Spacebar to Toggle", 12,12);
    
    ofEnableAlphaBlending();
    
    ofSetColor(255,255,0,faderAlpha);
    ofDrawBitmapString(lastState, 12,ofGetHeight() - 3);
    
    ofDisableAlphaBlending();
}

//------------------------------------------------------------------------------
void testApp::keyPressed(int key) {
    if(key == ' ') {
        myClass.toggleEnabled();
    } else if(key == 'e') {
        myClass.enable();
    } else if(key == 'd') {
        myClass.disable();
    } else if(key == 'E') {
        myClass.setEnabled(true);
    } else if(key == 'D') {
        myClass.setEnabled(false);
    }
}

//------------------------------------------------------------------------------
void testApp::myClassEnabled(const void* sender, bool& value) {
    if(value) {
        lastState = "MyClass was enabled.";
    } else {
        lastState = "MyClass was disabled.";
    }
    
    faderAlpha = 255;
}
