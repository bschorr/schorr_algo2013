//
//  fish.cpp
//  algo_week_03_03_creature
//
//  Created by Bernardo Santos Schorr on 9/16/13.
//
//

#include "fish.h"

Fish::Fish (ofPoint _pos, ofVec2f _size, float _speed){
    
    pos = _pos;
    size = _size;
    speed = _speed;
    
    for ( float i = 0.0f; i < size.x; i += 0.1 ) {
     
        float tempRectH = abs (sin (i * PI) * size.y);
        if ( tempRectH < 5 ) tempRectH = 5;
        
        rectH.push_back(tempRectH);
        
    }

    
    
}

void Fish::update () {
    
    sinMult += speed;
    posY.clear();
            
    for ( float i = 0.0f; i < size.x; i += 0.1 ) {
            
        float motionMult = ofMap(i, 0, size.x, size.x * 0.3, size.x * 0.6);
            
        float tempPosY = sin(sinMult + (size.x - i)) * 4 * motionMult;
            
        posY.push_back(tempPosY);
            
    }
        
    
}

void Fish::draw () {
    
    
    ofPushMatrix(); {
        
        ofTranslate (pos.x, pos.y);
        
        for ( float i = 0.0f; i < size.x; i += 0.1 ) {
        
            int index = int (i*10);
            ofRect ((i * 50), posY[index], 3, rectH[index]);
        
        
        }

    
    }ofPopMatrix();
    
    
    
    
    
}