#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    //ofBackground( 100 );
    
    ofBackground(0);
    //ofEnableBlendMode (OF_BLENDMODE_ADD);
    //CGDisplayHideCursor(0);
    ofSetBackgroundAuto(false);
    ofEnableSmoothing();
    ofHideCursor();
    ofEnableAlphaBlending();
    
    fireworks.push_back(Firework());
    
}

//--------------------------------------------------------------
void testApp::update(){
        
        
    fireworks[0].update();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    //ofHideCursor();
    
    //ofSaveFrame();
    
    ofSetColor(0, 0, 0, 10);
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    for( int i=0; i<fireworks.size(); i++ ){
        fireworks[i].draw();
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
