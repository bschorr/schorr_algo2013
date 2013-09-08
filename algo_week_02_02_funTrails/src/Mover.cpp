//
//  Mover.cpp
//  Acceleration
//
//  Created by Charlie Whitney on 9/2/13.
//
//

#include "Mover.h"

Mover::Mover() {
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    
    velocity.x = ofRandom(-5.0, 5.0);
    velocity.y = ofRandom(-5.0, 5.0);
    
    counter = 0;
}

void Mover::update() {
    
    if (pos != prevPos) {
    prevPos = pos;
    counter += 1;
    }
        
        
    if (ofDist(pos.x, pos.y, mousePos.x, mousePos.y) < 500) {
    ofVec2f accel = (mousePos - pos) * 0.001f;
    velocity += accel;
    
    pos += velocity;
    velocity *= 0.97;
        
    }
    
    
        
}

void Mover::draw() {
    //ofCircle( pos, 1 );
    
    ofSetColor(counter);
    ofSetLineWidth(1);
    
    if (pos != prevPos) {
    ofLine(prevPos, pos);        
    }
    
}