class Fish {

  PVector pos = new PVector();

  float size;
  float sinMult;
  float speed;

  float angleInDegrees;
  float prevAngleInDegrees;
  float catchUpSpeed;

  FloatList rectH = new FloatList();
  FloatList posY = new FloatList();


  Fish (PVector _pos, float _size, float _speed) {
    
    pos = _pos;
    size = _size;
    speed = _speed;
    
    for ( int i = 0; i < 13; i ++ ) {
     
        float tempRectH = abs (sin (0.1 * i * PI) * size);
        if ( tempRectH < size/6 ) tempRectH = size/6;
        
        rectH.append(tempRectH);
        
    }
    
    catchUpSpeed = 0.05;
    
  }

  void update () {
    
    sinMult += speed;
    posY.clear();
    
    for ( int i = 0; i < 13; i ++ ) {
            
        float motionMult = map(i, 0, 13, 1.5, 4);
            
        float tempPosY = sin(sinMult + (2.5 - (i * 0.2f) )) * motionMult;
            
        posY.append(tempPosY);
            
    }

    
  }

  void draw () {
    
    pushMatrix();
        
        translate (pos.x, pos.y);
        rotate(radians(angleInDegrees+180));
        
        for ( int i = 0; i < 13; i ++ ) {
        
            //int index = int (i*10);
            rect ((i * (size/6)), posY.get(i), size/10, rectH.get(i));
        
        }
    
    popMatrix();

    
  }

  void xenoToPoint (float catchX, float catchY) {
  
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    float deltaY = catchY - pos.y;
    float deltaX = catchX - pos.x;
    angleInDegrees = atan2(deltaY, deltaX) * 180 / PI;
    speed = dist(catchX, catchY, pos.x, pos.y) / 300;
    speed = constrain(speed, 0.1, 1);
  
    prevAngleInDegrees = angleInDegrees;

  }
  
}

