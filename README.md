# Analog Input and Output with ESP32
This code demonstrates how to read analog input from ADC (Analog-to-Digital Converter) and generate analog output using DAC (Digital-to-Analog Converter) on an ESP32 microcontroller.

## Features:
* Reads analog voltage from ADC pin 34 (GPIO 34) using ADC1.
* Generates analog voltage on DAC pin 25 (GPIO 25) using DAC1.
* Outputs the analog voltage to an external component or sensor.

## How to Use Example

### Hardware Required
* A development board with ESP32 SoC (e.g., ESP32-DevKitC, ESP-WROVER-KIT, etc.)
* A USB cable for Power supply and programming

### Configure the Project
* Connect an analog sensor or voltage source to GPIO 34 for input.
* Connect an analog output component or voltmeter to GPIO 25 for output.

### Build and Flash

Run `idf.py -p PORT flash monitor` to build, flash and monitor the project.

(To exit the serial monitor, type ``Ctrl-]``.)

## Example Output:

````bash

- The code reads the analog voltage from GPIO 34 and prints it to the console.
- The code generates variable analog voltage on GPIO 25 based on the ADC reading.
- The voltage output will vary between 0 to 3.3V.

````
### Notes:
* The ADC reading is printed every 100ms.
* The DAC output is updated every 1000ms, generating a voltage between 0 to 3.3V based on the ADC reading.
