//
//  fireworkList.cpp
//  algo_week_04_04_fireworks
//
//  Created by Bernardo Santos Schorr on 9/23/13.
//
//

#include "fireworkList.h"

Firework::Firework() {
    
    gravity = 0.01;
    exploded = false;
    dieCount = 255;
    
    posX = ofRandom(ofGetWindowWidth()/2 - 50, ofGetWindowWidth()/2 + 50);
    
    vel.x = ofRandom(-1.0, 1.0);
    vel.y = ofRandom(-3.0, -4.0);
    
    for( int i=0; i<200; i++){
        Mover myMover = Mover (posX, vel, gravity);
        moverList.push_back( myMover );
    }
    
    
}

void Firework::update() {
    
    if (!exploded) {
        
    vel.y += gravity;
    
    }
    
    for (int i = 0; i < moverList.size(); i++) {
        
        moverList[i].update();
        
        if (vel.y >= 0 && !exploded) {
        
        moverList[i].explode();
            
        }
    }
    
    if (vel.y >= 0 && !exploded) {
        
        exploded = true;
        
    }
    
    if (exploded && dieCount > 0) {
        
        dieCount -= 1.25;
        
    }
    

}

void Firework::draw() {
    
    
    ofSetColor(dieCount);
    for (int i = 0; i < moverList.size(); i++) {
     
    moverList[i].draw();
        
    }


}