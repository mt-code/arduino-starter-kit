bool isAnimating = false;

enum LED {
  RED_ONE = 5,
  RED_TWO = 4,
  GREEN = 3
};

void setup() {
  pinMode(5, OUTPUT); // Red LED
  pinMode(4, OUTPUT); // Red LED
  pinMode(3, OUTPUT); // Green LED
  pinMode(2, INPUT);
}

void loop() {
  bool isToggled = digitalRead(2) == HIGH;

  if (isToggled && !isAnimating) {
    animateLights();
  }
}

void animateLights() {
  isAnimating = true;
  
  // Enable RED_ONE
  setLedState(LED::RED_ONE, true);
  delay(1000);

  // Disable RED_ONE, enable RED_TWO
  setLedState(LED::RED_ONE, false);
  setLedState(LED::RED_TWO, true);
  delay(1000);

  setLedState(LED::RED_TWO, false);
  flickerLed(LED::GREEN, 200);

  // Enable RED_TWO
  setLedState(LED::RED_TWO, true);
  delay(1000);

  // Disable RED_TWO, enabled RED_ONE
  setLedState(LED::RED_TWO, false);
  setLedState(LED::RED_ONE, true);
  delay(1000);

  // Disable RED_ONE
  setLedState(LED::RED_ONE, false);

  isAnimating = false;
}

void flickerLed(int led, int delayTime) {
  for (int i = 0; i < 5; i++) {
    digitalWrite(led, HIGH);
    delay(delayTime);
    digitalWrite(led, LOW);
    delay(delayTime);
  }
}

void setLedState(int led, bool shouldEnable) {
  if (shouldEnable) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
