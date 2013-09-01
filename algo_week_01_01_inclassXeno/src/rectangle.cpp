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

void Rectangle::update() {
    
  //  pos.x = pos.x + ofRandom(-10, 10);
    
}

void Rectangle::draw() {
    
    ofSetColor(255, 255, 255);
    ofRect(pos.x, pos.y, 20, 20);
    
    
}

void Rectangle::interpolateByPct (float myPct) {
    
    //pct = myPct;
    
    pct = powf(myPct, 2);
    
    pos.x = (1-pct) * posa.x + pct * posb.x;
    pos.y = (1-pct) * posa.y + pct * posb.y;
}

void Rectangle::xenoToPoint(float catchX, float catchY){
    
    float catchUpSpeed = 0.03f;
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
}
