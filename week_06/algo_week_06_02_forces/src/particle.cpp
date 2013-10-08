#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0,0,0);
	damping = 0.09f;
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set( 0, 0, 0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y, float z){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
    frc.z = frc.z + z;
}

//------------------------------------------------------------
void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity 
	// damping is a force operating in the oposite direction of the 
	// velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
    frc.z = frc.z - vel.z * damping;
}


//------------------------------------------------------------
void particle::addRepulsionForce( float px, float py, float pz, float radius, float strength){
	
	
	ofVec3f posOfForce;
	posOfForce.set(px, py, pz);
	
	ofVec3f diff = pos - posOfForce;
	
	if (diff.length() < radius){
		float pct = 1 - (diff.length() / radius);
		diff.normalize();
		frc.x += diff.x * pct * strength;
		frc.y += diff.y * pct * strength;
        frc.z += diff.z * pct * strength;
	}
	
}

//------------------------------------------------------------
void particle::addAttractionForce( float px, float py, float pz, float radius, float strength){
	
	
	ofVec3f posOfForce;
	posOfForce.set(px, py, pz);
	
	ofVec3f diff = pos - posOfForce;
	
	if (diff.length() < radius){
		float pct = 1 - (diff.length() / radius);
		diff.normalize();
		frc.x -= diff.x * pct * strength;
		frc.y -= diff.y * pct * strength;
        frc.z -= diff.z * pct * strength;
	}
	
}


//------------------------------------------------------------
void particle::addClockwiseForce( float px, float py, float pz, float radius, float strength){
	
	
	ofVec3f posOfForce;
	posOfForce.set(px, py, pz);
	
	ofVec3f diff = pos - posOfForce;
	
	if (diff.length() < radius){
		float pct = 1 - (diff.length() / radius);
		diff.normalize();
		frc.x -= diff.y * pct * strength;
		frc.y += diff.x * pct * strength;
        frc.z += diff.z * pct * strength;
	}
	
}

//------------------------------------------------------------
void particle::addCounterClockwiseForce( float px, float py, float pz, float radius, float strength){
	
	
	ofVec3f posOfForce;
	posOfForce.set(px, py, pz);
	
	ofVec3f diff = pos - posOfForce;
	
	if (diff.length() < radius){
		float pct = 1 - (diff.length() / radius);
		diff.normalize();
		frc.x += diff.y * pct * strength;
		frc.y -= diff.x * pct * strength;
        frc.z -= diff.z * pct * strength;
	}
	
}





//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float pz, float vx, float vy, float vz){
    pos.set(px,py,pz);
    vel.set(px,py,pz);
}

//------------------------------------------------------------
void particle::update(){	
	vel = vel + frc;
	pos = pos + vel;
}

//------------------------------------------------------------
void particle::draw(){
    
    ofDrawSphere(pos, 50);
    
}

