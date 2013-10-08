#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    numCircles = 1;
    ofSetBackgroundAuto(false);
    ofBackground(0);
    ofEnableSmoothing();
    
    for ( float i = 0; i < 360; i += numCircles ) {
        
        
        float tempX = ofGetWindowWidth()/2 + 150 * cos(ofDegToRad(i));
        float tempY = ofGetWindowHeight()/2 + 150 * sin(ofDegToRad(i));
        
        circles.push_back(Circle ( ofVec2f (tempX, tempY), 150.0f, 2, i ));
        
        
    }
    
    click = false;
    ofSetLineWidth(1);
    isExporting = false;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for ( int i = 0; i < circles.size(); i++ ) {
    
        circles[i].update();
    
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    

    if (isExporting) {
    
        if (click) {
            click = !click;
            ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
        
        }
        
    }

    //ofSetColor (255);
    ofSetColor(0, 0, 0, 5);
    ofRect ( 0, 0, ofGetWindowWidth(), ofGetWindowHeight() );
    
    //ofSetColor(255);
    
    
    ofColor color;
    float hue = (int(ofGetElapsedTimeMillis())/10)%255;
    
    color.setHsb(hue, 255, 255);
    ofSetColor(color);
    //ofSetColor(0);
     
    for ( int i = 0; i < circles.size(); i++ ) {
        
        circles[i].draw();
        
    }
    
    if (isExporting) ofEndSaveScreenAsPDF();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    click = true;
    
    if (key == '0') {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].degrees = 0;
            
        }
        
    }
    
    if (key == '1') {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].degrees = i * numCircles;
            
        }
        
    }
    
    if (key == '2') {
        
        for ( int i = 0; i < circles.size(); i++ ) {
        
            circles[i].degrees += i * 2 * numCircles;
        
        }

    }
    
    if (key == '3') {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].degrees += i * 3 * numCircles;
            
        }
        
    }
    
    if (key == '4') {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].degrees += i * 4 * numCircles;
            
        }
        
    }
    
    if (key == '5') {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].degrees += i * 5 * numCircles;
            
        }
        
    }
    
    if (key == '6') {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].degrees += i * 6 * numCircles;
            
        }
        
    }
    
    if (key == '7') {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].degrees += i * 7 * numCircles;
            
        }
        
    }
    
    if (key == '8') {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].degrees += i * 8 * numCircles;
            
        }
        
    }
    
    if (key == '9') {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].degrees += i * 9 * numCircles;
            
        }
        
    }
    
    if (key == OF_KEY_UP) {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].speed += 0.01f * i * numCircles;
            
        }
        
    }
    
    if (key == OF_KEY_DOWN) {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].speed -= 0.01f * i * numCircles;
            
        }
        
    }
    
    if (key == OF_KEY_LEFT) {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].degrees += 0.1f * i;
            
        }
        
    }
    
    if (key == OF_KEY_RIGHT) {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].degrees -= 0.1f * i;
            
        }
        
    }
    
    if (key == ' ') {
        
        for ( int i = 0; i < circles.size(); i++ ) {
            
            circles[i].speed = 1;
            
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
