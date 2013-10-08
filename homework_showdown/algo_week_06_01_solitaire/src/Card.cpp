//
//  Card.cpp
//  algo_week_06_01_solitaire
//
//  Created by Bernardo Santos Schorr on 10/7/13.
//
//

#include "Card.h"

Card::Card(int _cardNumber, ofPoint _pos) {
    
    pos =_pos;
    string cardNumber = ofToString(_cardNumber) + ".png";
    img.loadImage(cardNumber);
    vel.set( ofRandom(-8, 5), 0, ofRandom(2,5) );
    rot.set( 0, 0, 0 );
    rotInc.set( ofRandom(-rotMult, rotMult), ofRandom(-rotMult, rotMult), ofRandom(-rotMult, rotMult) );
    face = true;
    
}

void Card::update(ofVec3f &_gravity) {
    
    rot += rotInc;
    vel += _gravity;
    if (pos.y > ofGetWindowHeight()-50) vel.y *= -0.6;
    pos+=vel;
    face = true;
    
    
    if (rot.y >= 0) {
        if (pos.x < ofGetWindowWidth()/2) angleY = ofMap (pos.x, 0, ofGetWindowWidth()/2, 128, 90);
        if (pos.x > ofGetWindowWidth()/2) angleY = ofMap (pos.x, ofGetWindowWidth()/2, ofGetWindowWidth(), 90, 52);
        if (rot.y >= angleY) face = !face;
    
    } else if (rot.y < 0) {
        if (pos.x < ofGetWindowWidth()/2) angleY = ofMap (pos.x, 0, ofGetWindowWidth()/2, -52, -90);
        if (pos.x > ofGetWindowWidth()/2) angleY = ofMap (pos.x, ofGetWindowWidth()/2, ofGetWindowWidth(), -90, -128);
        if (rot.y <= angleY) face = !face;
    }
    
    
    if (rot.x >= 0) {

        if (pos.y < ofGetWindowHeight()/2) angleX = ofMap (pos.y, ofGetWindowHeight()/2, 0, 90, 60);
        if (pos.y > ofGetWindowHeight()/2) angleX = ofMap (pos.y, ofGetWindowHeight()/2, ofGetWindowHeight(), 90, 120);
        if (rot.x >= angleX) face = !face;
    
    } else if (rot.x < 0) {
        if (pos.y < ofGetWindowHeight()/2) angleX = ofMap (pos.y, ofGetWindowHeight()/2, 0, -90, -120);
        if (pos.y > ofGetWindowHeight()/2) angleX = ofMap (pos.y, ofGetWindowHeight()/2, ofGetWindowHeight(), -90, -60);
        if (rot.x <= angleX) face = !face;
    }
    
    
    if (rot.y >= angleY+180) {
        rot.y -= 360;
    } else if (rot.y <= angleY-180) {
        rot.y += 360;
    }
    
    if (rot.x >= angleX+180) {
        rot.x -= 360;
    } else if (rot.x <= angleX-180) {
        rot.x += 360;
    }
    
}

void Card::draw( ofImage &back ) {
    
    ofPushMatrix();
    
    ofTranslate(pos.x, pos.y, pos.z);
    ofRotateX (rot.x);
    ofRotateY (rot.y);
    ofRotateZ (rot.z);
    
    //face = true;
    
    if (face) {
        img.draw(0, 0, 0, 108, 144);
    } else {
        back.draw(0, 0, 0, 108, 144);
    }
    
    
    ofPopMatrix();
    
}