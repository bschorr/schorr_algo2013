//
//  Mover.cpp
//  Acceleration
//
//  Created by Bernardo Santos Schorr on 9/8/13.
//  Based in Code by Charlie Whitney
//

#include "Mover.h"

Mover::Mover(float _posx, ofVec2f _vel, float _grav) {
    
    pos.x = _posx;
    pos.y = ofGetWindowHeight();
    
    gravity = _grav;
    velocity = _vel;
    
}

void Mover::update() {
    
    prevPos = pos;
    velocity.y += gravity;
    pos += velocity;
    
    //velocity *= 0.97;
    
}

void Mover::draw() {
    //ofCircle( pos, 1 );
    
    ofSetLineWidth(1);
    
    if (pos != prevPos) {
    ofLine(prevPos, pos);        
    }
    
}

void Mover::explode() {
    
    float angle = ofDegToRad(ofRandom(360));
    float x = cos(angle);
    float y = sin(angle);
    
    float mult = ofRandom(0.0f, 1.5f);

    velocity.set (x*mult, y*mult);    
    
}