#include "Nicla_System.h"
#include "Arduino_BHY2.h"

SensorBSEC bsec(SENSOR_ID_BSEC_LEGACY);

void setup() {
  Serial.begin(115200, SERIAL_8N1);
  nicla::begin();
  BHY2.begin(NICLA_I2C);
  bsec.begin();
}

void loop() {
  
  BHY2.update();

  static auto lastCheck = millis();

  if(millis() - lastCheck >= 1000){
    lastCheck = millis();
    Serial.println(bsec.toString());
  }
}
