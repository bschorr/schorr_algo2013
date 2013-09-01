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
    void draw();
    void update();
    
    ofPoint pos;
    ofPoint posa;
    ofPoint posb;
    float pct;
    ofColor color;
    
    void interpolateByPct (float myPct);
    
    void xenoToPoint (float catchX, float catchY);
    float catchUpSpeed;
    
    
    
};