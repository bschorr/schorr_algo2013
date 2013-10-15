//
//  Particle.h
//  algo_week_07_01_stealingKimrepo
//
//  Created by Bernardo Schorr on 10/14/13.
//  Based in code created by TheAlkimist on 10/5/13.
//  https://github.com/thealkimist/kim_algo2013/tree/master/wk6_attractorRepulsor
//

#include "ofMain.h"

class Particle{
public:
    
    Particle();     // particle constructor
    virtual ~Particle(){};
    
    ofVec2f pos;    // vector position
    ofVec2f vel;    // vector velocity
    ofVec2f force;    // vector force
    
    void resetForce();
    void addDamping();                      // damping 
    void setInitCondition(float px, float py, float vx, float vy);  // starting force
    void update();
    void draw();
    
    void addRepulsion(float px, float py, float radius, float strength);
    void addAttraction( float px, float py, float radius, float strength);
    void trail(float catchX, float catchY);
    
    float damping;
    float size;
    
    int r, g, b;
    float dist;
    
    
    
};
