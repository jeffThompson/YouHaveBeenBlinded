
// rumble the motor for different actions and terrains
void rumble(int tile) {

  // FLOOR - a short pit-pat
  if (tile == 0) {
    digitalWrite(motor, HIGH);
    if (ledFeedback) {
      digitalWrite(led, HIGH);
    }
    delay(150);
    digitalWrite(motor, LOW);
    if (ledFeedback) {
      digitalWrite(led, LOW);
    }
    delay(50);
    digitalWrite(motor, HIGH);
    if (ledFeedback) {
      digitalWrite(led, HIGH);
    }
    delay(150);
    digitalWrite(motor, LOW);
    if (ledFeedback) {
      digitalWrite(led, LOW);
    }
  }

  // WALL - nothing (formerly an abrupt bump)
  else if (tile == 1) {
    // digitalWrite(motor, HIGH);
    // delay(200);
    // digitalWrite(motor, LOW);
  }

  // SAND - dragging feet, slushy
  else if (tile == 2) {
    for (int i=150; i<225; i++) {      // shuffle
      analogWrite(motor, i);
      if (ledFeedback) {
        analogWrite(led, i);
      }
      delay(5);
    }
    digitalWrite(motor, LOW);
    if (ledFeedback) {
      digitalWrite(led, LOW);
    }
    delay(100);
    digitalWrite(motor, HIGH);         // bump
    if (ledFeedback) {
      digitalWrite(led, HIGH);
    }
    delay(30);
    digitalWrite(motor, LOW);
    if (ledFeedback) {
      digitalWrite(led, LOW);
    }
  }

  // RUBBLE
  else if (tile == 3) {
    for (int i=0; i<5; i++) {
      digitalWrite(motor, HIGH);
      if (ledFeedback) {
        digitalWrite(led, HIGH);
      }
      delay(50);
      digitalWrite(motor, LOW);
      if (ledFeedback) {
        digitalWrite(led, LOW);
      }
      delay(50);
    }
  }

  // RESPAWN!
  else if (tile == 4) {
    for (int i=255; i>60; i--) {       // fall down
      analogWrite(motor, i);
      if (ledFeedback) {
        analogWrite(led, i);
      }  
      delay(20);
    }

    // sharp "bump" as we "land" while fading out the led fully
    digitalWrite(motor, HIGH);
    if (ledFeedback) {
      digitalWrite(led, HIGH);
    }
    delay(250);
    digitalWrite(motor, LOW);
    if (ledFeedback) {
      digitalWrite(led, LOW);
    }
    resetPlayerPosition();
  }
}


