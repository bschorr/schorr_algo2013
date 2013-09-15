//
//  rectangle.cpp
//  algo_week_01
//
//  Created by Bernardo Santos Schorr on 8/27/13.
//
//

#include "rectangle.h"

Rectangle::Rectangle() {
    
    //ofSetRectMode(OF_RECTMODE_CENTER);
    pos.x = 0;
    pos.y = ofGetWindowHeight() / 2;
    
}

void Rectangle::update() {
    
  if (pos.x <= ofGetWidth()){
  
    pos.x += 40;
    cout << ofGetElapsedTimeMillis() << endl;
        
    }
        
}

void Rectangle::draw() {
    
    ofSetColor(255, 255, 255);
    ofRect(pos.x, pos.y, 20, 20);
    
}