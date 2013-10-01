#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate (30);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    img.loadImage("texture2.png");
    
    for ( int i = 0; i < 100; i++) {
        
        ants.push_back(Ant());
        
    }

}

//--------------------------------------------------------------
void testApp::update(){
    
    std::vector<Ant>::iterator p ;
    for ( p = ants.begin() ; p != ants.end() ; p++ ){
        
        p->update( ants );
        
    }
    
    cout << ofGetFrameRate() << endl;

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);
    
    std::vector<Ant>::iterator p ;
    for ( p = ants.begin() ; p != ants.end() ; p++ ) {
        
        ofSetColor(p->color);
        p->draw( img );
        
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
