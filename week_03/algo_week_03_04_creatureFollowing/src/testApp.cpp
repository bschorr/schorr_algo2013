#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    numFish = 50;

    ofSetRectMode(OF_RECTMODE_CENTER);
     
    for (int i = 0; i < numFish; i++ ) {
        
        myFishes.push_back(Fish (ofPoint (ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight())), ofRandom(25, 40), ofRandom(0.1, 0.5)));
        
    }
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < numFish; i++ ) {

    myFishes[i].update();
        
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);
    
    for (int i = 0; i < numFish; i++ ) {
        
        myFishes[i].draw();
        
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
