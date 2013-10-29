//
//  Particle.cpp
//  algo_week_09_02_animation
//
//  Created by Bernardo Santos Schorr on 10/28/13.
//
//

#include "Particle.h"

void Particle::setup(ofVec2f _pos, ofVec2f _dest) {
    
    pos = _pos;
    dest= _dest;
    prevPos = pos;
    vel.set(0.01, 0);
    size.set (10, 10);
    
    xenoRandomPos = ofRandom(0.95, 0.97);
    xenoRandomDest = 1.0 - xenoRandomPos;
    
    triggerOne = false;
    triggerTwo = false;
    triggerThree = false;
    
    color.set(0, 0);
    
}

void Particle::update(int i, int &countOne, int &countTwo) {
    
    if (!triggerTwo) {
        if (!triggerOne) {

            float tempRandom = ofRandomf();
            if (tempRandom < -0.8) triggerOne = true;
            
        } else {
        
            prevPos = pos;
            pos = pos*xenoRandomPos + dest*xenoRandomDest;
            size.x = 10*(pos.x-prevPos.x);
            float colorSet = ofMap(pos.x, 0s, dest.x, 0, 100);
            color.set(0, colorSet);
            
            if (size.x < 10) size.x = 10;
            
        }
        
        if (dest.x-pos.x < 1.0) {
            countOne ++;
        }
    
    } else {
        
        if (!triggerThree) {
            float tempRandom = ofRandomf();
            if (tempRandom < -0.8) triggerThree = true;
        } else {
            size.x -= 0.5;
            if (size.x < 0) {
                size.x = 0;
                countTwo++;
            }
        }
        
    }
    
}

void Particle::draw() {
    
    ofSetColor(color);
    ofRect(pos, size.x, size.y);
    
}