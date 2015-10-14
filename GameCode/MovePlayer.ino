
// if d-pad is pressed, check for
// collision with a wall and move player

// NOTE: dying has been disabled - walking 
// offscreen now works like hitting a wall (nothing happens)
void movePlayer(char dir) {

  // north
  if (dir == 'n') {
    if (level[y-1][x] == 4) {            // respawn point
      y--;                               // move to hole
      rumble(4);                         // play falling rumble
      resetPlayerPosition();             // reset x/y coords

      // ** no need to check if we're at the bottom level since it will have no holes!
    }
    else if (y-1 < 0) {                  // if you move offscreen...
      // y--;                            // fall into the ocean...
      // death = true;                   // and die!
    }
    else {
      rumble(level[y-1][x]);             // play the appropriate rumble-interface
      if (level[y-1][x] != 1) {          // if next tile is NOT a wall
        y--;                             // move player
      }
    }
  }

  // same for other directions...

  // south
  if (dir == 's') {
    if (level[y+1][x] == 4) {
      y++;
      rumble(4);
      resetPlayerPosition();
    }
    else if (y+1 > height-1) {
      // y++;
      // death = true;
    }
    else {
      rumble(level[y+1][x]);
      if (level[y+1][x] != 1) {
        y++;
      }
    }
  }

  // east
  if (dir == 'e') {
    if (level[y][x+1] == 4) {
      x++;
      rumble(4);
      resetPlayerPosition();
    }
    else if (x+1 > width-1) {
      // x++;
      // death = true;
    }
    else {
      rumble(level[y][x+1]);
      if (level[y][x+1] != 1) {
        x++;
      }
    }
  }

  // west
  if (dir == 'w') {
    if (level[y][x-1] == 4) {
      x--;
      rumble(4);
      resetPlayerPosition();
    }
    else if (x-1 < 0) {
      // x--;
      // death = true;
    }
    else {
      rumble(level[y][x-1]);
      if (level[y][x-1] != 1) {
        x--;
      }
    }
  }
}


