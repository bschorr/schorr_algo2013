//
//  Particle.cpp
//  SingleParticle
//
//  Created by Charlie Whitney on 9/23/13.
//
//

#include "Particle.h"

Particle::Particle() {
//    setParams(0,0,0);
    damping = ofVec2f( 0.01f );
}

void Particle::setParams( ofVec2f _pos, ofVec2f _vel ){
    pos.set( _pos );
    vel.set( _vel );
    
    lastPos.set( pos );
}

void Particle::addForce( ofVec2f force ){
    acc += force;       // F = MA
}

void Particle::seek() {
    float maxSpeed = 10.0;
    float maxForce = 0.2;
    
    float slowDownRadius = 200.0;
    
    ofVec2f desired = dest - pos;
    
    if( desired.length() < slowDownRadius ){
        float newMag = ofMap( desired.length(), 0, slowDownRadius, 0, maxSpeed);
        
        desired.normalize();
        desired *= newMag;
    }else{
        desired.normalize();
        desired *= maxSpeed;
    }

    //ofVec2f steer = desired - vel;
    ofVec2f steer = desired - vel;
    steer.limit( maxForce );
    
    if (!isAvoided) addForce( steer );
}

void Particle::avoid( Particle otherCar ) {
    
    float crashRadius = 60.0;
    ofVec2f crashDistance = otherCar.pos - pos;
    float crashAngle = crashDistance.angle(vel);
    
    ofVec2f posOfForce;
	posOfForce.set(otherCar.pos);
    
    float maxForce = 0.2;

	
	ofVec2f diff = pos - posOfForce;
    
    if (crashDistance.length() < crashRadius) {
        
        float pct = 1 - (diff.length() / crashRadius);
		diff.normalize();
        diff *= pct;
        //diff.limit(maxForce);
        //addForce(diff*pct);
        addForce( diff );
        isAvoided = true;
    
    }
    
}

void Particle::update (Particle otherCar) {
    vel = vel + acc;
    pos = pos + vel;
    
    vel *= 0.97;
    
    acc *= 0;
    
    lastPos.set( pos );
    isAvoided = false;
    
    
}

void Particle::draw() {
//    ofCircle(pos.x, pos.y, 4);
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    ofPushMatrix();
    ofTranslate( pos );
    
        float rotAmt = atan2( vel.y, vel.x );
        ofRotate( ofRadToDeg(rotAmt));
        ofRect( 0,0, 40, 20);
    
    ofPopMatrix();
}