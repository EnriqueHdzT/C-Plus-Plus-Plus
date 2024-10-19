unsigned char randomNumberArray[6] = {0, 0, 0, 0, 0, 0};

void setup()
{
    Serial.begin(115200);
    randomSeed(analogRead(36));
}

void loop()
{
    if (Serial.available() > 0)
    {
        const char command = Serial.read();

        if (command == '1')
        {
            generateRandomNumbers();
            Serial.println("El array de 6 numeros aleatorios es: ");
            for (int index = 0; index < 6; ++index)
            {
                Serial.print(randomNumberArray[index]);
                Serial.print(", ");
            }
            Serial.println();}
        else
        {
            Serial.println("Preciona '1' para generar un nuevo arreglo de 6 numeros aleatorios");
        }
    }
}

void generateRandomNumbers()
{
    for (int index = 0; index < 6; ++index)
    {
        int randomNumber;

        do
        {
            randomNumber = random(1, 56);
        } while (isNumberInArray(randomNumber, randomNumberArray, index));

        randomNumberArray[index] = randomNumber;
    }
}

bool isNumberInArray(int number, const int array[], int size)
{
    for (int index = 0; index < size; ++index)
    {
        if (array[index] == number)
        {
            return true;
        }
    }

    return false;
}
