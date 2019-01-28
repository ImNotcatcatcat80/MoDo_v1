#ifndef Ky040_h
#define Ky040_h

#include "Arduino.h"

class Ky040
{
    public:
        Ky040(int clk, int dt);
        int getVal();
        void setVal(int newVal);
        bool getReversed();
        void setReversed(bool isReversed);

    private:
        int _clk;
        int _dt;
        int pinA;
        int pinB;
        int encoderPos;
        int aVal;
        int pinALast;
        boolean bCW;
        boolean reversed;
        
};

#endif