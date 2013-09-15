#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    
    myRect.posa.x = 10;
    myRect.posa.y = 100;
    
    myRect.posb.x = 500;
    myRect.posb.y = 540;
    

}

//--------------------------------------------------------------
void testApp::update(){

    myRect.xenoToPoint(mouseX, mouseY);
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(255, 255, 255);
    myRect.draw();
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
