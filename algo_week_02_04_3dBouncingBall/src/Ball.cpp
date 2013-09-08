//
//  Ball.cpp
//  algo_week_02_02
//
//  Created by Bernardo Santos Schorr on 9/3/13.
//
//

#include "Ball.h"

Ball::Ball() {
    
    ofSeedRandom();
    
    xVelocity = ofRandom(0.0, 1.0);
    yVelocity = ofRandom(0.0, 1.0);
    zVelocity = ofRandom(0.0, 1.0);
    
    pos.x = ofGetWindowWidth() * 0.5;
    pos.y = ofGetWindowHeight() * 0.5;
    pos.z = ofGetWindowHeight() * 0.5;
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    
}

void Ball::update() {
    
    pos.x += xVelocity * 10.0;
    pos.y += yVelocity * 10.0;
    pos.z += zVelocity * 10.0;
    
    if (pos.x < 0 || pos.x > boxSize) {
        
        
        xVelocity *= -1;
        
    }
    
    if (pos.y < 0 || pos.y > boxSize) {
        
        yVelocity *= -1;
        
    }
    
    if (pos.z < 0 || pos.z > boxSize) {
        
        zVelocity *= -1;
        
    }
    
}

void Ball::draw() {
    
    ofFill();
    
    ofSetColor(0, 0, 255);
    ofSetLineWidth (5);
    ofDrawSphere (pos.x, pos.y, pos.z, 20);
    
    ofSetColor(255, 0, 0, 100);
    ofDrawBox(boxSize/2, boxSize/2, boxSize/2, boxSize, boxSize, boxSize);
    
    ofSetColor(255, 0, 0);
    ofNoFill();
    ofSetLineWidth (5);
    ofDrawBox(boxSize/2, boxSize/2, boxSize/2, boxSize, boxSize, boxSize);
    
}