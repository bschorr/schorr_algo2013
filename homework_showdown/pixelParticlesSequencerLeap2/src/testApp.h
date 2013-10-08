#pragma once

#include "ofMain.h"
#include "ofxLeapMotion.h"
#include "Particle.h"
#include "ofxOsc.h"


class testApp : public ofBaseApp{

  public:
    void setup();
    void update();
    void draw();
	
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void exit();
    void oscReceiver();

		
	ofxLeapMotion leap;
	vector <ofxLeapMotionSimpleHand> simpleHands;
    
    float tempX, tempY;
    
    
    //start sequencer variables
    
    
    vector<Particle> particles ;    //vector to store pixels
    int numParticles ;          //Number of particles
    
    //Spring and Sink Factors
    bool springEnabled ;        //toggle whether particles return to their origin
    float forceRadius ;             //radius of repellent/attraction force
    float friction ;                //damping to slow the particles down
    float springFactor ;          //how much the particle "springs" back to origin
    int cursorMode ;
    
    float rotation, prevRotation;
    ofPoint circle;
    float radius;
    
    ofxOscSender sender;
    ofxOscReceiver recvr;
    float inc;
    
    bool play;
    
    ofImage img;
    unsigned char hue;
    unsigned char bri;
    
    float x, y;
    
    bool debugtext;
    
};
