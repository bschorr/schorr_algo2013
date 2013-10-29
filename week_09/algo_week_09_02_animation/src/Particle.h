//
//  Particle.h
//  algo_week_09_02_animation
//
//  Created by Bernardo Santos Schorr on 10/28/13.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    void setup(ofVec2f _pos, ofVec2f _dest);
    void update(int i, int &countOne, int &countTwo);
    void draw();
    
    
    ofVec2f prevPos, pos, vel, dest, size;
    float xenoRandomPos, xenoRandomDest;
    
    ofColor color;
    
    bool triggerOne, triggerTwo, triggerThree;;
    
    
};