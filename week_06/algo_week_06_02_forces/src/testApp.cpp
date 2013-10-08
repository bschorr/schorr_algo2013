#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 1000; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(-500, 500),ofRandom(-500, 500), ofRandom(-500, 500),0,0,0);
		// more interesting with diversity :)
		// uncomment this: 
		//myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
	}
    
    camPos.set (0, 0, 500);
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		
		
		particles[i].addAttractionForce(camPos.x, camPos.y, camPos.z, 1000, 0.2);
		particles[i].addRepulsionForce(camPos.x, camPos.y, camPos.z, 60, 1);
		
		
//		particles[i].addCounterClockwiseForce(mouseX, mouseY, 1000, 0.1);
//		particles[i].addClockwiseForce(mouseX, mouseY, 200, 1);
		
		//particles[i].addForce(0,0.04);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}

}

//--------------------------------------------------------------
void testApp::draw(){
    
    light.enable();
    cam.begin();
    
    cam.setPosition( camPos );
	ofSetColor(0x000000);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}

    cam.end();
    light.disable();
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    
    switch (key) {
        case 'w':
            camPos.y += 10;
            break;
        case 's':
            camPos.y -= 10;
            break;
        case 'a':
            camPos.x -= 10;
            break;
        case 'd':
            camPos.x += 10;
            break;
            
        case OF_KEY_UP:
            camPos.z += 10;
            break;

        case OF_KEY_DOWN:
            camPos.z -= 10;
            break;
            
        default:
            break;
    }
    
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
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
void testApp::mouseReleased(){
}
