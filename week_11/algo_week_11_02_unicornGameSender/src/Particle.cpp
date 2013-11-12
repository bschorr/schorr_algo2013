//
//  Particle.cpp
//  unicornGame
//
//  Created by Bernardo Santos Schorr on 11/5/13.
//
//

#include "Particle.h"

void Particle::setup( ofVec2f _pos, ofColor &_myColor ) {
    
    pos = _pos;
    vel.y = ofRandom( 2 );
    vel.x = ofRandom( -2, 2 );
    myColor = _myColor;
}

void Particle::update() {
    
    vel.y += 0.2;
    pos += vel;
    
}

void Particle::draw() {
    
    ofSetColor(myColor);
    ofCircle(pos, 3);
    
}