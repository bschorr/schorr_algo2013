#include "testApp.h"

static int pts[] = {257,219,257,258,259,274,263,325,266,345,266,352,269,369,276,387,286,415,291,425,302,451,308,462,316,472,321,480,328,488,333,495,339,501,345,505,350,507,365,515,370,519,377,522,382,525,388,527,405,534,426,538,439,539,452,539,468,540,485,540,496,541,607,541,618,539,625,537,641,530,666,513,682,500,710,476,723,463,727,457,729,453,732,450,734,447,738,440,746,423,756,404,772,363,779,343,781,339,784,327,789,301,792,278,794,267,794,257,795,250,795,232,796,222,796,197,797,195,797,188,796,188};
static int nPts  = 61*2;

//--------------------------------------------------------------
void testApp::setup() {
	ofSetVerticalSync(true);
	ofBackgroundHex(0xfdefc2);
	ofSetLogLevel(OF_LOG_NOTICE);
	
	bMouseForce = false;
	
	box2d.init();
	box2d.setGravity(0, 0);
    box2d.createBounds();
	box2d.setFPS(30.0);
    //box2d.
	
	// lets add a contour to start
	
	// make the shape
	
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    myField.setGravity();
    showField = true;
    showText = true;
    
    for ( int i = 0; i < 500; i ++ ) {
        float r = ofRandom(5, 10);		// a random radius 4px - 20px
		CustomParticle p;
		p.setPhysics(5, 0.53, 0.31);
		p.setup(box2d.getWorld(), ofRandom(ofGetWindowWidth()), ofRandom(50), r);
		p.color.r = ofRandom(20, 100);
		p.color.g = 0;
		p.color.b = ofRandom(150, 255);
		customParticles.push_back(p);
    }
	
}

//--------------------------------------------------------------
void testApp::update() {
	
    myField.update();
	box2d.update();
	
	for( int i=0; i<customParticles.size(); i++ ){
        ofVec2f tempForce = myField.getForceAtPosition(customParticles[i].getPosition());
        customParticles[i].addForce( tempForce, 0.05 );
    }
    
//    
//	if(bMouseForce) {
//		float strength = 8.0f;
//		float damping  = 0.7f;
//		float minDis   = 100;
//		for(int i=0; i<circles.size(); i++) {
//			circles[i].addAttractionPoint(mouseX, mouseY, strength);
//			circles[i].setDamping(damping, damping);
//		}
//		for(int i=0; i<customParticles.size(); i++) {
//			customParticles[i].addAttractionPoint(mouseX, mouseY, strength);
//			customParticles[i].setDamping(damping, damping);
//            //customParticles[i].get
//            customParticles[i].addForce(<#ofVec2f frc#>, <#float scale#>);
//		}
//		
//	}
	
}


//--------------------------------------------------------------
void testApp::draw() {
    
    ofBackground(255);
	
	for(int i=0; i<customParticles.size(); i++) {
		customParticles[i].draw();
	}
	
	ofNoFill();
	ofSetHexColor(0x444342);

	
	if ( showText ) {
	string info = "";
	info += "Press [t] to toggle text visibility\n";
	info += "Press [z] to add a particle\n";
    info += "Press [f] to toggle field visibility\n";
	info += "Total Bodies: "+ofToString(box2d.getBodyCount())+"\n";
	info += "FPS: "+ofToString(ofGetFrameRate())+"\n";
	ofSetHexColor(0x444342);
	ofDrawBitmapString(info, 30, 30);
    }
        
    if (showField) {
    myField.draw();
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
	
	if(key == 't' || key == 'T') {
		showText = !showText;
	}
	
	if(key == 'z' || key == 'Z') {
		float r  = ofRandom(5, 10);		// a random radius 4px - 20px
		CustomParticle p;
		p.setPhysics(5, 0.53, 0.31);
		p.setup(box2d.getWorld(), mouseX, mouseY, r);
		p.color.r = ofRandom(20, 100);
		p.color.g = 0;
		p.color.b = ofRandom(150, 255);
		customParticles.push_back(p);
	}
    
    if ( key == 'f' || key == 'F') {
        showField = !showField;
    }
	
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
    ofVec2f dir = ofVec2f ( ofGetMouseX() - ofGetPreviousMouseX(), ofGetMouseY() - ofGetPreviousMouseY());
    
    if( button == OF_MOUSE_BUTTON_1 ){
        myField.addLinearForce(x, y, dir, 100);
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::resized(int w, int h){
	
}

