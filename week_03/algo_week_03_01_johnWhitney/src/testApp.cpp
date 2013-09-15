#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    numCircles = 1;
    ofSetBackgroundAuto(false);
    ofBackground(0);
    
    for ( int i = 0; i < 360; i += numCircles ) {
        
        
        float tempX = ofGetWindowWidth()/2 + 150 * cos(ofDegToRad(i));
        float tempY = ofGetWindowHeight()/2 + 150 * sin(ofDegToRad(i));
        
        circles.push_back(Circle ( ofVec2f (tempX, tempY), 150.0f, 2, i ));
        
        
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for ( int i = 0; i < circles.size(); i++ ) {
    
        circles[i].update();
    
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(0, 0, 0, 5);
    ofRect ( 0, 0, ofGetWindowWidth(), ofGetWindowHeight() );
    
    ofSetColor(255);
    for ( int i = 0; i < circles.size(); i++ ) {
        
        circles[i].draw();
        
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == OF_KEY_UP) {
        
        for ( int i = 0; i < circles.size(); i++ ) {
        
            circles[i].degrees += 0.1f * i;
        
        }

    }
    
    if (key == OF_KEY_DOWN) {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].degrees -= 0.1f * i;
            
        }
        
    }
    
    if (key == ' ') {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].degrees = i * numCircles;
            
        }
        
    }

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
