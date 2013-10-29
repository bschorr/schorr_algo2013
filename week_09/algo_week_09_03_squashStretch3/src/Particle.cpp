//
//  Particle.cpp
//  algo_week_09_03_squashStretch2
//
//  Created by Bernardo Santos Schorr on 10/28/13.
//
//

#include "Particle.h"

void Particle::setup(ofVec2f &initPos) {
    
    pos = initPos;
    initSize.set(200, 200);
    size = initSize;
    
    vel.set ( 0, 0 );
    gravity.set(0, 0.5);
    
    //defineFinalSize = true;
    finalSize.set (1000, 1000);
    
    reached = false;
    mult = 1.0;
    
}

void Particle::update() {
    
    vel += gravity;
    sizeYMult =  ofMap (abs(vel.y), 0, 100.0, 1.0, 2.0);
    size.y = initSize.y * sizeYMult;
    size.x = initSize.x * (2.0 - sizeYMult);

    pos += vel;
    

    
    if (pos.y > ofGetWindowHeight()- (size.y)*0.5) {
        
        pos.y = ofGetWindowHeight() - (size.y)*0.5;
        //vel.y = 0;
        //reached = true;
        vel.y*= -1;
        float tempX = size.x;
        float tempY = size.y;
        
        size.y = tempX;
        size.x = tempY;
    }
    
    
    
    
}

void Particle::draw() {
    
    ofEllipse (pos, size.x, size.y);
    
}