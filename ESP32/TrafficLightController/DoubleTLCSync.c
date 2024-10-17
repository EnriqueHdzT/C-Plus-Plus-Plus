int pins_leds_TL1[3] = {18, 5, 4};
int pins_leds_TL2[3] = {25, 26, 14};

unsigned int counter = 0;
unsigned char isTL1 = 0x01;

byte traffic_light[22][3] = {
    {1, 0, 0},
    {1, 1, 0},
    {0, 1, 0},
    {0, 0, 1},
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
                    digitalWrite(pins_leds_TL1[n], traffic_light[0][n]);
                    digitalWrite(pins_leds_TL2[n], traffic_light[3][n]);
                }
            }
            if (isTL1 == 0x00)
            {
                for (int n = 0; n < 3; n++)
                {
                    digitalWrite(pins_leds_TL1[n], traffic_light[3][n]);
                    digitalWrite(pins_leds_TL2[n], traffic_light[0][n]);
                }
            }
        }
        if ((counter >= 8) && (counter < 14))
        {
            if (isTL1 == 0x01)
            {
                for (int n = 0; n < 3; n++)
                {
                    digitalWrite(pins_leds_TL1[n], (counter % 2 == 0) ? traffic_light[1][n] : traffic_light[2][n]);
                    digitalWrite(pins_leds_TL2[n], traffic_light[3][n]);
                }
            }
            if (isTL1 == 0x00)
            {
                for (int n = 0; n < 3; n++)
                {
                    digitalWrite(pins_leds_TL1[n], traffic_light[3][n]);
                    digitalWrite(pins_leds_TL2[n], (counter % 2 == 0) ? traffic_light[1][n] : traffic_light[2][n]);
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
            digitalWrite(pins_leds_TL1[n], 1);
            digitalWrite(pins_leds_TL2[n], 1);
        }
        delay(500);
        for (int n = 0; n < 3; n++)
        {
            digitalWrite(pins_leds_TL1[n], 0);
            digitalWrite(pins_leds_TL2[n], 0);
        }
        delay(500);
    }
}