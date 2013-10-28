#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSeedRandom();
    
    
    for (int i =0; i < 6; i++) {
        
        ofVec2f pos;
        
        pos.x = ofRandom(ofGetWindowWidth());
        pos.y = ofRandom(ofGetWindowHeight());
        
        Particle tempCar;
        tempCar.setParams( pos, ofVec2f(10, -5) );
        tempCar.dest.set( ofRandomWidth(), ofRandomHeight() );
        cars.push_back(tempCar);
    }
    
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < cars.size(); i++) {
    
        for (int j = 0; j < cars.size(); j++) {
            if (i != j && cars[i].pos.distance(cars[j].pos) < 200.0) {
                cars[i].avoid(cars[j]);
            }
        }
        
        cars[i].seek();
        cars[i].update(cars[i]);
        
        if( cars[i].pos.distance(cars[i].dest) < 5){
            cars[i].dest = ofVec2f( ofRandomWidth(), ofRandomHeight() );
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < cars.size(); i++) {
        
        ofSetColor(255);
        cars[i].draw();
        
        ofSetColor(255,0,0);
        ofCircle( cars[i].dest, 4 );
        
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
