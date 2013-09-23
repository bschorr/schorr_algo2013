Fish myFish; 

void setup () {
  size (1024, 768);
  rectMode (CENTER);
  myFish = new Fish ( new PVector(width/2, height/2), random (25, 40), random (0.1, 0.5));
  
}

void draw () {
  
  background (0);
  
  myFish.update();
  myFish.xenoToPoint(mouseX, mouseY);
  myFish.draw();
 
}
