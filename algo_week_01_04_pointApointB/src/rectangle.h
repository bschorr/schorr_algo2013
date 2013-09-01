//
//  rectangle.h
//  algo_week_01
//
//  Created by Bernardo Santos Schorr on 8/27/13.
//
//

#pragma once

#include "ofMain.h"

class Rectangle {
    
public:
    
    Rectangle();
    void setPos(int x, int y);
    void draw();
    void update();
    
    ofPoint finalPos;
    ofPoint pos;
    float pct;
    
    void interpolateByPct (float myPct);
    
    void xenoToPoint (float catchX, float catchY);
    
    
    
};