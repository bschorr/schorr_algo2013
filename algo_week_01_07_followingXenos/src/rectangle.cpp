//
//  rectangle.cpp
//  algo_week_01
//
//  Created by Bernardo Santos Schorr on 8/27/13.
//
//

#include "rectangle.h"

Rectangle::Rectangle() {
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    catchUpSpeed = 0.2;
    
    
}

void Rectangle::update() {
        
}

void Rectangle::draw() {
    
    ofSetColor(color);
    
    //ofRect(0, 0, 20, 20);
    ofRotate(angleInDegrees);
    ofTriangle(0, 10, 0, -10, 25, 0);
    //float angleInDegrees = atan2(deltaY, deltaX) * 180 / PI
    
}


void Rectangle::xenoToPoint(float catchX, float catchY){
    
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    float deltaY = catchY - pos.y;
    float deltaX = catchX - pos.x;
    angleInDegrees = atan2(deltaY, deltaX) * 180 / PI;

    
}
