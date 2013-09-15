#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    
    for (int i = 0; i < NUM ; i++) {
    
    myRect[i].color = ofColor (ofRandom(255), ofRandom(255), ofRandom(255));
        
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < NUM ; i++) {

    myRect[i].xenoToPoint(mouseX, mouseY);
    
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(255);
    
    for (int i = 0; i < NUM ; i++) {

    myRect[i].draw();
        
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
