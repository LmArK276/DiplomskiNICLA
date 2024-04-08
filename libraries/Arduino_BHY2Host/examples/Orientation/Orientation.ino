/* 
 * This sketch shows how an arduino board can act as a host for nicla. 
 * An host board can configure the sensors of nicla and then read their values.
 * The host board should be connected to nicla through the eslov connector.
 * 
 * In this example, the orientation sensor is enabled and its
 * values are periodically read and then printed to the serial channel
 * 
 * NOTE: if Nicla is used as a Shield on top of a MKR board,
 * please use BHY2Host.begin(false, NICLA_AS_SHIELD)
*/

#include "Arduino.h"
#include "Arduino_BHY2Host.h"

SensorOrientation ori(SENSOR_ID_ORI);

void setup()
{
  Serial.begin(115200);
  while(!Serial);

  BHY2Host.begin();

  ori.begin();
}

void loop()
{
  static auto printTime = millis();
  BHY2Host.update();

  if (millis() - printTime >= 1000) {
    printTime = millis();
    Serial.println(String("Orientation values: ") + ori.toString());
  }
}
