#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(0);
    ofDisableBlendMode();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    for (int i = 0; i < 25000; i++){
        Particle myParticle;
        myParticle.setInitCondition(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), 0, 0);
        myParticle.damping = ofRandom(0.01,0.05);
        particles.push_back(myParticle);
        
    }
    
#ifdef TARGET_OPENGLES
    shaderBlurX.load("shadersES2/shaderBlurX");
    shaderBlurY.load("shadersES2/shaderBlurY");
#else
	if(ofIsGLProgrammableRenderer()){
		shaderBlurX.load("shadersGL3/shaderBlurX");
        shaderBlurY.load("shadersGL3/shaderBlurY");
	}else{
		shaderBlurX.load("shadersGL2/shaderBlurX");
        shaderBlurY.load("shadersGL2/shaderBlurY");
	}
#endif
    
    fboBlurOnePass.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_RGBA);
    fboBlurTwoPass.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_RGBA);
    drawParticles.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_RGBA);
}

//--------------------------------------------------------------
void testApp::update(){
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    drawParticles.begin();
    
        ofSetColor (0);
        //ofRect (0, 0, ofGetWindowWidth(), ofGetWindowHeight());
        ofClear (0, 0);
        
        int i = 0;
        int thisMouseX = mouseX;
        int thisMouseY = mouseY;
        
        for (vector<Particle>::iterator it = particles.begin(); it != particles.end(); it++){

            it -> resetForce();
            it -> addAttraction(thisMouseX, thisMouseY, 1000, 0.1);
            it -> addRepulsion(thisMouseX, thisMouseY, 100, 80);
            it -> addDamping();
            it -> update();
            
            if (i == 0){
                it -> trail(thisMouseX, thisMouseY);
            }else{
                it -> trail(particles[i-1].pos.x, particles[i-1].pos.y);
            }
            
            it -> draw( );
            
            i++;
        }
    
    drawParticles.end();
    
    fboBlurOnePass.begin();
    
        ofClear (0, 0);
        
        shaderBlurX.begin();
        shaderBlurX.setUniform1f("blurAmnt", 1.25);
        
        ofSetColor (255);
        drawParticles.draw(0, 0);

        
        shaderBlurX.end();
    
    fboBlurOnePass.end();
    
    fboBlurTwoPass.begin();
    
        ofClear ( 0, 0);
        
        shaderBlurY.begin();
        shaderBlurY.setUniform1f("blurAmnt", 1.25);
        
        ofSetColor(255);
        fboBlurOnePass.draw(0, 0);
        
        shaderBlurY.end();
    
    fboBlurTwoPass.end();

    
    ofSetColor(255);
    fboBlurTwoPass.draw(0, 0);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);

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
