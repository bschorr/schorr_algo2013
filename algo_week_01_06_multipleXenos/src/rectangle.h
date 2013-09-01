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
    ofColor color;
        
    void xenoToPoint (float catchX, float catchY);
    float catchUpSpeed;
    
    
    
};