#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i =0; i < balls.size(); i++) {
        
        balls[i].update();
        
    }
    

}

//--------------------------------------------------------------
void testApp::draw(){

    for (int i =0; i < balls.size(); i++) {
        
        balls[i].draw();
        
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

    Ball newBall;
    balls.push_back(newBall);
    
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
