int pins_leds_TL1[3] = {15, 2, 4};
int pins_leds_TL2[3] = {13, 12, 14};

unsigned char counter = 0;
unsigned char isTL1 = 0x01;
// red, gleen, blue
unsigned char traffic_light[4][3] = {
    {255, 0, 255},
    {0, 0, 255},
    {255, 255, 255},
    {0, 255, 255},
};

void setup()
{
    for (int i = 0; i < 3; i++)
    {
        pinMode(pins_leds_TL1[i], OUTPUT);
        pinMode(pins_leds_TL2[i], OUTPUT);
    }
    pinMode(23, INPUT);
}
void loop()
{
    if (digitalRead(23) == LOW)
    {
        if (counter >= 14)
        {
            counter = 0;
            isTL1 = (~isTL1) & 0x01;
        }
        if (counter < 8)
        {
            if (isTL1 == 0x01)
            {
                for (int n = 0; n < 3; n++)
                {
                    analogWrite(pins_leds_TL1[n], traffic_light[0][n]);
                    analogWrite(pins_leds_TL2[n], traffic_light[3][n]);
                }
            }
            if (isTL1 == 0x00)
            {
                for (int n = 0; n < 3; n++)
                {
                    analogWrite(pins_leds_TL1[n], traffic_light[3][n]);
                    analogWrite(pins_leds_TL2[n], traffic_light[0][n]);
                }
            }
        }
        if ((counter >= 8) && (counter < 14))
        {
            if (isTL1 == 0x01)
            {
                for (int n = 0; n < 3; n++)
                {
                    analogWrite(pins_leds_TL1[n], (counter % 2 == 0) ? traffic_light[1][n] : traffic_light[2][n]);
                    analogWrite(pins_leds_TL2[n], traffic_light[3][n]);
                }
            }
            if (isTL1 == 0x00)
            {
                for (int n = 0; n < 3; n++)
                {
                    analogWrite(pins_leds_TL1[n], traffic_light[3][n]);
                    analogWrite(pins_leds_TL2[n], (counter % 2 == 0) ? traffic_light[1][n] : traffic_light[2][n]);
                }
            }
        }
        counter++;
        delay(500);
    }
    else
    {
        counter = 0;
        isTL1 = 0x01;
        for (int n = 0; n < 3; n++)
        {
            analogWrite(pins_leds_TL1[n], traffic_light[1][n]);
            analogWrite(pins_leds_TL2[n], traffic_light[1][n]);
        }
        delay(500);
        for (int n = 0; n < 3; n++)
        {
            analogWrite(pins_leds_TL1[n], traffic_light[2][n]);
            analogWrite(pins_leds_TL2[n], traffic_light[2][n]);
        }
        delay(500);
    }
}