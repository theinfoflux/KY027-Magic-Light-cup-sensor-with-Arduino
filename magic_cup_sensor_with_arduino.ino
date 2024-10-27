// Pin definitions
const int sensorPin = 8;  // KY-027 sensor signal pin connected to digital pin 8
const int ledPin = 9;    // Onboard LED on most Arduino boards (or you can use an external LED)

const int sensorPin2 = 3;
const int ledPin2 = 4;
// Variables to store the sensor state
int sensorState = 0;
int lastSensorState = 0;  // Previous state of the sensor

int sensorState2 = 0;
int lastSensorState2 = 0;  // Previous state of the sensor
// Timing variables
unsigned long previousMillis = 0;
const long interval = 100; // Interval at which to read the sensor and update the LED (in milliseconds)

void setup() {
  pinMode(sensorPin, INPUT);  // Set the sensor pin as an input
  pinMode(ledPin, OUTPUT);    // Set the LED pin as an output
  pinMode(sensorPin2, INPUT);  // Set the sensor pin as an input
  pinMode(ledPin2, OUTPUT);    // Set the LED pin as an output
  Serial.begin(9600);         // Initialize serial communication for debugging
}

void loop() {
  // Get the current time
  unsigned long currentMillis = millis();

  // Check if it's time to read the sensor state and update the LED
  if (currentMillis - previousMillis >= interval) {
    // Save the last time you read the sensor state
    previousMillis = currentMillis;

    // Read the sensor state
    sensorState = digitalRead(sensorPin);
   sensorState2 = digitalRead(sensorPin2);
    // Print the sensor state to the serial monitor
    Serial.print("Sensor State: ");
    Serial.println(sensorState);

    // If the sensor pins open (HIGH state), turn on the LED
    if (sensorState == HIGH) {
      digitalWrite(ledPin, LOW);
    } else {
      // If LOW state, turn off the LED
      digitalWrite(ledPin, HIGH);
    }

      if (sensorState2 == HIGH) {
      digitalWrite(ledPin2, LOW);
    } else {
      // If LOW state, turn off the LED
      digitalWrite(ledPin2, HIGH);
    }
  }
}
