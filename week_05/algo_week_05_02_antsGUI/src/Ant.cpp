//
//  Ant.cpp
//  algo_week_04_01_antsGUI
//
//  Created by Bernardo Santos Schorr on 9/30/13.
//
//

#include "Ant.h"

Ant::Ant () {
    
    pos.set(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowWidth()));
    
    vel.set(ofRandom(-1, 1), ofRandom(-1, 1));
    vel.normalize();
    
}

void Ant::update( vector <Ant> _ants ) {
    
    minDist = 1000;
    chosenOne = -1;
    
    vector <Ant> ants = _ants;
    
    
    std::vector<Ant>::iterator p ;
    for ( p = ants.begin() ; p != ants.end() ; p++ )
    {
        dist = ofDist(pos.x, pos.y, p->pos.x, p->pos.y);
        
        if ( dist != 0 && dist < minDist ) {
            
            minDist = dist;
            
            ofVec2f delta = ofVec2f(p->pos.x - pos.x , p->pos.y - pos.y);
            
            if (abs (vel.angle(delta)) < 30) {
                
                vel = delta;
                
            }
            
        }
        
    }
    
    vel.normalize();
    
    if (pos.x < 0) vel.x += 1;
    if (pos.x > ofGetWindowWidth() ) vel.x -= 1;
    if (pos.y < 0) vel.y += 1;
    if (pos.y > ofGetWindowHeight()) vel.y -= 1;
    
    //vel += accel;
    vel *= 3;
    vel.rotate(ofRandom(-10, 10));
    pos += vel;
    
}

void Ant::draw( ofImage _img ) {
    
    //ofRect(pos, 3, 3);
    _img.draw(pos.x, pos.y);

    
}