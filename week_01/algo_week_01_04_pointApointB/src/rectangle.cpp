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
    
}

void Rectangle::setPos(int x, int y) {
    
    pos.x = x;
    pos.y = y;
    
    finalPos = pos;
    
}

void Rectangle::update() {
    

    
}

void Rectangle::draw() {
    
    ofSetColor(255, 255, 255);
    ofRect(pos.x, pos.y, 20, 20);
    
}

void Rectangle::xenoToPoint(float catchX, float catchY){
    
    finalPos.set (catchX, catchY);
    
    float catchUpSpeed = 0.03f;
    pos.x = catchUpSpeed * finalPos.x + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * finalPos.y + (1-catchUpSpeed) * pos.y;
    
}