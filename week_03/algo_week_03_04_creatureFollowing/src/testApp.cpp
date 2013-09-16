#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetRectMode(OF_RECTMODE_CENTER);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    myFish.update();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);

        myFish.xenoToPoint(mouseX, mouseY);
        myFish.draw();

    
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
