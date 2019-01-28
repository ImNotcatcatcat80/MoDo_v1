
#include <Ky040.h>

Ky040 encoder = Ky040(52, 50);
int val;
int prVal;
bool prSwitch = false;
bool encReversed;
String dotLine = "";
int dotLineLength = 100;
bool star = false;

void setup() {
  Serial.begin(115200);
  Serial.println("MoDo is for Moving Dot - v1");
  encoder.setReversed(true);
}

void loop() {
  encReversed = encoder.getReversed();
  if (!prSwitch && digitalRead(40)) {
    // Serial.println("<sw>");
    star = true;
    encoder.setReversed(!encReversed);
  }
  else {
    star = false;
  }
  val = encoder.getVal();

  /*
  // Print an integer for encoder value
  if (val != prVal) {
    Serial.println((String) val);
  }
  */

  // Print a dot ("0") moving along a line of "-"s 
  if (val > dotLineLength) {
    val = dotLineLength;
    encoder.setVal(val);
  }
  if (val < 0) {
    val = 0;
    encoder.setVal(val);
  }
  if (val != prVal || star) {
    dotLine = "";
    for(int n = 0; n <= dotLineLength; n++) {
      if(n == val) {
        if(star) {
          dotLine += "*";
        }
        else {
          dotLine += "0";
        }
      }
      else if (n==0 || n==dotLineLength) {
        dotLine += "+";
      }
      else {
        dotLine += "-";
      }
    }
    Serial.println(dotLine);
  }
  prVal = val;
  prSwitch = digitalRead(40);
}

