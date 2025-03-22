const int outpins[4] = {5, 18, 19, 21};
const int a_inpins[3] = {14, 27, 26};
const int b_inpins[3] = {32, 35, 34};

const byte seven_seg_display[3][4] = {{0, 1, 0, 1}, {0, 1, 1, 1}, {1, 1, 0, 1}};

unsigned int eval = 0;

unsigned int a_current_values[3] = {0, 0, 0};
unsigned int b_current_values[3] = {0, 0, 0};

unsigned int a_previous_values[3] = {0, 0, 0};
unsigned int b_previous_values[3] = {0, 0, 0};

void setup()
{
    for (int a_inpin = 0; 3 > a_inpin; a_inpin++)
    {
        pinMode(a_inpins[a_inpin], INPUT);
    }
    for (int b_inpin = 0; 3 > b_inpin; b_inpin++)
    {
        pinMode(b_inpins[b_inpin], INPUT);
    }
    for (int outpin = 0; 4 > outpin; outpin++)
    {
        pinMode(outpins[outpin], OUTPUT);
    }
}

void loop()
{
    // Update values from inputs
    for (int a_inpin = 0; 3 > a_inpin; a_inpin++)
    {
        if (0 == digitalRead(a_inpins[a_inpin]))
        {
            a_current_values[a_inpin] = 0;
        }
        else
        {
            a_current_values[a_inpin] = 1;
        }
    }
    for (int b_inpin = 0; 3 > b_inpin; b_inpin++)
    {
        if (0 == digitalRead(b_inpins[b_inpin]))
        {
            b_current_values[b_inpin] = 0;
        }
        else
        {
            b_current_values[b_inpin] = 1;
        }
    }

    if (a_current_values != a_previous_values || b_current_values != b_previous_values)
    {
        for (int i = 0; 3 > i; i++)
        {
            if (0 == digitalRead(a_inpins[i]) && (1 == digitalRead(b_inpins[i])))
            {
                eval = 1;
                break;
            }
            else if (1 == digitalRead(a_inpins[i]) && (0 == digitalRead(b_inpins[i])))
            {
                eval = 2;
                break;
            }
            else
            {
                eval = 0;
            }
        }

        for (int p = 0; p < 4; p++)
        {
            digitalWrite(outpins[p], seven_seg_display[eval][p]);
        }

        for (int i = 0; i < 3; i++)
        {
            a_previous_values[i] = a_current_values[i];
        }
        for (int i = 0; i < 3; i++)
        {
            b_previous_values[i] = b_current_values[i];
        }
    }
}
