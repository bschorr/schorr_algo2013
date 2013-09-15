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
    catchUpSpeed = ofRandom(0.01f, 0.1f);
    
    
}

void Rectangle::update() {
        
}

void Rectangle::draw() {
    
    ofSetColor(color);
    ofRect(pos.x, pos.y, 20, 20);
    
    
}

void Rectangle::xenoToPoint(float catchX, float catchY){
    
    //float catchUpSpeed = 0.03f;
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
}
