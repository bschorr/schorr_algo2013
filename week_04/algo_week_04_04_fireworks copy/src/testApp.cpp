#include "testApp.h"

//--------------------------------------------------------------

void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();

    //ofSetBackgroundColor (255, 0, 0);
    //ofSetBackgroundAuto(false);
    ofEnableSmoothing();
    shader.load("MotionBlur_GLES.vert", "MotionBlur_GLES.frag");

    ofSetLineWidth(2);
    
    for (int i =0; i < 4; i++){
        fireworks.push_back(Firework());
        
    }
    foo.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_RGBA);

    foo.begin();
    ofClear(0,0,0,0);
    foo.end();

    //shader.load("shaderExample");
}

//--------------------------------------------------------------
void testApp::update(){
    
    float sorting = ofRandom(30);
    
    if (fireworks.size() < 4 && sorting < 1) {
        
        fireworks.push_back(Firework());
        
    }
    
    int counter;
    
    for( vector<Firework>::iterator it=fireworks.begin(); it!=fireworks.end(); ){
        float noise = ofNoise(ofGetElapsedTimef()+ (counter * 100)) * 15.0;
        it->update(noise);
        counter++;
        
        if( it->bIsDead ){
            it = fireworks.erase(it);
            
        }else {
            it++;
        }
    }

    foo.begin();
    
        shader.begin();
        shader.setUniform1f("time", ofGetElapsedTimef());
        shader.setUniform2f("resolution", ofGetWindowWidth(), ofGetWindowHeight());
    
        ofSetColor(0, 0, 0, 10);
        ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
        
        for( vector<Firework>::iterator it=fireworks.begin(); it!=fireworks.end(); ){
            it->draw();
            it++;
        }

        shader.end();
        
    foo.end();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground (4, 5, 6);
    //ofHideCursor();
    
    //ofSaveFrame();
    ofSetColor(255, 255, 255);
    foo.draw( 0, 0 );
 
    
    ofDrawBitmapString (ofToString(ofGetFrameRate()), ofPoint (20, 20));
    
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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