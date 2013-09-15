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
    
    ofVec2f pos;
    ofColor color;
    
    
    void xenoToPoint (ofVec2f catchUp);
    float catchUpSpeed;
    float angleInDegrees;

    
    
};