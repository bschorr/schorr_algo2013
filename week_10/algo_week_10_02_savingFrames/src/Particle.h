//
//  Particle.h
//  algo_week_10_01_moreParticlesThanTheEyeCanSee
//
//  Created by Bernardo Santos Schorr on 11/4/13.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    void setup( ofVec2f &_pos );
    void update();
    void draw();
    
    ofVec2f prevPos, pos, vel, acc;
    
    
};