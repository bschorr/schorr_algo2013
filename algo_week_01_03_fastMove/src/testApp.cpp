#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    
    //myRect.pos.x = ofGetWindowWidth() / 2;
    //myRect.pos.y = ofGetWindowWidth() / 2;
    
}

//--------------------------------------------------------------
void testApp::update(){
//    pct += 0.01f;
//    
//    if (pct > 1) {
//        pct = 0;
//    }
//    
//    myRect.interpolateByPct(pct);
//
    myRect.update();
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    myRect.draw();
    ofSetColor(255);
    //ofDrawBitmapString(ofToString(pct), ofPoint (10, 10));

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

    //pct = (float)y / ofGetWindowHeight();
    //myRect.interpolateByPct(pct);

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
