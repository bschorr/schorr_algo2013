#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetSmoothLighting(true);
    //myMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    counter = 1;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            
            float tempNoise = ofNoise(counter*i*0.02, counter*j*0.02);
            ofVec3f tempVec = ofVec3f (i*5, j*5, tempNoise*100);
            myMesh.addVertex(ofPoint(i*50, j*50, tempNoise*100));
            myMesh.addColor(1.0);
            myPoints.push_back(tempVec);
            
        }
    }
    
    for (int y = 0; y<10-1; y++){
		for (int x=0; x<10-1; x++){
			myMesh.addIndex(x+y*10);				// 0
			myMesh.addIndex((x+1)+y*10);			// 1
			myMesh.addIndex(x+(y+1)*10);			// 10
			
			myMesh.addIndex((x+1)+y*10);			// 1
			myMesh.addIndex((x+1)+(y+1)*10);		// 11
			myMesh.addIndex(x+(y+1)*10);			// 10
		}
	}
    
    light.setPointLight();
    
    
    
//    myMesh.addVertex(ofVec3f(-50, -50, 0));
//    myMesh.addVertex(ofVec3f( 50, -50, 0));
//    myMesh.addVertex(ofVec3f(-50,  50, 0));
//    myMesh.addVertex(ofVec3f( 50,  50, 0));
//    
//    myMesh.addIndex(0);
//    myMesh.addColor(255);
//    
//    myMesh.addIndex(1);
//    myMesh.addColor(255);
//    
//    myMesh.addIndex(2);
//    myMesh.addColor(255);
//    
//    myMesh.addIndex(3);
//    myMesh.addColor(255);
    

}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            float tempNoise = ofNoise((i*0.2) + counter, (j*0.2));
            ofVec3f tempVec = ofVec3f (i*50, j*50, tempNoise*100);
            myMesh.setVertex((i*10) + j, tempVec);
        }
    }
    
    //ofPushMatrix();
    
    glEnable(GL_DEPTH_TEST);
    ofEnableLighting();
    light.enable();
    
    cam.begin();
    ofTranslate(-250, -250);
    myMesh.draw();
    
    cam.end();
    
    ofDisableLighting();
    glDisable(GL_DEPTH_TEST);
    
    
    
    //ofPopMatrix();
    
    counter += 0.02;
    
    

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    ofTranslate(-250, -250);
    light.setPosition(x, y, 100);

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
