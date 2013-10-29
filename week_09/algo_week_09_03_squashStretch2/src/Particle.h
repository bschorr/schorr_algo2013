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
    
    ofVec2f pos, gravity;
    ofVec2f top, bottom;
    ofVec2f velTop, velBottom;
    float dampingTop, dampingBottom, finalVelBottom;
    int counter;
    ofVec2f size, initSize, finalSize;
    
    bool defineFinalSize;
    
    
};