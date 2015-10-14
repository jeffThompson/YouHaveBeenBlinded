
// display the level as you play in the Serial Monitor window
// NOTE: this option is only for debugging on a regular Arduino - will
// not compile for the ATtiny chip (comment out for upload when done)
/*
void printLevel() {

  // space between images of level
  Serial.println();
  Serial.println();

  // draw level!
  for (int ly = 0; ly < height; ly++) {
    for (int lx = 0; lx < width; lx++) {

      // player position
      if (ly == y && lx == x) {
        Serial.print(" X ");
      }

      // tiles
      else {
        if (level[ly][lx] == 0) {          // floor
          Serial.print("   ");
        }
        else if (level[ly][lx] == 1) {     // walls
          Serial.print(" + ");
        }
        else if (level[ly][lx] == 2) {     // sand
          Serial.print(" . ");
        }
        else if (level[ly][lx] == 3) {     // rubble
          Serial.print(":::");
        }
        else if (level[ly][lx] == 4) {     // respawn point
          Serial.print("[ ]");
        }
      }
    }
    Serial.println();
  }
}
*/


