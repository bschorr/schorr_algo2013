//
//  fish.cpp
//  algo_week_03_03_creature
//
//  Created by Bernardo Santos Schorr on 9/16/13.
//
//

#include "fish.h"

Fish::Fish (ofPoint _pos, float _size, float _speed){
    
    pos = _pos;
    size = _size;
    speed = _speed;
    
    for ( int i = 0; i < 13; i ++ ) {
     
        float tempRectH = abs (sin (0.1 * i * PI) * size);
        if ( tempRectH < size/6 ) tempRectH = size/6;
        
        rectH.push_back(tempRectH);
        
    }
    
    catchUpSpeed = 0.05;

    
    
}

void Fish::update () {
    
    sinMult += speed;
    posY.clear();
    
    for ( int i = 0; i < 13; i ++ ) {
            
        float motionMult = ofMap(i, 0, 13, 1.5, 4);
            
        float tempPosY = sin(sinMult + (2.5 - (i * 0.2f) )) * motionMult;
            
        posY.push_back(tempPosY);
            
    }
        
    
}

void Fish::draw () {
    
    
    ofPushMatrix(); {
        
        ofTranslate (pos.x, pos.y);
        ofRotate(angleInDegrees+180);
        
        for ( int i = 0; i < 13; i ++ ) {
        
            //int index = int (i*10);
            ofRect ((i * (size/6)), posY[i], size/10, rectH[i]);
        
        }
    
    }ofPopMatrix();
    
}

void Fish::xenoToPoint(float catchX, float catchY){
    
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    float deltaY = catchY - pos.y;
    float deltaX = catchX - pos.x;
    angleInDegrees = atan2(deltaY, deltaX) * 180 / PI;
    speed = ofDist(catchX, catchY, pos.x, pos.y) / 300;
    speed = ofClamp(speed, 0.1, 1);
    
 //   if (angleInDegrees < 30 && prevAngleInDegrees < 30)
    
    //angleInDegrees = angleInDegrees * 0.1 + prevAngleInDegrees * 0.9;
    prevAngleInDegrees = angleInDegrees;
    
}