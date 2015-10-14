
/*
LEVEL CONVERTER
 Jeff Thompson | 2015 | www.jeffreythompson.org
 
 Generates a 2D text array for a rougelike based
 on an image file, for "You Have Been Blinded..."
 
 COLOR          TILE #    TERRAIN
 (255,255,0)    0         floor
 (0)            1         wall
 (0,255,0)      2         rubble
 (0,0,255)      3         water
 (255)          4         respawn
 (255,0,0)      0         player
 
 */
 
 String levelFile =   "YHBBv2-lvl1.png";
 int imgWidth =       20;                  // level image size in px
 int imgHeight =      20;
 
 int resizeFactor =   30;                  // scale redrawn level onscreen
 
 
 void settings() {
   size(imgWidth*resizeFactor, imgHeight*resizeFactor);
   noSmooth();
 }
 

void setup() {

  // load image file
  PImage img = loadImage("../" + levelFile);
  println("Level dimensions: " + img.width + " x " + img.height);

  // store level as array of strings (plus the start and end { };
  String[] level = new String[img.height + 1];
  level[0] = "byte level[height][width] = {";

  // load image pixels and iterate
  img.loadPixels();
  for (int y = 1; y<img.height; y++) {

    // start each row with { then go through row's px 
    String row = "  {";
    for (int x = 0; x<img.width; x++) {

      // check color and add to row
      color c = img.pixels[x + y*img.width];
      if (c == color(255,255,0)) {            // floor
        row += "0";
      }
      else if (c == color(255, 0, 0)) {       // player (print position, set to floor)
        row += "0";
        println("Player start:     " + x + ", " + y);
      }
      else if (c == color(0)) {               // wall
        row += "1";
      }
      else if (c == color(0, 255, 0)) {       // rubble
        row += "2";
      }
      else if (c == color(0, 0, 255)) {       // water
        row += "3";
      }
      else if (c == color(255)) {             // respawn
        row += "4";
        println("Respawn at:       " + x + ", " + y);
      }
      else {                                  // something else? default = floor...
         row += "0";
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
  image(img, 0, 0, img.width*resizeFactor, img.height*resizeFactor);     // resize
  println("DONE!");
}