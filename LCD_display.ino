/*  Your LCD Name
 *  Application for displaying a text on 16x2 LCD display (HD44780) with Arduino Nano.
 *  Could be used for similar types of displays (for instance 20x4 LCD).
 *  User enters his name through serial console and his name is then displayed on LCD screen.

    Wiring instructions:
    ====================
     [LCD - Arduino Nano]
     1. VSS Arduino GND
     2. VDD - Arduino 5V
     3. V0 (contrast) - 10k Ohm potentiometer (connect one wire to center pin and the other to left/right pin) - Arduino GND
     4. RS - Arduino D9
     5. RW - Arduino D8
     6. E (enable) - Arduino D7
     7. D0 (data 0) - no connection   
     8. D1 - no connection   
     9. D2 - no connection   
     10. D3 - no connection  
     11. D4 - Arduino D5
     12. D5 - Arduino D4
     13. D6 - Arduino D3
     14. D7 - Arduino D2
     15. A (backlight +) - 220 Ohm resistor (40 Ohm min.) - Arduino D6
     16. K (backlight GND) - GND Arduino pin*

    If there is no text displayed, LCD module may be out of sync with Arduino.
    In that case press the reset button on your Arduino to synchronize (it may take a couple of resets).

    Source: https://www.hacktronics.com/Tutorials/arduino-character-lcd-tutorial.html
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(9, 8, 7, 5, 4, 3, 2);

int backLight = 6;    // Arduino pin D6 will control the backlight

String user_input;    // Variable when input text will be stored.

void setup()
{
  // Open serial console.
  Serial.begin(9600);
  Serial.print("Vnesi svoje ime: ");   // Print instructions to enter user's name to serial console.

  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH);       // Turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  lcd.begin(16,2);                     // Columns and rows.  use 16,2 for a 16x2 LCD.
  lcd.clear();                         // Start with a blank screen...
  lcd.setCursor(0,0);                  // Set cursor to column 0, row 0 (the beginning of the first line).
  lcd.print("Codeweek demo...");       // Text displayed in a first line.
  lcd.setCursor(0,1);                  // Set cursor to column 0, row 1 (the beginning of the second line).
  lcd.print("LCD ZASLON 16x2.");       // Text displayed in a second line.
}

void loop()
{
  while(Serial.available()) {
    user_input = Serial.readString();           // Read the incoming data as string.
    
    user_input.remove(user_input.length()-2);   // Remove last two character from input string.
    Serial.println(user_input);                 // Print input string to serial console.

    lcd.clear(); 
    lcd.setCursor(0, 0);
    lcd.print("Pozdravljen,");
    lcd.setCursor(0, 1);
    lcd.print(user_input);                      // Display input string on LCD display.
    Serial.print("Ponovno vnesi svoje ime: ");
  }
}
