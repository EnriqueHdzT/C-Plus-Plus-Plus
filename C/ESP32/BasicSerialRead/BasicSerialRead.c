char key;
const int ledPin = 4;

void setup()
{
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    if (Serial.available() > 0)
    {
        key = Serial.read();
        if (key == '1')
        {
            digitalWrite(ledPin, HIGH);
            Serial.println("LED ON");
        }
        else
        {
            digitalWrite(ledPin, LOW);
            Serial.println("LED OFF");
        }
        delay(1000);
    }
}