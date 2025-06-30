#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Motor pins
const int ENA = 3; // Motor A speed control
const int ENB = 9; // Motor B speed control
const int MotorA1 = 4; // Motor A direction control
const int MotorA2 = 5; // Motor A direction control
const int MotorB1 = 6; // Motor B direction control
const int MotorB2 = 7; // Motor B direction control

RF24 radio(10, 9); // CE, CSN

// Define a struct to match the data sent from the transmitter
struct SensorData {
  int xAxis;
  int yAxis;
};

SensorData receiveData;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, 0xF0F0F0F0E1LL); // Address
  radio.setPALevel(RF24_PA_LOW); // Try RF24_PA_HIGH for better range
  radio.setDataRate(RF24_250KBPS); // Try RF24_1MBPS or RF24_2MBPS
  radio.startListening(); // Set to receive mode

  // Set motor pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);
  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);

  Serial.println("Receiver setup complete");
}

void loop() {
  if (radio.available()) {
    radio.read(&receiveData, sizeof(receiveData)); // Read data into struct

    // Process received data to control motors
    int xAxis = receiveData.xAxis;
    int yAxis = receiveData.yAxis;

    Serial.print("X Axis: ");
    Serial.print(xAxis);
    Serial.print(" | Y Axis: ");
    Serial.println(yAxis);

    // Motor control logic
    if (yAxis > 400) {
      // Move Forward
      Serial.println("Moving Forward");
      digitalWrite(MotorA1, LOW);
      digitalWrite(MotorA2, HIGH);
      digitalWrite(MotorB1, HIGH);
      digitalWrite(MotorB2, LOW);
      analogWrite(ENA, 150);
      analogWrite(ENB, 150);
    } else if (yAxis < 320) {
      // Move Backward
      Serial.println("Moving Backward");
      digitalWrite(MotorA1, HIGH);
      digitalWrite(MotorA2, LOW);
      digitalWrite(MotorB1, LOW);
      digitalWrite(MotorB2, HIGH);
      analogWrite(ENA, 150);
      analogWrite(ENB, 150);
    } else if (xAxis < 320) {
      // Turn Left
      Serial.println("Turning Left");
      digitalWrite(MotorA1, HIGH);
      digitalWrite(MotorA2, LOW);
      digitalWrite(MotorB1, HIGH);
      digitalWrite(MotorB2, LOW);
      analogWrite(ENA, 150);
      analogWrite(ENB, 150);
    } else if (xAxis > 400) {
      // Turn Right
      Serial.println("Turning Right");
      digitalWrite(MotorA1, LOW);
      digitalWrite(MotorA2, HIGH);
      digitalWrite(MotorB1, LOW);
      digitalWrite(MotorB2, HIGH);
      analogWrite(ENA, 150);
      analogWrite(ENB, 150);
    } else {
      // Stop
      Serial.println("Stopping");
      digitalWrite(MotorA1, LOW);
      digitalWrite(MotorA2, LOW);
      digitalWrite(MotorB1, LOW);
      digitalWrite(MotorB2, LOW);
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
    }
  } else {
    Serial.println("No data received");
  }

  delay(1000); // Short delay to avoid flooding the serial monitor
}