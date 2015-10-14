/*
LEVEL CONVERTER
 Jeff Thompson | 2015 | www.jeffreythompson.org
 
 Generates a 2D text array for a rougelike based
 on an image file, for "You Have Been Blinded..."
 
 RULES:
 (0,0,0)       = wall
 (255,255,255) = floor
 (255,0,0)     = player
 (0,255,0)     = beach
 (0,0,255)     = ocean
 
 */

void setup() {

  // load image file
  PImage img = loadImage("../Level_Version2.0.gif");
  println("Level dimensions: " + img.width + " x " + img.height);

  // store level as array of strings (plus the start and end { };
  String[] level = new String[img.height + 1];
  level[0] = "{";

  // load image pixels and iterate
  img.loadPixels();
  for (int y = 0; y<img.height; y++) {

    // start each row with { then go through row's px 
    String row = "{";
    for (int x = 0; x<img.width; x++) {

      // check color and add to row
      color c = img.pixels[x + y*img.width];
      if (c == color(0)) {                          // wall
        row += "1";
      }
      else if (c == color(255)) {                   // floor
        row += "0";
      }
      else if (c == color(255, 0, 0)) {             // player (just print position)
        row += "0";
        println("Player start:     " + x + ", " + y);
      }
      else if (c == color(0, 255, 0)) {             // beach
        row += "2";
      }
      else if (c == color(0, 0, 255)) {             // ocean
        row += "3";
      }

      // if we're at the last entry of the line...
      if (x == img.width-1) {

        // end row with the }
        row += "}";

        // if this isnt' the last row, also append a comma
        if (y != level.length-2) {
          row += ",";
        }

        // add to the array and reset the row
        level[y] = row;
        row = "{";
      }

      // append a comma between each entry in the row
      else {
        row += ", ";
      }
    }
  }
  img.updatePixels();

  // finish the array and save to text file
  level[level.length-1] = "};";
  saveStrings("../level.txt", level);

  // display the level!
  noSmooth();                                      // preserve hard edges on the level file...
  size(img.width*8, img.height*8);                 // set size to enlarged image
  image(img, 0, 0, img.width*8, img.height*8);     // resize
  println("DONE!");
}