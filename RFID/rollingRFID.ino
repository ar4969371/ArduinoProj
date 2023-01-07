#include <MFRC522.h>

const int RST_PIN = 9;  // Pin 9 on the Arduino Uno
const int SS_PIN = 10;  // Pin 10 on the Arduino Uno
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  SPI.begin();  // Initialize SPI communication
  mfrc522.PCD_Init();  // Initialize MFRC522
  Serial.println("Ready to read RFID tag...");
}

void loop() {
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Dump debug info about the card; PICC_HaltA() is automatically called
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

  // Increment the value stored on the tag
  byte block = 4;  // Select block 4 (0-based)
  byte data[16];   // Create a buffer to store the data
  mfrc522.MIFARE_Read(block, data, &(mfrc522.uid));  // Read the block
  int value = data[0];  // Get the value stored in the block
  value++;  // Increment the value
  data[0] = value;  // Store the incremented value in the buffer
  mfrc522.MIFARE_Write(block, data, &(mfrc522.uid));  // Write the block back to the tag

  // Dump the data for debugging purposes
  for (int i = 0; i < 16; i++) {
    Serial.print(data[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}
