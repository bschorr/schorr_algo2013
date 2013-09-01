#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    
    myRect.setPos (256, 384);
    myOtherRect.setPos (768, 384);
    
    which = true;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    myRect.xenoToPoint(myRect.finalPos.x, myRect.finalPos.y);
    myOtherRect.xenoToPoint(myOtherRect.finalPos.x, myOtherRect.finalPos.y);

    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    myRect.draw();
    myOtherRect.draw();
    ofSetColor(255);
    ofLine(myRect.pos.x, myRect.pos.y, myOtherRect.pos.x, myOtherRect.pos.y);

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
    
    if (which){
    
    myRect.xenoToPoint(x, y);
    which = !which;
        
    } else {
        
    myOtherRect.xenoToPoint(x, y);
    which = !which;
        
    }
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
