#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    myField.setup( 1000, 1000, 1000, 50 );
    myField.setPerlin();
    
    particleList.clear();
    
    for( int i=0; i<100000; i++ ){
        addParticle();
    }
    
    ofBackground (0);
    
}

void testApp::addParticle() {
        Particle part;
        part.pos = ofVec3f( ofRandom(myField.width), ofRandom(myField.height), ofRandom(myField.depth) );
        
        particleList.push_back( part );
    }
    
//--------------------------------------------------------------
void testApp::update(){
    //myField.update();
    
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].applyForce( myField.getForceAtPosition(particleList[i].pos ) * 0.005 );
        particleList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    myCam.begin();
    
    ofPushMatrix(); {
        ofTranslate(myField.width*0.5*-1, myField.height*0.5*-1, myField.depth*0.5*-1);
    
        //myField.draw();
        for( int i=0; i<particleList.size(); i++ ){
            particleList[i].draw();
        }
    
    } ofPopMatrix();
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
