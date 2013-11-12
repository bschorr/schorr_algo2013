#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    
    myUnicorn.setup();
    mSender.setup("localhost", 12345);
    
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
    
    myUnicorn.update();
    
    ofxOscMessage m2;
    m2.setAddress("/unicorn");
    m2.addFloatArg(myUnicorn.pos.x);
    mSender.sendMessage( m2 );
    
    for ( int i = 0; i < 20; i++ ) {
        
        int index = floor(ofRandom(6));
        Particle p;
        p.setup( myUnicorn.pos, rainbow[index]);
        pList.push_back(p);
        
        ofxOscMessage m;
        
        m.setAddress("/particle/new");
        m.addFloatArg(p.pos.x);
        m.addFloatArg(p.pos.y);
        m.addFloatArg(p.vel.x);
        m.addFloatArg(p.vel.y);
        m.addIntArg(index);
        
        mSender.sendMessage( m );

        
    }
    
    for (int i = 0; i < pList.size(); i++ ) {
        
        pList[i].update();
        
        if (pList[i].pos.y > ofGetWindowHeight()) {
            pList.erase (pList.begin()+i);
        }
        
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < pList.size(); i++ ) {
        pList[i].draw();
    }
    
    myUnicorn.draw();
    
    cout << ofGetFrameRate() << endl;

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
