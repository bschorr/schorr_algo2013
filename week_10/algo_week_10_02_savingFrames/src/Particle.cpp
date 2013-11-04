//
//  Particle.cpp
//  algo_week_10_01_moreParticlesThanTheEyeCanSee
//
//  Created by Bernardo Santos Schorr on 11/4/13.
//
//

#include "Particle.h"

void Particle::setup( ofVec2f &_pos ) {
    
    pos = _pos;
    float tempAngle =  ofRandom (360);
    vel.set( cos(tempAngle), sin(tempAngle) );
    //vel*=1.0;
    
}

void Particle::update() {
    
    ofVec2f center = ofGetWindowSize()/2;
    ofVec2f force = center - pos;
    acc = force * 0.0001;
    
    vel += acc;
    prevPos = pos;
    pos += vel;
    
    float mult = ofRandom(0.98, 1.02);
    vel *= mult;
    acc *= 0;
    
}

void Particle::draw() {
    
    ofLine (prevPos, pos);
    
}