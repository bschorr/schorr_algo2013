//
//  Ant.h
//  algo_week_04_01_antsGUI
//
//  Created by Bernardo Santos Schorr on 9/30/13.
//
//

#pragma once

#include "ofMain.h"

class Ant {
public:
    
    Ant ();
    Ant ( ofPoint _pos, ofVec2f _vel );
    
    void update( vector <Ant> _ants );
    void draw( ofImage _img);
    
    ofPoint pos;
    ofVec2f vel;
    //ofVec2f accel;
    
    float dist;
    float minDist;
    int chosenOne;
    
};
