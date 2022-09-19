#include <Arduino.h>

/*
    I, Wael Harba, student number 000787960, certify that what I am submitting is my own work;
    that I have not copied it from any other source. I also certify that I have not allowed my work to be copied by others.
*/

void setup()
{
  // configure the USB serial monitor
  Serial.begin(115200);
}

float convertToAnalogVoltage(int analogRead, int numberOfBits, float desiredOutputVoltage)
{
  float analogVoltage = (analogRead * desiredOutputVoltage) / numberOfBits;

  return analogVoltage;
}

float calculateTemp(float analogVoltage)
{
  float calculatedTemp = (analogVoltage * 50) / 3.3;

  return calculatedTemp;
}

String getTemperatureJudgement(float temp)
{
  if (temp < 10)
  {
    return "Cold!";
  }
  else if (temp >= 10 && temp < 15)
  {
    return "Cool";
  }
  else if (temp >= 15 && temp < 25)
  {
    return "Perfect";
  }
  else if (temp >= 25 && temp < 30)
  {
    return "Warm";
  }
  else if (temp >= 30 && temp < 35)
  {
    return "Hot";
  }
  else if (temp >= 35)
  {
    return "Too Hot!";
  }

  return "Unkown";
}

void loop()
{
  int iVal;

  // read digitized value from the D1 Mini's A/D convertor
  iVal = analogRead(A0);

  float valueInVoltage = convertToAnalogVoltage(iVal, 1023, 3.3);

  // print value to the USB port
  Serial.println("Digitized Value of " + String(iVal) + " is equivalent to an Analog Voltage = " + valueInVoltage + "V");

  // wait 2 seconds
  delay(2000);

  float temp = calculateTemp(valueInVoltage);

  // print temperature judgement
  Serial.println("Digitized Value of " + String(iVal) + " is equivalent to a temperature input of = " + temp + " deg. C which is " + getTemperatureJudgement(temp));
}
