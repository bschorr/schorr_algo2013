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
    
    top.x = pos.x;
    bottom.x = pos.x;
    
    top.y = pos.y - size.y*0.5;
    bottom.y = pos.y + size.y*0.5;
    
    //vel.set ( 0, 0 );
    velTop.set (0,0);
    velBottom.set (0,0);
    gravity.set (0, 1.0);
    
    dampingTop = 0.9f;
    dampingBottom = 1.0f;
    defineFinalSize = true;
    finalSize.set (1000, 1000);
    
}

void Particle::update() {
    
    
    // add gravity to both velocities
    velTop += gravity;
    velBottom += gravity;
    
    // add different dampings to each velocity
    bottom += velBottom*dampingBottom;
    top += velTop*dampingTop;
    
    //draw ellipse at right position
    pos = (bottom + top) /2;
    
    //make x and y sizes always proportional
    size.y = bottom.y - top.y;
    size.x = initSize.x - (size.y - initSize.y);
    
    //different dampings for velocity going up and down
//    if (velBottom.y > 0) {
//        dampingTop = 0.9;
//        dampingBottom = 1.0;
//    } else {
//        dampingTop = 1.0;
//        dampingBottom = 0.9;
//    }
    
    if (bottom.y >= ofGetWindowHeight()) {
        
        bottom.y = ofGetWindowHeight();
        
        if (size.y <= 120) {
            velTop *= -1;
        }
        
        if (size.y >= finalSize.y) {
            velBottom.y = velTop.y;
            cout << finalSize << endl;
            //defineFinalSize = true;
        }
        
        if (defineFinalSize) {
            finalSize = size;
            defineFinalSize = false;
            finalVelBottom = velBottom.y*-1;
            velBottom.y = 0;
        }
        
    }
    
    
}

void Particle::draw() {
    
    ofEllipse (pos, size.x, size.y);
    
}