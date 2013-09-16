#pragma once

#include "ofMain.h"
#include "fish.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        Fish myFish = Fish (ofPoint (ofGetWindowWidth()/2, ofGetWindowHeight()/2), ofRandom(25, 40), ofRandom(0.1, 0.5));
		
};
