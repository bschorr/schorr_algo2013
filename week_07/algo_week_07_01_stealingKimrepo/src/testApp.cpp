#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(0);
    //ofSetBackgroundAuto(false);
    //ofEnableBlendMode(OF_BLENDMODE_ADD);
    sprite.loadImage("texture2.png");
    
    for (int i = 0; i < 25000; i++){
        Particle myParticle;
        myParticle.setInitCondition(ofRandom(0,1000), ofRandom(0,1000), 0, 0);
        myParticle.damping = ofRandom(0.01,0.05);
        particles.push_back(myParticle);
        
//        distanceX = particles[i].pos.x - mouseX;
//        distanceY = particles[i].pos.y - mouseY;
//        
//        trans = ofMap(distanceX, 0, 5, 2, 20);
//        particles[i].size = trans;
    }
    
    myFbo.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_RGBA);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
//    for (int i = 0; i < particles.size(); i++){
//        particles[i].resetForce();
//        particles[i].addAttraction(mouseX, mouseY, 1000, 0.05);
//        particles[i].addRepulsion(mouseX, mouseY, 30, 35);
//        particles[i].addDamping();
//        particles[i].update();
//        
//        if (i == 0){
//            particles[i].trail(mouseX, mouseY);
//        }else{
//            particles[i].trail(particles[i-1].pos.x, particles[i-1].pos.y);
//        }
//    
//    }
    
    myFbo.begin();
//    
    ofClear ( 0, 0, 0, 0 );
    
    int i = 0;
    int thisMouseX = mouseX;
    int thisMouseY = mouseY;

    for (vector<Particle>::iterator it = particles.begin(); it != particles.end(); it++){
        
        it -> size = ofDist(thisMouseX, thisMouseY, it->pos.x, it->pos.y);
        it -> size = ofClamp(it->size, 0, 50);
        it -> resetForce();
        it -> addAttraction(thisMouseX, thisMouseY, 1000, 0.02);
        it -> addRepulsion(thisMouseX, thisMouseY, 40, 20);
        it -> addDamping();
        it -> update();
        
        if (i == 0){
            it -> trail(thisMouseX, thisMouseY);
        }else{
            it -> trail(particles[i-1].pos.x, particles[i-1].pos.y);
        }
        
        it -> draw( sprite );
        
        i++;
        
        // iterators look so simple and elegant
    }

    myFbo.end();

}

//--------------------------------------------------------------
void testApp::draw(){
    
//    for (int i = 0; i < particles.size(); i++){
//  
//        particles[i].draw(sprite);
//    }
    
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);
// 
//    for (vector<Particle>::iterator it = particles.begin(); it != particles.end(); it++){
//        it -> draw( sprite );
//    }
    
    ofSetColor(255);
    myFbo.draw(0, 0);

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
