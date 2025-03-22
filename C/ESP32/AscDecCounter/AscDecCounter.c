const int outpins[7] = {2, 4, 5, 18, 19, 21, 22};
const int dir_button = 15;
const int reset_button = 27;
const int stop_button = 14;
//  7 segments display: a, b, c, d, e, f, g
const byte sev_seg_display[16][7] = {{1, 1, 1, 1, 1, 1, 0},
                                     {0, 1, 1, 0, 0, 0, 0},
                                     {1, 1, 0, 1, 1, 0, 1},
                                     {1, 1, 1, 1, 0, 0, 1},
                                     {0, 1, 1, 0, 0, 1, 1},
                                     {1, 0, 1, 1, 0, 1, 1},
                                     {1, 0, 1, 1, 1, 1, 1},
                                     {1, 1, 1, 0, 0, 0, 0},
                                     {1, 1, 1, 1, 1, 1, 1},
                                     {1, 1, 1, 1, 0, 1, 1},
                                     {1, 1, 1, 0, 1, 1, 1},
                                     {0, 0, 1, 1, 1, 1, 1},
                                     {0, 0, 0, 1, 1, 0, 1},
                                     {0, 1, 1, 1, 1, 0, 1},
                                     {1, 0, 0, 1, 1, 1, 1},
                                     {1, 0, 0, 0, 1, 1, 1}};

unsigned char i = 0;
void setup()
{
    pinMode(dir_button, INPUT);
    pinMode(reset_button, INPUT);
    pinMode(stop_button, INPUT);

    for (int outpin = 0; 8 > outpin; outpin++)
    {
        pinMode(outpins[outpin], OUTPUT);
    }
}

void loop()
{
    int direction = digitalRead(dir_button);
    int reset = digitalRead(reset_button);
    int stop = digitalRead(stop_button);

    if (1 == reset)
    {
        i = 0;
    }

    if (0 == stop)
    {
        if (0 == direction)
        {
            i = (15 < i) ? 0 : i + 1;
        }
        else
        {
            i = (15 < i) ? 15 : i - 1;
        }
        delay(1000);
        decoder_7seg(i);
    }
}

void decoder_7seg(int n)
{
    for (int p = 0; p < 8; p++)
    {
        digitalWrite(outpins[p], sev_seg_display[n][p]);
    }
}