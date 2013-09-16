//
//  fish.h
//  algo_week_03_03_creature
//
//  Created by Bernardo Santos Schorr on 9/16/13.
//
//

#pragma once

#include "ofMain.h"

class Fish {
    
public:
    
    Fish();
    Fish( ofPoint _pos, float _size, float _speed);
    
    void update ();
    void draw ();
    
    ofPoint pos;
    float size;
    float sinMult;
    float speed;
    
    vector<float> rectH;
    vector<float> posY;
    
};
