const int ADC_IN_PIN = 36;
const int LED_OUT_PIN = 23;
unsigned int value = 0;
unsigned int duty_cycle = 0;

void setup()
{
    pinMode(ADC_IN_PIN, INPUT);
    Serial.begin(9600);
}
void loop()
{
    value = analogRead(ADC_IN_PIN);
    duty_cycle = (0x000000FF & ~map(value, 0, 4095, 0, 255));
    analogWrite(LED_OUT_PIN, duty_cycle);
    delay(15);
    Serial.println("The PWM value is = " + String(duty_cycle));
    delay(300);
}