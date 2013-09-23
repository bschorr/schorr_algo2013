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
    Mover(float _posx, ofVec2f _vel, float _grav);
    
    void update();
    void draw();
    void explode();
    
    ofPoint     pos, mousePos;
    ofPoint     prevPos;
    ofVec2f     velocity, accel;
    float       gravity;
    
};