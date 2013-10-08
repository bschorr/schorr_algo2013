//
//  Card.h
//  algo_week_06_01_solitaire
//
//  Created by Bernardo Santos Schorr on 10/7/13.
//
//

#pragma once
#include "ofMain.h"

class Card {
public:
    
    Card (int _cardNumber, ofPoint _pos);
    void update (ofVec3f &_gravity);
    void draw ( ofImage &back );
    
    ofImage img;
    ofPoint pos;
    
    ofVec3f vel;
    ofVec3f accel;
    ofVec3f rot;
    ofVec3f rotInc;
    
    int rotMult = 4;
    bool face;
    
    float angleY;
    float angleX;
    
};