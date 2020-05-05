#include <Wire.h>

int led = D6;

void setup() {
    pinMode(led, OUTPUT); // initalise the LED
    digitalWrite(led, LOW); // initalise the led voltage to 0
    
    Wire.begin(0x40); // Initalise argon device as a slave on address 40
    
    Wire.onReceive(signalDetected); // call signalDetected when the signal is recieved from the master device
    
}

void signalDetected(int numOfBytes)
{
    char c = Wire.read(); // read the value from the RPI
    
    if (c == 1)
    {
        digitalWrite(led, HIGH); // turn the led on
    }
    else
    {
        digitalWrite(led, LOW); // turn the led off
    }
}

void loop() {
    delay(500);
}