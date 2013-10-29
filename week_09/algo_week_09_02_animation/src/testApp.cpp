#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    logo.loadImage("logo.bmp");
    
    ofEnableAlphaBlending();
    
    ofPixels pix = logo.getPixelsRef();
    for(int y=0; y<pix.getHeight(); y++)
    {
        for(int x=0; x<pix.getWidth(); x++)
        {
            ofColor c = pix.getColor(x, y);
            if(c.getBrightness() < 255)
            {
                Particle p;
                ofVec2f pos = ofVec2f (-10.0, y*4);
                ofVec2f dest = ofVec2f (x*4, y*4);
                p.setup(pos, dest);
                particleList.push_back(p);
                
            }
        }
    }
    
    ofSetColor(0, 30);
    triggerParticles = true;
    countToRetrigger = 0;
    

}

//--------------------------------------------------------------
void testApp::update(){

    if (triggerParticles) {
        for (int i = 0; i < particleList.size(); i++) {
            particleList[i].update(i, countOne, countTwo);
        }
        
        if (countOne == 3920) {
            
            for (int i = 0; i < particleList.size(); i++) {
                particleList[i].triggerTwo = true;
            }
            
        }
        
        if (countTwo == 3920) {
            
            triggerParticles = false;
            for (int i = 0; i < particleList.size(); i++) {
                particleList[i].triggerOne = false;
                particleList[i].triggerTwo = false;
                particleList[i].triggerThree = false;
                particleList[i].pos.x = -10.0;
            }
        }
    } else {
        
        countToRetrigger++;
        if (countToRetrigger > 120) {
            triggerParticles = true;
            countToRetrigger = 0;
        }
        
        
    }
    
    countOne = 0;
    countTwo = 0;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(255);
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
