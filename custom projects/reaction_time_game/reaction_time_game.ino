enum BUTTON {
  PLAYER_ONE = 2,
  PLAYER_TWO = 3
};

enum LED {
  TIMED_RED = 4,
  PLAYER_ONE_WIN = 5,
  PLAYER_TWO_WIN = 6
};

enum GAME_STATE {
  REACTION_DELAY,
  WAITING_FOR_INPUT,
  SHOWING_WINNER
};

enum PLAYER {
  NONE, ONE, TWO
};

PLAYER currentWinner = NONE;
GAME_STATE currentState = REACTION_DELAY;

void setup() {
  // Init buttons/leds
  for (int pinNumber = 2; pinNumber < 7; pinNumber++) {
    pinMode(pinNumber, pinNumber >= 4 ? OUTPUT : INPUT);
  }
}

void loop() {
  switch (currentState) {
    case REACTION_DELAY:
      reactionDelay();
      break;

    case WAITING_FOR_INPUT:
      waitForInput();
      break;

    case SHOWING_WINNER:
      showWinner();
      break;
  }
}

// Wait a random interval before lighting the central LED.
void reactionDelay() {
  // Reset current winner.
  currentWinner = NONE;
  
  // Turn off all LEDS.
  digitalWrite(LED::TIMED_RED, LOW);
  digitalWrite(LED::PLAYER_ONE_WIN, LOW);
  digitalWrite(LED::PLAYER_TWO_WIN, LOW);

  // Wait a random interval and then turn on the central LED.
  delay(random(3000, 10000));
  digitalWrite(LED::TIMED_RED, HIGH);

  currentState = WAITING_FOR_INPUT;
}

void waitForInput() {
  if (digitalRead(BUTTON::PLAYER_ONE) == HIGH) {
    currentWinner = ONE;
  } else if (digitalRead(BUTTON::PLAYER_TWO) == HIGH) {
    currentWinner = TWO;
  }

  if (currentWinner != NONE) {
    currentState = SHOWING_WINNER;
  }
}

void showWinner() {
  // Turn off central LED.
  digitalWrite(LED::TIMED_RED, LOW);
  
  switch (currentWinner) {
    case ONE:
      digitalWrite(LED::PLAYER_ONE_WIN, HIGH);
      break;

    case TWO:
      digitalWrite(LED::PLAYER_TWO_WIN, HIGH);
      break;
  }

  delay(3000);
  currentState = REACTION_DELAY;
}
