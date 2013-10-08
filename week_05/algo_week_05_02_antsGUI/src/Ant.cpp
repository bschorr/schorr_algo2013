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
    
    noiseSeed = ofRandom(1000);
    
    color.setHsb(ofRandom(0, 10), 255, 255);
    
}

void Ant::update( vector <Ant> &ants ) {
    
    minDist = 1000;
    
    std::vector<Ant>::iterator p ;
    for ( p = ants.begin() ; p != ants.end() ; p++ )
    {
        dist = ofDist(pos.x, pos.y, p->pos.x, p->pos.y);
        
        if ( dist != 0 && dist < minDist ) {
            
            minDist = dist;
            //size = 50 - minDist;
            size = minDist;
            size = ofClamp(size, 50, 500);
            
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
    float noise = ofNoise(noiseSeed + ofGetElapsedTimef());
    noise = ofMap(noise, 0.0, 1.0, -1.0, 1.0);
    vel.rotate(noise * 2);
    pos += vel;
    
}

void Ant::draw( ofImage &img ) {
    
    //ofRect(pos, 3, 3);
    img.draw(pos.x, pos.y, size, size);

    
}