//
//  Particle.h
//  unicornGame
//
//  Created by Bernardo Santos Schorr on 11/5/13.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    void setup ( ofVec2f _pos, ofColor &_myColor );
    void update();
    void draw ();
    
    ofVec2f pos, vel;
    ofColor myColor;
    
};
