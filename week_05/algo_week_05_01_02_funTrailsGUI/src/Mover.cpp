//
//  Mover.cpp
//  Acceleration
//
//  Created by Bernardo Santos Schorr on 9/8/13.
//  Based in Code by Charlie Whitney
//

#include "Mover.h"

Mover::Mover() {
    float angle = ofRandom(360);
    pos = ofGetWindowSize()/2;
    pos.x += cos (ofRadToDeg(angle)) * ofRandomWidth()/2;
    pos.y += sin (ofRadToDeg(angle)) * ofRandomWidth()/2;
    
    velocity.x = ofRandom(-5.0, 5.0);
    velocity.y = ofRandom(-5.0, 5.0);
    
    counter = 0;
}

void Mover::update(float _damping, float _accelMult) {
    
    damping= _damping;
    accelMult = _accelMult;
    
    damping = ofMap( damping, 1, 10, 1.0, 0.9 );
    accelMult = ofMap( accelMult, 1, 10, 0.00001, 0.01);
    
    if (pos != prevPos) {
    prevPos = pos;
        if (counter < 255) {
            
        counter += 1;
        }
    }
        
        
    ofVec2f accel = (mousePos - pos) * accelMult;
    velocity += accel;
    
    pos += velocity;
    velocity *= damping;
    
    
        
}

void Mover::draw() {
    //ofCircle( pos, 1 );
    
    ofSetColor(255);
    ofSetLineWidth(1);
    
    if (pos != prevPos) {
    ofLine(prevPos, pos);        
    }
    
}