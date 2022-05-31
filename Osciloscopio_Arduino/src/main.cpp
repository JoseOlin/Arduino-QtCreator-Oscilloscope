#include <Arduino.h>

int inputs[6];
int inputsReaded = 6;
int inputs_pins[6] = {A0, A1, A2, A3, A4, A5 };
char* inputs_headers[6] = {"A0", "A1", "A2", "A3", "A4", "A5"};

/*int input2;
int input3;
int input4;
int input5;
int input6;
*/

void setup()
{
    //Serial.begin(115200);
    //Serial.begin(250000);
    //Serial.begin(300000);
    //Serial.begin(400000);
    Serial.begin(500000);
    //Serial.begin(600000);
}

void loop()
{
    //Serial.print("Inputs: ");
    for(int index = 0; index < inputsReaded; index++)
    {
        Serial.print(inputs_headers[index]); Serial.print(": ");
        inputs[index] = analogRead(inputs_pins[index]);
        Serial.print(inputs[index]);

        if(index < inputsReaded-1)
            Serial.print(", ");
        else
            Serial.println(" ");
    }
    delayMicroseconds(10);

    //Serial.print("A0: ");
}
