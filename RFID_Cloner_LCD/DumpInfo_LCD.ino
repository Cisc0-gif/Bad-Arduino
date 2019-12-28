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

/*
LCD1602 MODULE PIN LAYOUT:
LCD1602      Uno/Nano     MEGA
VSS          GND          GND
V0           GND          GND
RW           GND          GND
K            GND          GND
VDD          5V           5V
RS           D12          D12
E            D11          D11
D4           D5           D5
D5           D4           D4
D6           D3           D3
D7           D2           D2
A            3.3V         3.3V
/*
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define RST_PIN         #          // Configurable, see typical pin layout above
#define SS_PIN          #         // Configurable, see typical pin layout above
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  lcd.begin(16,2);
  lcd.print("Booted!");
  mfrc522.PCD_Init();   // Init MFRC522
  delay(4);       // Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    lcd.clear();
    delay(100);
    lcd.print("Waiting For Card");
    delay(100);
    lcd.clear();
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  lcd.print("Scanning Card...");
  // Dump debug info about the card; PICC_HaltA() is automatically called
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  lcd.clear();
  lcd.print("Scan Complete!");
  delay(2000);
}
