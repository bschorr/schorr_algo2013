//
//  Ball.h
//  algo_week_02_03_gravity
//
//  Created by Bernardo Santos Schorr on 9/8/13.
//
//

#pragma once
#include "ofMain.h"
//#include "testApp.h"


class Ball {
    
public:
    
    Ball ();
    void update ();
    void draw ();
    
    float size;
    ofVec2f pos;
    ofVec2f vel;
    float gravity = _GRAVITY;
    
    
};

