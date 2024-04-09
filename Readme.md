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

# Board communication:

## PC passthrough:
We need to change the App.ino file from the examples folder in the ArduinoBHY2 library like this:

Instead of:
```c
BHY2.begin();
```

We will use:
```c
BHY2.begin(NICLA_I2C, NICLA_VIA_ESLOV);
```

Then, we upload this .ino file to the Nicla board.

Afther that, we upload the Passthrough.ino file from the Arduino_BHY2Host library to the Arduino MKR board.

The tools folder is downloaded from https://github.com/arduino/nicla-sense-me-fw
repository.

We can use a Go script to communicate with the Nicla Sense board through the Arduino MKR board from the PC's terminal

Before we do that, it is necessary to build the go script, and for that we need to have GoLang installed.

When we install GoLang, we must navigate to the tools\bhy-controller\src
folder, and the run the go build command to build the tool.

Then, we can use the following commands to read the values from the sensor:

```console
# list available serial ports
./bhy list

# read available sensor data
./bhy sensor read -p /dev/ttyACM2

# continuously read sensor data when available
./bhy sensor read -live -p /dev/ttyACM2

# configure sensor 10 with a sample rate of 1 Hz and latency of 0ms
./bhy sensor config -p /dev/ttyACM2 -sensor 10 -rate 1 -latency 0

# disable sensor 10
./bhy sensor config -p /dev/ttyACM2 -sensor 10 -rate 0 -latency 0
```
For all of this to work we need to replace /dev/ttyACM2 with the appropriate
port we recieved from the ./bhy list command

We can change the sensor we are reading by changing the ID after the -sensor flag.
