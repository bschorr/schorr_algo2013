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
    
    pos.x = ofGetWindowWidth() * 0.5;
    pos.y = ofGetWindowHeight() * 0.5;
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    
}

void Ball::update() {
    
    pos.x += xVelocity * 10.0;
    pos.y += yVelocity * 10.0;
    
    if (pos.x < 0 || pos.x > ofGetWindowWidth()) {
        
        
        xVelocity *= -1;
        
    }
    
    if (pos.y < 0 || pos.y > ofGetWindowHeight()) {
        
        yVelocity *= -1;
        
    }
    
}

void Ball::draw() {
    
    ofSetColor(0, 0, 255);
    ofCircle(pos.x, pos.y, 20);
    
}