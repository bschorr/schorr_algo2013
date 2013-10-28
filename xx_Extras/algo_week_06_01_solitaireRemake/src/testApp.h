#pragma once

#include "ofMain.h"
#include "Card.h"

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
		
    vector <Card> cards;
    int timer, counter;
    int initCounter;
    int drawKings;
    ofImage realBack;
    ofVec3f gravity;
    ofImage bkg;
    
};
