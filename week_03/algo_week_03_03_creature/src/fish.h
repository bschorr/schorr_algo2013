//
//  fish.h
//  algo_week_03_03_creature
//
//  Created by Bernardo Santos Schorr on 9/16/13.
//
//

#pragma once

#include "ofMain.h"

class Fish {
    
public:
    
    Fish();
    Fish( ofPoint _pos, ofVec2f _size, float _speed);
    
    void update ();
    void draw ();
    
    ofPoint pos;
    ofVec2f size;
    float sinMult;
    float speed;
    
    vector<float> rectH;
    vector<float> posY;
    
    
    
 /*   float tempMult = ofMap (mouseY, 0, ofGetWindowHeight(), 0, 1);
    sinMult += tempMult;
    
    ofPushMatrix(); {
        
        ofTranslate (ofGetWindowWidth()/2, ofGetWindowHeight()/2);
        
        for ( float i = 0.0f; i < 1.3; i += 0.1 ) {
            
            float rectH = abs (sin (i * PI) * 30);
            if ( rectH < 5 ) rectH = 5;
            
            float motionMult = ofMap(i, 0, 1.3, 0.4, 1);
            
            float posY = sin(sinMult + (1.3 - i)) * 4 * motionMult;
            
            
            ofRect((i * 50), posY, 3, rectH);
            
            
        }
        
        
    }ofPopMatrix();
  
  */
    
    
    
    
    
    
    
    
    
};
