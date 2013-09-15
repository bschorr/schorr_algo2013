//
//  Ball.cpp
//  algo_week_02_03_gravity
//
//  Created by Bernardo Santos Schorr on 9/8/13.
//
//

#include "Ball.h"

Ball::Ball () {
    
    pos.set(ofGetMouseX(), ofGetMouseY());
    //vel.set(ofRandom(-5, 5), 0);
    //vel.set(ofGetPreviousMouseX()-ofGetMouseX(), ofGetPreviousMouseY()-ofGetMouseY());
    
    //cout << vel << endl;
    
    size = 30;
    
    
    
}

void Ball::update() {
    
    vel.y += gravity;
    pos += vel;
    
    if (pos.y > ofGetWindowHeight()-(size)) {
        
        pos.y = ofGetWindowHeight()-(size);
        vel.y *= -0.9;
        
    }
    
    if (pos.x > ofGetWindowWidth() - size) {
        
        pos.x = ofGetWindowWidth() - size;
        vel.x *= -0.5;
        
    }
    
    if (pos.x < size) {
        
        pos.x = size;
        vel.x *= -0.5;
        
    }
    
    
    
}

void Ball::draw() {
    
    
    ofCircle(pos, size);
    
}