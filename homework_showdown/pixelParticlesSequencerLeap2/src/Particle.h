//
//  Particle.h
//  PixelForces 2
//
//  Created by Bernardo Schorr 2013.
//
//  Based in code by Ben McChesney on 7/2/11.
//
//  A Simple Particle Class

#ifndef _PARTICLE
#define _PARTICLE

#include "ofMain.h" 

class Particle
{
    public : 
        Particle() ;
        Particle( ofPoint _position , ofColor _color )
        {
            position = _position ; 
            color = _color ; 
            velocity = ofPoint ( ofRandom ( -5 , 5 ) , ofRandom ( -5 , 5 ) ) ; 
            spawnPoint = _position ;
            
            angle = atan2(position.x - ofGetWidth()/2, position.y - ofGetHeight()/2);
            
            size = 10;
            
            if (position.x > ofGetWidth()/2){
                angle = 360 - (angle * 180 / PI);
                
            } else {
                angle = (angle * 180 / PI) * -1;
            }
            
            
        }
    
    void defineAngleNote () {
        
        //defining the angle
        
        angle = atan2(position.x - ofGetWidth()/2, position.y - ofGetHeight()/2);
        
        if (position.x > ofGetWidth()/2){
            angle = 360 - (angle * 180 / PI);
            
        } else {
            angle = (angle * 180 / PI) * -1;
        }
        
        //defining the note
        
        float tempNote  = ofDist(position.x, position.y, ofGetWidth()/2, ofGetHeight()/2);
        note = int (ofMap (tempNote, 0, 640, 0, 23));
        if (note>23) note = 23;
        
        
    }
    
    
        ofPoint position , velocity ;
        ofPoint acceleration ;          //smoothing applied to velocity
        ofPoint spawnPoint ;            //original location to line up the picture
        ofColor color ;
    
        float angle;
    
        float note;
    int size;

};
#endif