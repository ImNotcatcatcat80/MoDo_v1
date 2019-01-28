#include "Arduino.h"
#include "Ky040.h"

Ky040::Ky040(int clk, int dt)
{
    _clk = clk;
    _dt = dt;
    pinMode(_clk, INPUT);
    pinMode(_dt, INPUT);
    pinALast = digitalRead(_clk);
    encoderPos = 0;
    reversed = false;
    setReversed(false);
}

int Ky040::getVal()
{
    aVal = digitalRead(pinA);
    if(aVal != pinALast) {
        if(digitalRead(pinB) != aVal) {
            encoderPos++;
            bCW = true;
        }
        else
        {
            encoderPos--;
            bCW = false;
        }     
    }
    pinALast = aVal;
    return encoderPos;
}

void Ky040::setVal(int newVal)
{
    encoderPos = newVal;
}

bool Ky040::getReversed()
{
    return reversed;
}

void Ky040::setReversed(bool isReversed)
{
    reversed = isReversed;
    if(!reversed) {
        pinA = _clk;
        pinB = _dt;
    }
    else {
        pinA = _dt;
        pinB = _clk;
    }
}
