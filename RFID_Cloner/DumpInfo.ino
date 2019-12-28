/*
RC522 MODULE PIN LAYOUT:
RC522         Uno/Nano     MEGA
SDA           D10          D9
SCK           D13          D52
MOSI          D11          D51
MISO          D12          D50
IRQ           N/A          N/A
GND           GND          GND
RST           D9           D8
3.3V          3.3V         3.3V
*/
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         #          // Configurable, see typical pin layout above
#define SS_PIN          #         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  delay(4);       // Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  Serial.print("Scanning Card...");
  // Dump debug info about the card; PICC_HaltA() is automatically called
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  Serial.print("Scan Complete!");
  delay(2000);
}
