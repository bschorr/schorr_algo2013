#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    
    
    for (int i = 0; i < NUM ; i++) {
        
    myRect[i].color = ofColor (i*12);
            
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < NUM ; i++) {

        
        if (i == 0) {
            
        myRect[i].xenoToPoint(mouseX, mouseY);
            
        } else {
            
        myRect[i].xenoToPoint(myRect[i-1].pos.x, myRect[i-1].pos.y);
            
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(255);
    
    for (int i = 0; i < NUM ; i++) {
    
    ofPushMatrix();
    ofTranslate(myRect[i].pos.x, myRect[i].pos.y);
    myRect[i].draw();
        
    ofPopMatrix();
        
    }
    
    ofSetColor(255);

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
