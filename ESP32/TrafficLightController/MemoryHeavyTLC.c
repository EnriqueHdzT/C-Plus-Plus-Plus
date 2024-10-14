int pins_leds[3] = {18, 5, 4};
byte traffic_light[22][3] = {{1, 0, 0},
                             {1, 0, 0},
                             {1, 0, 0},
                             {1, 0, 0},
                             {1, 0, 0},
                             {1, 0, 0},
                             {1, 0, 0},
                             {1, 0, 0},
                             {1, 1, 0},
                             {0, 1, 0},
                             {1, 1, 0},
                             {0, 1, 0},
                             {1, 1, 0},
                             {0, 1, 0},
                             {0, 0, 1},
                             {0, 0, 1},
                             {0, 0, 1},
                             {0, 0, 1},
                             {0, 0, 1},
                             {0, 0, 1},
                             {0, 0, 1},
                             {0, 0, 1}};

void setup()
{
    for (int i = 0; i < 3; i++)
    {
        pinMode(pins_leds[i], OUTPUT);
    }
}
void loop()
{
    for (int p = 0; p < 22; p++)
    {
        for (int n = 0; n < 3; n++)
        {
            digitalWrite(pins_leds[n], traffic_light[p][n]); //
        }
        delay(500);
    }
}