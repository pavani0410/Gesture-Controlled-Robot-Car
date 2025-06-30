#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// RF24 radio object
RF24 radio(10, 9); // CE, CSN

// ADXL335 pin definitions
const int xPin = A0; // Analog pin for X axis
const int yPin = A1; // Analog pin for Y axis

// Define a struct to hold the sensor data
struct SensorData {
  int xAxis;
  int yAxis;
};

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(0xF0F0F0F0E1LL); // Set the address
  radio.setPALevel(RF24_PA_LOW); // Set power level
  radio.setDataRate(RF24_250KBPS); // Set data rate
  radio.stopListening(); // Set to transmit mode
  Serial.println("Transmitter setup complete");
}

void loop() {
  SensorData data;
  data.xAxis = analogRead(xPin); // Read X axis value
  data.yAxis = analogRead(yPin); // Read Y axis value

  bool success = radio.write(&data, sizeof(data)); // Send sensor data
  if (success) {
    Serial.println("Data sent successfully");
    Serial.print("X: ");
    Serial.print(data.xAxis);
    Serial.print(" | Y: ");
    Serial.println(data.yAxis);
  } else {
    Serial.println("Failed to send data");
  }

  delay(1000); // Wait 1 second before sending the next data
}