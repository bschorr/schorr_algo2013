#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground (0, 150, 0);
    ofSetBackgroundAuto(false);
    
    initCounter = 12;
    counter = initCounter;
    timer = 0;
    ofSetRectMode (OF_RECTMODE_CENTER);
    gravity.set(0, 0.6, 0);
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            
            int cardNum = (13*i) + j;
            ofPoint pos = ofPoint ((i*120)+550, 100, 0);
            Card tempCard = Card(cardNum, pos);
            cards.push_back(tempCard);
        }
    }
    
    
    drawKings = 4;
    back.loadImage("b2fv.png");
    //ofCircle(100, 100, 300);
    
    //cout << cards.size() << endl;
    //ofSetFrameRate (10);


}

//--------------------------------------------------------------
void testApp::update(){

    cards[counter].update(gravity);
    
    timer++;
    cout << initCounter << endl;
    
    if (initCounter >= 0) {
    
    if (cards[counter].pos.x > ofGetWindowWidth() || cards[counter].pos.x < 0 || cards[counter].pos.y > ofGetWindowHeight() || cards[counter].pos.y < 0 ) {
        
        counter += 13;
        
//        if ( counter > cards.size() ) {
//            initCounter --;
//            counter = initCounter;
//        }
//        
    }
    }
    
    if (timer >= 180) {
        counter += 13;
        timer = 0;
        
        if ( counter > cards.size() ) {
            initCounter --;
            counter = initCounter;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    if (drawKings > 0) {
        for (int i = cards.size()-1; i > 0; i-=13) {
            cards[i].draw(back);
        }
        drawKings --;
    }
    
    cards[counter].draw(back);

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
