//
//  circle.cpp
//  algo_week_03_01_johnWhitney
//
//  Created by Bernardo Santos Schorr on 9/15/13.
//
//

#include "circle.h"

Circle::Circle (ofVec2f _rotCenter, float _rotRadius, float _circRadius, float _degrees) {
    
    rotCenter = _rotCenter;
    rotRadius = _rotRadius;
    circRadius = _circRadius;
    degrees = _degrees;
    speed = 1;
    
}


void Circle::update() {
    
    prevPos = circlePos;
    
    circlePos.x = rotCenter.x + rotRadius * cos (ofDegToRad( degrees ) );
    circlePos.y = rotCenter.y + rotRadius * sin (ofDegToRad( degrees ) );
    
    degrees += speed;
    
}

void Circle::draw() {

    //ofRect ( circlePos, circRadius, circRadius ) ;
    //ofCircle ( circlePos, circRadius ) ;
    ofLine (prevPos, circlePos);
    
}


