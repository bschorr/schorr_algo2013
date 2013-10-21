#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "FlowField.h"

// ------------------------------------------------- a simple extended box2d circle
class CustomParticle : public ofxBox2dCircle {
	
public:
	CustomParticle() {
	}
	ofColor color;
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f accel;
    float mass = 1.0;
    
    void applyForce(ofVec2f force){
        accel += (force / mass);
    }
	void draw() {
		float radius = getRadius();
		
		glPushMatrix();
		glTranslatef(getPosition().x, getPosition().y, 0);
		
		ofSetColor(color.r, color.g, color.b);
		ofFill();
		ofCircle(0, 0, radius);	
		
		glPopMatrix();
		
	}
    
//    void update(){
//        vel += accel;
//        this->setVelocity(vel.x, vel.y);
//        
//        if (this->getPosition().y > ofGetWindowHeight()-this->getRadius()) {
//            
//            this->setPosition(this->getPosition().x, ofGetWindowHeight() - this->getRadius());
//            vel *= -0.1;
//            
//        }
//        
//        pos += vel;
//        vel *= 0.97;
//        accel.set(0);
//        
//    }
};


// -------------------------------------------------
class testApp : public ofBaseApp {
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void resized(int w, int h);
	
	float							px, py;
	bool							bDrawLines;
	bool							bMouseForce;
	
	ofxBox2d						box2d;			  //	the box2d world
	vector		<ofxBox2dCircle>	circles;		  //	default box2d circles
	vector		<ofxBox2dRect>		boxes;			  //	defalut box2d rects
	vector		<CustomParticle>	customParticles;  //	this is a custom particle the extends a cirlce
    FlowField           myField;
    bool showField;
    bool showText;
	
	
};
