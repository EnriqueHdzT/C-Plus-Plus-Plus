int pins_leds[3] = {18, 5, 4};
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
        pinMode(pins_leds[i], OUTPUT);
    }
}
void loop()
{
    for (int n = 0; n < 3; n++)
    {
        digitalWrite(pins_leds[n], traffic_light[0][n]); //
    }
    delay(500 * 8);
    for (int p = 0; p < 6; p++)
    {
        if (p % 2 == 0)
        {
            for (int n = 0; n < 3; n++)
            {
                digitalWrite(pins_leds[n], traffic_light[1][n]); //
            }
        }
        else
        {
            for (int n = 2; n >= 0; n--)
            {
                digitalWrite(pins_leds[n], traffic_light[2][n]); //
            }
        }
        delay(500);
    }
    for (int n = 0; n < 3; n++)
    {
        digitalWrite(pins_leds[n], traffic_light[3][n]); //
    }
    delay(500 * 8);
}