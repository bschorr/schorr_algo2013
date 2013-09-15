Particle [] particles = new Particle [50]; 
float rot;

void setup () {

  size (1000, 1000);
  
  strokeWeight (0.1);
  
  background (0);
  stroke (255);
  strokeWeight (1);  

  for ( int i = 0; i < particles.length; i++ ) {

    PVector tempPos = new PVector (width/2, height/2);
    PVector tempVel = new PVector (map(i, 0, particles.length-1, 5, 10), map(i, 0, particles.length-1, 10, 5));

    particles[i] = new Particle (tempPos, tempVel);
  }
}

void draw () {

  for ( int i = 0; i < particles.length; i++ ) {
    
    particles[i].update();
    particles[i].draw();
    
    
  }
}

void keyPressed () {
  noLoop();
  
};

