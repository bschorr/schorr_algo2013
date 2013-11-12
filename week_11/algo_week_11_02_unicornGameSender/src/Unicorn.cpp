//
//  Unicorn.cpp
//  unicornGame
//
//  Created by Bernardo Santos Schorr on 11/5/13.
//
//

#include "Unicorn.h"

void Unicorn::setup(){

    pos.set (10, 30);
    vel.set(10, 0);

}

void Unicorn::update(){
    
    pos += vel;
    
    if (pos.x > ofGetWindowWidth()*2 || pos.x < 0 ) {
        vel.x *= -1;
    }
    
    
}

void Unicorn::draw(){
    
    ofSetColor(0);
    ofCircle (pos, 40);
    
}
