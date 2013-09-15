class Particle {

  PVector pos = new PVector();
  PVector prevPos = new PVector(); 
  PVector vel = new PVector();
  PVector accel = new PVector();

  Particle (PVector _pos, PVector _vel) {

    pos = _pos;
    vel = _vel;
  }


  void update () {
    prevPos.x = pos.x;
    prevPos.y = pos.y;
    accel.x = (mouseX - pos.x);
    accel.y = (mouseY - pos.y);
    accel.normalize();
    accel.mult(0.1);
    //accel.x = map (accel.x, 0, 1, 1, 0);
    //accel.y = map (accel.y, 0, 1, 1, 0);
    vel.add(accel);
    pos.add(vel);
    vel.mult(0.99);
  }

  void draw () {
    line (prevPos.x, prevPos.y, pos.x, pos.y);
  }
}

