#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    //ofEnableAlphaBlending();
    ofBackground( 0 );
    
    pos.set(ofRandomWidth(), ofRandomHeight());
    
    //GUI Settings
    
    /*
     
     Some cool values for Damping, Acceleration and Explosion, respectively:
     
     1.5 / 1.5 / 10
     1.5 / 5.0 / 50
     1.0 / 6.5 / 3
     
     */
    
    gui = new ofxUICanvas;
    gui->addLabel("Particle Controller");
    gui->addSpacer();
    gui->addButton("Explode", false, 44, 44);
    
    gui->setColorBack(ofColor(100, 100));
    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255, 100));
    gui->addSlider("Damping", 1, 10, 5);
    gui->addSlider("Acceleration", 1, 10, 3);
    gui->addSlider("Explosion", 0, 50, 10);
    
    ofAddListener(gui->newGUIEvent,this,&testApp::onGuiEvent);
    gui->loadSettings("guiSettings.xml");

    
    for( int i=0; i<200; i++){
        Mover myMover;
        moverList.push_back( myMover );
    }
    
    //ofEnableBlendMode (OF_BLENDMODE_ADD);
    //CGDisplayHideCursor(0);
    ofSetBackgroundAuto(false);
    ofEnableSmoothing();
    ofHideCursor();
    
}

void testApp::exit() {
    gui->saveSettings("guiSettings.xml");
    delete gui;
}

void testApp::onGuiEvent(ofxUIEventArgs &e) {
    
    
    string name = e.widget->getName();
	int kind = e.widget->getKind();
    
    if( name == "Damping" ){
        ofxUISlider *mySlider = (ofxUISlider *)e.widget;
        damping = mySlider->getScaledValue();
        
        cout << "Got a message! " << name << " - " << mySlider->getValue() << endl;
        
    }else if( name == "Acceleration" ){
        ofxUISlider *mySlider = (ofxUISlider *)e.widget;
        acceleration = mySlider->getScaledValue();
        
        cout << "Got a message! " << name << " - " << mySlider->getValue() << endl;
        
    }else if( name == "Explosion" ){
        ofxUISlider *mySlider = (ofxUISlider *)e.widget;
        multiplier = mySlider->getScaledValue();
        
        cout << "Got a message! " << name << " - " << mySlider->getValue() << endl;
        
    }else if( name == "Explode"){
        
        ofxUIButton *myButton = (ofxUIButton *)e.widget;
        
        if( myButton->getValue() == 0){
            for (int i = 0; i < moverList.size(); i++) {
                
                float angle = ofDegToRad(ofRandom(360));
                float x = cos(angle);
                float y = sin(angle);
                
                float mult = ofRandom(0.0f, multiplier);
                //float mult = 10.0f;
                
                moverList[i].velocity.set (x*mult, y*mult);
                
            }
        }
    }
    
    
    //    cout << "Got a message! " << name  << " - " << kind << endl;
}


//--------------------------------------------------------------
void testApp::update(){

    for( int i=0; i<moverList.size(); i++ ){
        moverList[i].mousePos.x = pos.x;
        moverList[i].mousePos.y = pos.y;
        
        moverList[i].update( damping, acceleration);
    }
    
    pos.x = ofNoise(ofGetElapsedTimef()/2)*ofGetWidth();
    pos.y = ofNoise(ofGetElapsedTimef()/2+1000)*ofGetHeight();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //ofHideCursor();
    
    //ofSaveFrame();
    
    ofSetColor(0, 0, 0, 10);
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    for( int i=0; i<moverList.size(); i++ ){
        moverList[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == ' '){
        
        for (int i = 0; i < moverList.size(); i++) {
            
            float angle = ofDegToRad(ofRandom(360));
            float x = cos(angle);
            float y = sin(angle);
            
            float mult = ofRandom(0.0f, 10.0f);
            //float mult = 10.0f;
            
            moverList[i].velocity.set (x*mult, y*mult);
                        
        }
    }
    
    if (key == 'g' || key == 'G') {

        gui->toggleVisible();

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
