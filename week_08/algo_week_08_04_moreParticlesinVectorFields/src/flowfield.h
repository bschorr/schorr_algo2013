//
//  flowfield.h
//  algo_week_08_04_moreParticlesinVectorFields
//
//  Created by Bernardo Santos Schorr on 10/21/13.
//
//

#pragma once

#include "ofMain.h"

typedef vector<ofVec3f> VectorList;
typedef vector< vector<ofVec3f> > PlaneList;

class Flowfield {
public:
    
    void setup (int _width, int _height, int _depth, int _resolution);
    void update ();
    void draw ();
    void setPerlin();
    ofVec3f getForceAtPosition( ofVec3f pos );
    
    int width, height, depth, resolution;
    vector <PlaneList> flowList;
    
};