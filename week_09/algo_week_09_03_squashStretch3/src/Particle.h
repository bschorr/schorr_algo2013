//
//  Particle.h
//  algo_week_09_03_squashStretch2
//
//  Created by Bernardo Santos Schorr on 10/28/13.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    void setup(ofVec2f &initPos);
    void update();
    void draw();
    
    ofVec2f pos, gravity, vel;
    ofVec2f size, initSize, finalSize;
    
    float sizeYMult;
    
    //bool defineFinalSize;
    bool reached;
    float mult;
    
};