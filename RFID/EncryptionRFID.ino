#include <Crypto.h>
#include <AES.h>
#include <MFRC522.h>

#define SS_PIN 53
#define RST_PIN 49

AES128 aes;
const byte key[16] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16};
const byte iv[16] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16};

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

void setup() {
  Serial.begin(9600); // Initialize serial communication
  SPI.begin(); // Initialize SPI communication
  mfrc522.PCD_Init(); // Initialize MFRC522
  aes.setKey(key, sizeof(key));
  aes.setIV(iv, sizeof(iv));
  Serial.println("Ready to scan RFID tag");
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

  // Encrypt UID
  byte ciphertext[16];
  encryptData(mfrc522.uid.uidByte, ciphertext, mfrc522.uid.size);

  // Print encrypted UID
  Serial.print("Encrypted UID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
     Serial.print(ciphertext[i] < 0x10 ? " 0" : " ");
     Serial.print(ciphertext[i], HEX);
  }
  Serial.println();

  // Decrypt encrypted UID
  byte plaintext[16];
  decryptData(ciphertext, plaintext, mfrc522.uid.size);

  // Print decrypted UID
  Serial.print("Decrypted UID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
     Serial.print(plaintext[i] < 0x10 ? " 0" : " ");
     Serial.print(plaintext[i], HEX);
  }
  Serial.println();

  delay(3000); // delay to see the message before reset
}

void encryptData(byte* plaintext, byte* ciphertext, int length) {
  aes.encrypt(plaintext, ciphertext, length);
}

void decryptData(byte* ciphertext, byte* plaintext, int length) {
  aes.decrypt(ciphertext, plaintext, length);
}
