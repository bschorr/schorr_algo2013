//
//  circle.h
//  algo_week_03_01_johnWhitney
//
//  Created by Bernardo Santos Schorr on 9/15/13.
//
//

#pragma once

#include "ofMain.h"


class Circle {
    
public:
    
    Circle();
    Circle (ofVec2f _rotCenter, float _rotRadius, float _circRadius, float _degrees);
    
    ofVec2f circlePos;
    ofVec2f prevPos;
    ofVec2f rotCenter;
    float circRadius;
    float rotRadius;
    float degrees;
    
    void update ();
    void draw ();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};
