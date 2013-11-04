#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofSetLineWidth(2.0);
    
    for (int i = 0; i < 10; i++) {
        Particle p;
        ofVec2f tempPos;
        tempPos.set(ofRandomWidth(), ofRandomHeight());
        p.setup(tempPos);
        pList.push_back(p);
    }

    myFbo.allocate(ofGetWindowWidth(), ofGetWindowWidth(), GL_RGBA);
    
    myFbo.begin();
        ofClear(0, 0, 0, 0);
    myFbo.end();

}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i<pList.size(); i++) {
        pList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofVec2f center = ofGetWindowSize()/2;
    
    ofSetColor(255, 10);
    ofRect(center, ofGetWindowWidth(), ofGetWindowHeight());
    
    myFbo.begin();
    ofSetColor(0);
        ofClear(0, 0, 0, 0);
        for (int i = 0; i<pList.size(); i++) {
            pList[i].draw();
        }
    myFbo.end();
    
    for (int i = 0; i < 360; i+=5){
        ofPushMatrix();
        ofTranslate(center.x, center.y);
        ofRotate(i);
        myFbo.draw(0, 0);
        ofPopMatrix();
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
