I'm imagining randomly placed ants on a canvas forming trails.

Ants are randomly placed on a canvas.
Ants start with velocity vectors of similar magnitude and different directions. 
Ants have a field of vision that points towards their velocity and has an angle.

Ruleset would be:

If an ant sees another ant in its field of vision, it changes its velocity direction towards where this ant is going.

If there's more than one ant in one ant's field of vision, it will follow the ant that is closest.

If there are no ants in its field of vision it will walk one more increment towards its existing velocity.
