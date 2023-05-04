#include <SPI.h>
#include <MFRC522.h>
#include <Stepper.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include<Servo.h>
//RFID
#define SS_PIN 53
#define RST_PIN 49

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key;

int state = 0;
String stk_status;
String verify_msg;
String rgn_item;
// Init array that will store new NUID
byte nuidPICC[4];
//String id;

//LCD
//int Contrast = 75;
int rs = 32;
int en = 30;
int d4 = 28;
int d5 = 26;
int d6 = 24;
int d7 = 22;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Stepper motor
const int stepsPerRevolution = 512; // change th is to fit the number of steps per revolution for your stepper motor
int stp = 55;
int stpitem1 = 45;
int item = 0, qty = 0;

// initialize the stepper motor library with the number of steps per revolution
Stepper myStepper1(stepsPerRevolution, 34, 36, 35, 37);
Stepper myStepper2(stepsPerRevolution, 38, 40, 39, 41);
Stepper myStepper3(stepsPerRevolution, 42, 44, 43, 45);

//keypad
char input;
char item_ch;
char qty_ch;
char item_placed;
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//Servo
Servo servoX;//moves vertically // pin 23
Servo servoY;//moves horizontally // pin 25
Servo servoGate;//control return-gate state
int sXpin = 23;
int sYpin = 10;
int sGatepin = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //analogWrite(6, Contrast);
  lcd.begin(16, 2);

  //RFID
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

  //Stepper motor
  myStepper1.setSpeed(1000.0 / stpitem1); // 1000.0 is to convert milliseconds to seconds
  myStepper2.setSpeed(1000.0 / stp);
  myStepper3.setSpeed(1000.0 / stp);

  //Servo motor
  servoX.attach(sXpin);
  servoY.attach(sYpin);
  servoGate.attach(sGatepin);

  resetPipePos();
}

void loop() {

  //resetPipePos();

  lcd.clear();
  lcd.print("Punch card!");
  delay(1000);
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;


  // Store NUID into nuidPICC array
  for (byte i = 0; i < 4; i++) {
    nuidPICC[i] = rfid.uid.uidByte[i];
  }


  //Serial.println("Card detected: ");    ///this is the extra part
  printDec(rfid.uid.uidByte, rfid.uid.size);
  delay(1000);
  verify_msg = Serial.readStringUntil('\r');
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(verify_msg);
  delay(1000);
  if (verify_msg != "  Invalid ID  ")//if ID is valid
  {
    while (1)
    {
      showMainMenu();

      input = keypad.getKey();

      if (input == '#' && input != NO_KEY) {
        Serial.println(String(input));
        break;// exit while loop to go to punch card state
      }
      else if (input == '1' && input != NO_KEY) {
        Serial.println(String(input));

        showBorrowMenu();

        do {
          item_ch = keypad.getKey();
        } while (item_ch == NO_KEY);
        if (item_ch != NO_KEY)
        {
          //Serial.println("item: " + String(item_ch));
          item = item_ch - '0';
          Serial.println(String(item_ch));//let python know which is selected
          if (item <= 3 && item != 0)
          {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("how many item?");
            delay(1000);
            do {
              qty_ch = keypad.getKey();
            } while (qty_ch == NO_KEY);
            if (qty_ch != NO_KEY)
            {
              //qty = atoi(qty_ch);
              qty = qty_ch - '0';
              Serial.println(String(qty_ch));//let python know how many item is requested
              delay(1000);
              stk_status = Serial.readStringUntil('\r');//get python response about stock status
              if (stk_status == "ok")
              {
                if (item == 1)
                {
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print(String("Giving " + String(qty_ch) + " Humidity"));
                  for (int i = 0; i < qty; i++) {
                    myStepper1.step(stepsPerRevolution);
                    delay(1000);
                  }
                  //                  myStepper1.step(-stepsPerRevolution);
                  //                  delay(1000);
                }
                else if (item == 2)
                {
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print(String("Giving " + String(qty_ch)));
                  lcd.setCursor(0, 1);
                  lcd.print("Transistor");
                  for (int i = 0; i < qty; i++) {
                    myStepper2.step(stepsPerRevolution);
                    delay(1000);
                  }
                  //                  myStepper2.step(-stepsPerRevolution);
                  //                  delay(1000);
                }
                else if (item == 3)
                {
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print(String("Giving " + String(qty_ch)));
                  lcd.setCursor(0, 1);
                  lcd.print(" Bluetooth");
                  for (int i = 0; i < qty; i++) {
                    myStepper3.step(stepsPerRevolution);
                    delay(1000);
                  }
                  //                  myStepper3.step(-stepsPerRevolution);
                  //                  delay(1000);
                }
              }
              else {
                showQtyExceedMsg(stk_status);
              }
            }
          }
          else
          {
            showErrInvalidItem();
          }
        }
      }
      else if (input == '2' && input != NO_KEY)
      {
        //item return part
        Serial.println(String(input));
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Press * to ");
        lcd.setCursor(0, 1);
        lcd.print("confirm return");
        do {
          item_placed = keypad.getKey();
        } while (item_placed == NO_KEY);

        if (item_placed != NO_KEY && item_placed == '*') {
          lcd.clear();
          lcd.setCursor(2, 0);
          lcd.print("Detecting...");
          lcd.setCursor(0, 1);
          lcd.print("Wait est. 25s");
          delay(1000);
          Serial.println(String(item_placed));//let python know that an item is placed to be returned in the system
          delay(30000);
          rgn_item = Serial.readStringUntil('\r');//get python response about which item is detected
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("  Detected");
          lcd.setCursor(0, 1);
          lcd.print(rgn_item);//print recognised item
          delay(1000);
          fixItemPath(rgn_item);//rotates pipe vertically to allign with recognised item's coveyer belt
          //delay(1000);
          //servoY.write(45);//rotates pipe horizontally to let item slip down to it's slot in the conveyer belt
          delay(1000);

          resetPipePos();//reset pipe position to default position
        }
      }
    }
  }
  else
  {
    return;
  }
  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();


}



//custom functions

/**
   Helper routine to dump a byte array as dec values to Serial.
*/
void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i], DEC);
  }
  Serial.println();


}

void showMainMenu() {
  //read input from keypad, press '1' to borrow or '2' to return item print this in LCD
  lcd.setCursor(0, 0);
  lcd.print("Borrow Rtrn Exit");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("  1     2    #");
}

void showBorrowMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("which item?");//which item?
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("  1  2  3");
}

void showQtyExceedMsg(String stk_status) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Qty exceeds stk!");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print(stk_status + " item in stock");
  delay(1000);
}

void showErrInvalidItem() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("_____Error_____");
  lcd.setCursor(0, 1);
  lcd.print("Invalid item req");
  delay(1000);
}

void fixItemPath(String rgn_item) {
  servoGate.write(45);//opens the return-gate
  delay(2000);
  servoGate.write(0);//closes the return-gate
  if (rgn_item == "Humidity") {
    //servoX.write(45);// pin 23
    myStepper1.step(-stepsPerRevolution);
    delay(1000);
    servoXSlowMove(45, 2000);
    servoYSlowMove(35, 3000);
    Serial.println(rgn_item);
    //returnPosition(2000);
  }
  
  else if (rgn_item == "Transistor")
  {
    //servoX.write(90);
    myStepper2.step(-stepsPerRevolution);
    delay(1000);
    servoXSlowMove(75, 2000);
    servoYSlowMove(35, 3000);
    Serial.println(rgn_item);
  }
  
  else if (rgn_item == "Bluetooth")
  {
    //servoX.write(120);
    myStepper3.step(-stepsPerRevolution);
    delay(1000);
    servoXSlowMove(110, 2000);
    servoYSlowMove(35, 3000);
    Serial.println(rgn_item);
    //returnPosition(2000);
  }
  else {
    Serial.println("cannot recognize " + rgn_item);
  }
}

void resetPipePos() {
  servoYSlowMove(80, 1000);
  servoGate.write(0);
  servoXSlowMove(75, 3000);
}

void servoXSlowMove(int goTo, int del) {
  //how to find current position?
  int current = servoX.read();
  servoXSlowMove2(current, goTo);
  delay(del);
}
void servoXSlowMove2(int startPos, int endPos) {
  if (startPos > endPos) {
    for (int i = startPos; i >= endPos; i--)
    {
      servoX.write(i);
      delay(20);
    }
  } else {
    for (int i = startPos; i <= endPos; i++)
    {
      servoX.write(i);
      delay(20);
    }
  }
}
void servoYSlowMove(int goTo, int del) {
  int endPos = goTo;
  int startPos = servoY.read();
  if (startPos > endPos) {
    for (int i = startPos; i >= endPos; i--)
    {
      servoY.write(i);
      delay(30);
    }
  } else {
    for (int i = startPos; i <= endPos; i++)
    {
      servoY.write(i);
      delay(30);
    }
  }
  delay(del);
}

void returnPosition(int del) {
  servoYSlowMove(120, del);
  servoYSlowMove(90, del);
}
