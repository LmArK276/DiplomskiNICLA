#include "Arduino_BHY2.h"

SensorXYZ accelerometer(SENSOR_ID_ACC);
SensorXYZ gyro(SENSOR_ID_GYRO);

void setup() {
  Serial.begin(115200, SERIAL_8N1);
  BHY2.begin();

  accelerometer.begin();
  gyro.begin();
}

void loop() {
  static auto lastCheck = millis();

  //Update should be polled continuously
  BHY2.update();

  if(millis() - lastCheck >= 1000){
    lastCheck = millis();

    Serial.println(String("acceleration: ") + accelerometer.toString());
    Serial.println(String("gyroscope: ") + gyro.toString());
  }
}
