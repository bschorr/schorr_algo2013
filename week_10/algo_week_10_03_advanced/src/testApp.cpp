#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    ofBackground(0);
    
    flocker.addParticle( 500 );
    
    ofEnableDepthTest();
    myCam.setDistance(1000);
}

//--------------------------------------------------------------
void testApp::update(){
    
    flocker.applyForces(80, 0.4, 0.75);
    flocker.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    myCam.begin();
    
    ofPushMatrix();{
//        ofTranslate( ofGetWindowSize() / 2.0 );
        flocker.draw();
    }ofPopMatrix();
    
    myCam.end();
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
    flocker.addParticle( 50 );
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
