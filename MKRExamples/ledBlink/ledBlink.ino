#include <WiFiNINA.h>
#include <utility/wifi_drv.h>

WiFiDrv driver;

void setup(){
    driver.pinMode(25, OUTPUT);
    driver.pinMode(26, OUTPUT);
    driver.pinMode(27, OUTPUT);
}

void loop(){
    driver.analogWrite(25, HIGH); //GREEN
    driver.analogWrite(26, LOW); //RED
    driver.analogWrite(27, LOW); //BLUE

    delay(1000);

    driver.analogWrite(25, LOW); //GREEN
    driver.analogWrite(26, HIGH); //RED
    driver.analogWrite(27, LOW); //BLUE

    delay(1000);

    driver.analogWrite(25, LOW); //GREEN
    driver.analogWrite(26, LOW); //RED
    driver.analogWrite(27, HIGH); //BLUE

    delay(1000);


}