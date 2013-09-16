#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    vector<float> posY;
    
    for (int i = 0; i < 11; i++) {
        
        posY.push_back(sin(ofGetElapsedTimeMillis()/50 + (i * 6)) * 4);
        
    }
    
    ofPushMatrix(); {
        
        ofTranslate (ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    
        ofRect(0, posY[0], 10, 30);
        ofRect(15, posY[1], 10, 40);
        ofRect(30, posY[2], 10, 60);
        ofRect(45, posY[3], 10, 50);
        ofRect(60, posY[4], 10, 40);
        ofRect(75, posY[5], 10, 30);
        ofRect(90, posY[6], 10, 20);
        ofRect(105, posY[7], 10, 30);
        ofRect(120, posY[8], 10, 45);
        ofRect(135, posY[9], 10, 60);

        
    }ofPopMatrix();
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
