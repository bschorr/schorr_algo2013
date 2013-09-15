#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    for ( int i = 0; i < 36; i++ ) {
        
        
        float tempX = ofGetWindowWidth()/2 + 150 * cos(ofDegToRad(i*10));
        float tempY = ofGetWindowHeight()/2 + 150 * sin(ofDegToRad(i*10));
        
        circles.push_back(Circle ( ofVec2f (tempX, tempY), 150.0f, 10, (i*10)+ (i * 5) ));
        
        
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for ( int i = 0; i < 36; i++ ) {
    
        circles[i].update();
    
    }

}

//--------------------------------------------------------------
void testApp::draw(){

    for ( int i = 0; i < 36; i++ ) {
        
        circles[i].draw();
        
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
