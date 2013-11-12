#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    
    myUnicorn.setup();
    mReceiver.setup(12345);
    
    ofBackground(255, 150, 150);
    
    rainbow[0] = ofColor (255, 0, 0);
    rainbow[1] = ofColor (0, 255, 0);
    rainbow[2] = ofColor (0, 0, 255);
    rainbow[3] = ofColor (255, 255, 0);
    rainbow[4] = ofColor (0, 255, 255);
    rainbow[5] = ofColor (255, 0, 255);
    //rainbow[6] = ofColor (0, 0, 0);

}

//--------------------------------------------------------------
void testApp::update(){
    
    //myUnicorn.update();
    checkOsc();
    
//    for ( int i = 0; i < 20; i++ ) {
//        
//        Particle p;
//        checkOsc( p );
//        pList.push_back(p);
//        
//    }
    
    for (int i = 0; i < pList.size(); i++ ) {
        
        pList[i].update();
        
        if (pList[i].pos.y > ofGetWindowHeight()) {
            pList.erase (pList.begin()+i);
        }
        
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix();
    
    ofTranslate(-ofGetWindowWidth(), 0);
    
    for (int i = 0; i < pList.size(); i++ ) {
        pList[i].draw();
    }
    
    myUnicorn.draw();
    
    ofPopMatrix();
    cout << ofGetFrameRate() << endl;

}

//--------------------------------------------------------------

void testApp::checkOsc(){
    
    while ( mReceiver.hasWaitingMessages() ) {
        ofxOscMessage m;
        mReceiver.getNextMessage( &m );
        
        string addr = m.getAddress();
        
        if ( addr == "/unicorn" ) {
            myUnicorn.pos.x = m.getArgAsFloat(0);
        }
        
        else if ( addr == "/particle/new" ) {
            Particle p;
            
            int xPos = m.getArgAsFloat(0);
            int yPos = m.getArgAsFloat(1);
            int xVel = m.getArgAsFloat(2);
            int yVel = m.getArgAsFloat(3);
            int index = m.getArgAsInt32(4);
            
            p.pos.set( xPos, yPos );
            p.vel.set( xVel, yVel );
            p.myColor = rainbow[index];
            
            pList.push_back(p);
            
        }
    
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
