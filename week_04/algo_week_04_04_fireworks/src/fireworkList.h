//
//  fireworkList.h
//  algo_week_04_04_fireworks
//
//  Created by Bernardo Santos Schorr on 9/23/13.
//
//

#pragma once

#include "ofMain.h"
#include "Mover.h"

class Firework {
public:
    
    Firework();
    void update();
    void draw();
    
    vector <Mover> moverList;
    ofVec2f vel;
    float posX;
    ofVec2f accel;
    bool exploded;
    bool bIsDead;
    float dieCount;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};