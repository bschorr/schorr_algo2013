#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    
    //myRect.pos.x = ofGetWindowWidth() / 2;
    //myRect.pos.y = ofGetWindowWidth() / 2;
    
    for (int i = 0; i < NUM ; i++) {
    
    myRect[i].posa.x = 10;
    myRect[i].posa.y = 100;
    
    myRect[i].posb.x = 500;
    myRect[i].posb.y = 540;
    
    myRect[i].interpolateByPct(0.0f);
        
    myRect[i].color = ofColor (ofRandom(255), ofRandom(255), ofRandom(255));
    
    pct = 0;
        
    }
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
