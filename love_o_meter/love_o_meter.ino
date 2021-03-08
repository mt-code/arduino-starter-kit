const int sensorPin = A0;
const float baselineTemp = 20.0;

enum LED {
  RED_1 = 2,
  RED_2 = 3,
  RED_3 = 4
};

void setup() {
  Serial.begin(9600);

  // Init output LED pins
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal / 1024.0) * 5.0;
  float temperature = (voltage - 0.5) * 100;

  Serial.println((String)"Sensor Value: " + sensorVal + ", Volts: " + voltage + ", Temp: " + temperature);

  digitalWrite(LED::RED_1, temperature > baselineTemp + 3 ? HIGH : LOW);
  digitalWrite(LED::RED_2, temperature > baselineTemp + 6 ? HIGH : LOW);
  digitalWrite(LED::RED_3, temperature > baselineTemp + 9 ? HIGH : LOW);

  delay(100);
}
