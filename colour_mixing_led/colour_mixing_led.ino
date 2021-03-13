const int greenLedPin = 9;
const int redLedPin = 10;
const int blueLedPin = 11;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
    Serial.begin(9600);

    pinMode(greenLedPin, OUTPUT);
    pinMode(redLedPin, OUTPUT);
    pinMode(blueLedPin, OUTPUT);
}

void loop() {
    redSensorValue = analogRead(redSensorPin);
    delay(5);
    greenSensorValue = analogRead(greenSensorPin);
    delay(5);
    blueSensorValue = analogRead(blueSensorPin);
    
    Serial.println((String) "Red Sensor Values \tred: " + redSensorValue + "\tgreen: " + greenSensorValue + "\tblue: " + blueSensorValue);

    redValue = redSensorValue / 4;
    greenValue = greenSensorValue / 4;
    blueValue = blueSensorPin / 4;

    Serial.println((String)"Mapped Sensor Values \tred: " + redValue + "\tgreen: " + greenValue + "\tblue: " + blueValue);
    
    analogWrite(redLedPin, redValue);
    analogWrite(greenLedPin, greenValue);
    analogWrite(blueLedPin, blueValue);

    delay(100);
}
