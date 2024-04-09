# General notes:

## Library installation
It is necessary to install libraries trough ArduinoIDE, without using the VS Code extension, otherwise the libraries won't be installed in the project folder and won't be detected by the IDE (IntelliSense won't work).

# Nicla Sense ME Setup:

## Board manager:
Arduino Mbed OS Nicla Boards

## Libraries:
ArduinoBLE, ArduinoBHY2, Arduino_BHY2Host

## Bosch Sensortec Enviromental Cluster (BSEC) setup
In '\libraries\Arduino_BHY2\src\sensors' change:

```c
#define SENSOR_DATA_FIXED_LENGTH (10)

#define SENSOR_LONG_DATA_FIXED_LENGTH (18)
```
to

```c
#define SENSOR_DATA_FIXED_LENGTH (30)

#define SENSOR_LONG_DATA_FIXED_LENGTH (30)
```

And for this version of Nicla Sense ME, when initializing the SensorBSEC variable we need
to send a legacy macro to the bsec function, like this:

```c
SensorBSEC bsec(SENSOR_ID_BSEC_LEGACY)
```

Otherwise the readings returned from the sensors will always be 0

# Arduino MKR 1010 WiFi Setup:

## Board manager:
Arduino SAMD Boards

## Libraries:
WifiNINA