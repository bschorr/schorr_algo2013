#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(60);
    ofSetVerticalSync(true);
	ofSetLogLevel(OF_LOG_VERBOSE);

	leap.open();
    leap.setupGestures();   // we enable our gesture detection here
    
    //sequencer setup
    
    //ofSetWindowShape(ofGetScreenWidth(), ofGetScreenHeight());
    //ofToggleFullscreen();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    img.loadImage("texture2.png");
    hue = 0;
    bri = 150;
    ofHideCursor();
    
    //sequencer setup
    sender.setup("localhost", 6534);
    recvr.setup(6666);
    circle.set(ofGetWidth()/2, ofGetHeight()/2);
    rotation = 0;
    
    //Set the background to black
    ofBackground( 0 , 0 , 0 ) ;
    
    //Loop through all the rows
    for ( float i = 0 ; i < 360 ; i += 0.2)
    {
        
        ofColor color = ofColor::fromHsb(hue, 255, bri);
        //red pixel
        //color.g = pixels[index+1] ;     //blue pixel
        //color.b = pixels[index+2] ;     //green pixel
        int tempRadius = ofRandom(130, 150);
        int x = ofGetWidth()/2 + cos(i)*150;
        int y = ofGetHeight()/2 + sin(i)*150;
        
        particles.push_back( Particle ( ofPoint ( x, y ) , color) ) ;
    }
    
    ofSetFrameRate( 30 ) ;
    numParticles = particles.size() ;
    
    
    //Set spring and sink values
    cursorMode = 0 ;
    forceRadius = 100 ;
    friction = 0.85 ;
    springFactor = 0.12 ;
    springEnabled = true ;
    inc = 2;

}


//--------------------------------------------------------------
void testApp::update(){
    
    simpleHands = leap.getSimpleHands();
    leap.updateGestures();  // check for gesture updates
    
    for(int i = 0; i < simpleHands.size(); i++){
        //simpleHands[i].debugDraw();
        
        tempX = ofMap (simpleHands[i].handPos.x, -120.0, 120.0, 0, ofGetWindowWidth());
        
        tempY = ofMap (simpleHands[i].handPos.y, 400, 100, 0, ofGetWindowHeight());
    }

	//IMPORTANT! - tell ofxLeapMotion that the frame is no longer new. 
	leap.markFrameAsOld();
    
    //start sequencer update
    
    oscReceiver();
    
    //sequencer update
    prevRotation = rotation;
    rotation += inc;
    hue += 1;
    
    if (rotation > 360) rotation = 0;
    if (rotation < 0) rotation = 360-rotation;
    if (hue > 255) hue = 0;
    
    
    ofPoint diff ;          //Difference between particle and mouse
    float dist ;            //distance from particle to mouse ( as the crow flies )
    float ratio ;           //Ratio of how strong the effect is = 1 + (-dist/maxDistance) ;
    const ofPoint mousePosition = ofPoint( tempX , tempY ) ; //Allocate and retrieve mouse values once.
    
    
    //Create an iterator to cycle through the vector
    std::vector<Particle>::iterator p ;
    for ( p = particles.begin() ; p != particles.end() ; p++ )
    {
        ratio = 1.0f ;
        p->velocity *= friction ;
        //reset acceleration every frame
        p->acceleration = ofPoint() ;
        diff = mousePosition - p->position ;
        dist = ofDist( 0 , 0 , diff.x , diff.y ) ;
        //If within the zone of interaction
        if ( dist < forceRadius )
        {
            ratio = -1 + dist / forceRadius ;
            //Repulsion
            if ( cursorMode == 0 )
                p->acceleration -= ( diff * ratio) ;
            //Attraction
            else
                p->acceleration += ( diff * ratio ) ;
        }
        if ( springEnabled )
        {
            //Move back to the original position
            p->acceleration.x += springFactor * (p->spawnPoint.x - p->position.x);
            p->acceleration.y += springFactor * (p->spawnPoint.y - p->position.y) ;
        }
        
        p->velocity += p->acceleration * ratio ;
        p->position += p->velocity ;
        
        p->defineAngleNote();
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	//ofDisableLighting();
    ofBackground(0);
	
	ofSetColor(200);
    
    for(int i = 0; i < simpleHands.size(); i++){
        //simpleHands[i].debugDraw();
        
        ofCircle (tempX, tempY, 3);

    }
    
    //sequencer draw
    
    vector<Particle>::iterator p ;
    
    for ( p = particles.begin() ; p != particles.end() ; p++ )
        //for ( int i = 0 ; i < particles.size() ; i++ )
    {
        
        //playing the notes
        
        play = false;
        
        if (prevRotation <= int(p->angle) && rotation >= int(p->angle) && abs(rotation - prevRotation) < abs (inc*2)) play = true;
        
        if (prevRotation >= int(p->angle) && rotation <= int(p->angle) && abs(rotation - prevRotation) < abs(inc*2)) play =true;
        
        
        p->color.setHue(hue);
        
        if (play == true) {
            
            p->color.a = 255;
            p->color.setBrightness(255);
            p->color.setSaturation(255);
            p->size = 30;
            
            ofxOscMessage message;
            message.setAddress("/playtone");
            message.addIntArg( p->note );
            sender.sendMessage(message);
            
        } else {
            
            p->color.setBrightness(p->color.getBrightness()-10);
            p->color.setSaturation(p->color.getSaturation()+10);
            p->size -= 0.5;
            p->color.a -= 10;
            
            
        }
        
        if (p->color.a < 80) p->color.a = 80;
        if (p->color.getBrightness() < 150) p->color.setBrightness(150);
        if (p->color.getSaturation() > 200) p->color.setSaturation(200);
        if (p->size < 10) p->size=10;
        
        
        // draw the particles
        ofSetColor((unsigned char)p->color.r,(unsigned char)p->color.g,(unsigned char)p->color.b, (unsigned char)p->color.a);
        img.draw(p->position.x, p->position.y, p->size, p->size);
        
    }
    
    ofSetColor ( 255 , 255 , 255 ) ;
    
    string output = "S :: Springs on/off : " + ofToString(springEnabled) +
    
    "\n C :: CursorMode repel/attract " + ofToString( cursorMode ) +
    
    "\n # of particles : " + ofToString( numParticles ) +
    
    " \n fps:" +ofToString( ofGetFrameRate() );
    
    
    if (debugtext)ofDrawBitmapString(output ,20,666);
    
    ofSetColor(255, 100);
    ofCircle (mouseX, mouseY, 5, 5);
    
    switch ( leap.iGestures )
    {
        case 3:
            springEnabled = true ;
            break ;
            
        case 4:
            springEnabled = false ;
            break ;
            
    }
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    switch ( key )
    {
        case 'c':
        case 'C':
            cursorMode = ( cursorMode + 1 > 1 ) ? 0 : 1 ;
            break ;
            
        case 2:
            springEnabled = !springEnabled ;
            break ;
            
            
        case 't':
        case 'T':
            debugtext = !debugtext ;
            break ;
    }

  
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
void testApp::exit(){
    // let's close down Leap and kill the controller
    leap.close();
}


void testApp::oscReceiver () {
    
    ofxOscMessage message;
    recvr.getNextMessage(&message);
    
    string address = message.getAddress();
    cout << "message address: " << message.getAddress() << endl;
    cout << "message num arguments: " << message.getNumArgs() << endl;
    
    for (int i = 0; i < message.getNumArgs(); i++){
        cout << "argument " << i << " is type " << message.getArgTypeName(i);
        
        if (message.getArgType(i) == OFXOSC_TYPE_FLOAT){
            if (address.compare("/1/speed")== 0)inc = message.getArgAsFloat(i);
            if (address.compare("/1/spring")== 0)springEnabled =message.getArgAsFloat(i);
            if (address.compare("/1/repel")== 0)cursorMode = message.getArgAsFloat(i);
            if (address.compare("/1/radius")== 0) {
                
                std::vector<Particle>::iterator p ;
                for ( p = particles.begin() ; p != particles.end() ; p++ )
                {
                    
                    p->spawnPoint.x = ofGetWidth()/2 + cos(p - particles.begin()
                                                           )* message.getArgAsFloat(i);
                    
                    p->spawnPoint.y = ofGetHeight()/2 + sin(p - particles.begin()
                                                            )* message.getArgAsFloat(i);
                    
                }
            }
            
            
            
            ;
            
            cout << " val = " << message.getArgAsFloat(i) << endl;
        } else if (message.getArgType(i) == OFXOSC_TYPE_INT32){
            cout << " val = " << message.getArgAsInt32(i) << endl;
        } else if (message.getArgType(i) == OFXOSC_TYPE_STRING){
            cout << " val = " << message.getArgAsString(i) << endl;
        }
        
    }
}

