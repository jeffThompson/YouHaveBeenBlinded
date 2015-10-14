
// read buttons 1-4 (N-W clockwise)
char checkButtons() {
  int b = analogRead(buttons);

  // 1: NORTH
  if (b > 400 && b < 700) {
    return 'n';
  }

  // 2: EAST
  else if (b > 700 && b <= 1024) {
    return 'e';
  }

  // 3: SOUTH
  else if (b < 400 && b > 300) {
    return 's';
  }

  // 4: WEST
  else if (b < 300 && b > 50) {
    return 'w';
  }

  // nothing? return a space
  return ' ';
}


