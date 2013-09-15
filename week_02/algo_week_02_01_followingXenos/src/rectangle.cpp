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


void Rectangle::xenoToPoint(ofVec2f catchUp){
    
    pos.x = catchUpSpeed * catchUp.x + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchUp.y + (1-catchUpSpeed) * pos.y;
    ofVec2f delta = ofVec2f(catchUp.x - pos.x, catchUp.y - pos.y);
    angleInDegrees = atan2(delta.y, delta.x) * 180 / PI;

    
}
