#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    
    //myRect.pos.x = ofGetWindowWidth() / 2;
    //myRect.pos.y = ofGetWindowWidth() / 2;
    
    myRect.posa.x = 10;
    myRect.posa.y = 100;
    
    myRect.posb.x = 500;
    myRect.posb.y = 540;
    
    myRect.interpolateByPct(0.0f);
    
    pct = 0;

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
    myRect.xenoToPoint(mouseX, mouseY);
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    myRect.draw();
    ofSetColor(255);
    ofDrawBitmapString(ofToString(pct), ofPoint (10, 10));

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
