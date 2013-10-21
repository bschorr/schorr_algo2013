#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    myField.setGravity();
    
    particleList.clear();
    
    //ofBackground(0);
    
    counter = 0;
    showField = true;
}

void testApp::addParticle() {
    Particle part;
    ofVec2f origin;
    origin.set(ofGetWindowWidth()/2, 50);
    part.pos = origin;
    part.vel.set(ofRandom (-3.0, 3.0), ofRandom(-1, -3));
    
    particleList.push_back( part );
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < 20; i++) {
    addParticle();
    }
    counter = 0;
    myField.update();
    
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].applyForce( myField.getForceAtPosition(particleList[i].pos ) * 0.005 );
        particleList[i].update();
        if (particleList[i].pos.x > ofGetWindowWidth() || particleList[i].pos.x < 0 || particleList[i].pos.y > ofGetWindowHeight() || particleList[i].pos.y < 0 ) {
            particleList.erase (particleList.begin()+i);
        }
    }
    
    counter ++;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackgroundGradient(ofColor (150, 230, 255), ofColor(50, 100, 130), OF_GRADIENT_CIRCULAR);
    
    ofSetColor(255);
    if (showField) {
     
        myField.draw();
        ofDrawBitmapString("'s' toggles field visibility", 20, 20);
    }
    
    ofSetColor(0, 255, 255);
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if ( key == 's' || key == 'S') {
        showField = !showField;
    }
    else if( key == 'r' ){
        for( int i=0; i<particleList.size(); i++ ){
            particleList[i].pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );
        }
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    ofVec2f dir = ofVec2f ( ofGetMouseX() - ofGetPreviousMouseX(), ofGetMouseY() - ofGetPreviousMouseY());
    
    if( button == OF_MOUSE_BUTTON_1 ){
        myField.addLinearForce(x, y, dir, 100);
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    mouseDragged(x, y, button);
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
