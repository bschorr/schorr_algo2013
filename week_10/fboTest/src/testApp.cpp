#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    pos = ofGetWindowSize()/2;
    vel.set ( 20, 9 );
    
    mFbo.allocate (ofGetWindowWidth(), ofGetWindowHeight());
    
    ofEnableAlphaBlending();
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    pos += vel;
    
    if (pos.x < 0 || pos.x > ofGetWindowWidth()) {
        vel.x *= -1;
    }
    
    if (pos.y < 0 || pos.y > ofGetWindowHeight()) {
        vel.y *= -1;
    }

}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackground(0);

    mFbo.begin(); {
        ofClear( 255, 255, 255, 0 );
        ofPushMatrix();{
            ofTranslate( pos );
            ofSetRectMode (OF_RECTMODE_CENTER);
            ofRect(0, 0, 50, 50);
        }ofPopMatrix();
    }mFbo.end();
    
    
    ofSetRectMode (OF_RECTMODE_CORNER);
    mFbo.draw (0, 0);
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
