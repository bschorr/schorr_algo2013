//
//  Mover.cpp
//  Acceleration
//
//  Created by Bernardo Santos Schorr on 9/8/13.
//  Based in Code by Charlie Whitney
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
        if (counter < 255) {
            
        counter += 1;
        }
    }
        
        
    ofVec2f accel = (mousePos - pos) * 0.001f;
    velocity += accel;
    
    pos += velocity;
    velocity *= 0.97;
    
    
        
}

void Mover::draw() {
    //ofCircle( pos, 1 );
    
    ofSetColor(counter);
    ofSetLineWidth(1);
    
    if (pos != prevPos) {
    ofLine(prevPos, pos);        
    }
    
}