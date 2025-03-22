#include <LiquidCrystal.h>

// Pin definitions
const int ADC_IN_PIN = 36;

// Initialize the LiquidCrystal object with the pins connected to the LCD
// (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(15, 2, 4, 5, 18, 19);

unsigned int value = 0;
unsigned int duty_cycle = 0;

void setup()
{
    // Initialize the analog pin
    pinMode(ADC_IN_PIN, INPUT);
    
    // Allow time for LCD to power up
    delay(100);

    // Initialize the LCD with 16 columns and 2 rows
    lcd.begin(16, 2);

    // Print initial text to the LCD
    lcd.print("PWM Value:");
    lcd.setCursor(0, 1); // Move to the second line
    lcd.print("Initializing...");
    delay(1000); // Display initialization message for a second
}

void loop()
{
    // Read the ADC value and calculate the duty cycle
    value = analogRead(ADC_IN_PIN);
    duty_cycle = (0x000000FF & ~map(value, 0, 4095, 0, 255));

    // Display the PWM value on the LCD
    lcd.setCursor(0, 1); // Move the cursor to the second line
    lcd.print("                "); // Clear the line (overwrite any previous value)
    lcd.setCursor(0, 1);
    lcd.print(duty_cycle); // Print the calculated PWM value

    // Add a short delay before updating again
    delay(200);
}
