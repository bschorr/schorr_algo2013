//
//  Mover.h
//  Acceleration
//
//  Created by Bernardo Santos Schorr on 9/8/13.
//  Based in Code by Charlie Whitney
//

#pragma once

#include "ofMain.h"

class Mover {
  public:
    Mover();
    
    void update();
    void draw();
    
    ofPoint     pos, mousePos;
    ofPoint     prevPos;
    ofVec2f     velocity, accel;
    
    int counter;
};