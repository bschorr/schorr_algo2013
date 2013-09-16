#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void testApp::update(){
    
    myFish.update();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);
    
    myFish.draw();
    
    vector<float> posY;
    float tempMult = ofMap (mouseY, 0, ofGetWindowHeight(), 0, 1);
    sinMult += tempMult;
    
    ofPushMatrix(); {
        
        ofTranslate (ofGetWindowWidth()/2, ofGetWindowHeight()/2);
        
        for ( float i = 0.0f; i < 1.3; i += 0.1 ) {
            
            float rectH = abs (sin (i * PI) * 30);
            if ( rectH < 5 ) rectH = 5;
            
            float motionMult = ofMap(i, 0, 1.3, 0.4, 1);
            
            float posY = sin(sinMult + (1.3 - i)) * 4 * motionMult;
            
            
            ofRect((i * 50), posY, 3, rectH);
            
            
        }

        
    }ofPopMatrix();
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
