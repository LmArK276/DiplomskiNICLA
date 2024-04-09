#include "Arduino_BHY2.h"

SensorActivity activity(SENSOR_ID_AR);

void setup(){
    Serial.begin(115200, SERIAL_8N1);

    BHY2.begin();
    activity.begin();
}

void loop(){
    static auto lastCheck = millis();
    BHY2.update();

    if(millis() - lastCheck >= 1000){
        lastCheck = millis();

        Serial.println(String("Activity info") + activity.toString());
    }
}


