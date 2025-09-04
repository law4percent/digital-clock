# Arduino Digital Clock with RTC DS3231 and TM1637 Display

A simple digital clock project using Arduino, DS3231 Real-Time Clock module, and TM1637 4-digit 7-segment display.

## Features

- 12-hour time format display (HHMM)
- Real-time clock with DS3231 RTC module for accurate timekeeping
- Bright 4-digit 7-segment display with colon separator
- Battery backup support (DS3231 maintains time during power loss)
- Serial monitor debugging output

## Components Required

- Arduino Uno/Nano/Pro Mini
- DS3231 RTC Module
- TM1637 4-Digit 7-Segment Display
- Jumper wires
- Breadboard (optional)
- CR2032 battery (for DS3231 backup - usually included with module)

## Circuit Connections

### TM1637 Display Connections
| TM1637 Pin | Arduino Pin |
|------------|-------------|
| VCC        | 5V          |
| GND        | GND         |
| CLK        | Digital Pin 9  |
| DIO        | Digital Pin 10 |

### DS3231 RTC Module Connections
| DS3231 Pin | Arduino Pin |
|------------|-------------|
| VCC        | 5V          |
| GND        | GND         |
| SDA        | A4 (Uno/Nano) |
| SCL        | A5 (Uno/Nano) |

## Required Libraries

Install these libraries through the Arduino IDE Library Manager:

1. **RTClib** by Adafruit
   - Go to Sketch → Include Library → Manage Libraries
   - Search for "RTClib" and install the Adafruit version

2. **TM1637Display** by Avishay Orpaz
   - Search for "TM1637Display" in Library Manager
   - Install the library by Avishay Orpaz

## Setup Instructions

1. **Hardware Assembly:**
   - Connect the components according to the wiring diagram above
   - Ensure the DS3231 has a CR2032 battery installed for backup
   - Double-check all connections

2. **Software Setup:**
   - Install required libraries
   - Upload the code to your Arduino
   - Open Serial Monitor (115200 baud) to check for any errors

3. **Setting the Time:**
   - The DS3231 will maintain the time once set
   - If you need to set the initial time, you can use the DS3231 examples from the RTClib library
   - Alternatively, add this line in setup() to set current time: `rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));`

## Code Explanation

### Key Functions

- **setup():** Initializes serial communication, display brightness, and checks RTC connection
- **loop():** Continuously reads time from RTC and updates the display
- **Time Format:** Converts 24-hour to 12-hour format for display

### Display Format

- Shows time as HHMM (e.g., 12:34)
- Colon separator blinks to indicate seconds
- Leading zeros are displayed (e.g., 09:05 not 9:5)
- 12-hour format (1-12, not 0-23)

## Troubleshooting

### Common Issues

1. **"RTC module is NOT found" error:**
   - Check I2C connections (SDA/SCL)
   - Verify 5V and GND connections
   - Try different I2C pins if using other Arduino models

2. **Display not working:**
   - Check CLK and DIO pin connections
   - Verify power connections (5V/GND)
   - Try adjusting brightness value

3. **Incorrect time display:**
   - Set the RTC time using library examples
   - Check if battery is properly installed in DS3231

### Pin Reference for Different Arduino Models

| Board | SDA Pin | SCL Pin |
|-------|---------|---------|
| Uno/Nano | A4 | A5 |
| Leonardo/Micro | 2 | 3 |
| Mega 2560 | 20 | 21 |

## Modifications and Improvements

### Possible Enhancements

- Add AM/PM indicator
- Include date display (alternating with time)
- Add alarm functionality
- Implement brightness control based on ambient light
- Add temperature display (DS3231 has built-in temperature sensor)

### Code Customization

- Change display pins by modifying `#define CLK` and `#define DIO` values
- Adjust brightness: `display.setBrightness(0x0f);` (0x00 to 0x0f)
- Switch to 24-hour format by removing the hour conversion logic

## Power Consumption

- Arduino Uno: ~20mA
- DS3231: ~0.1mA (with battery backup)
- TM1637: ~15mA (varies with brightness)
- Total: ~35mA at 5V

---

**Note:** Make sure to handle the DS3231 module carefully and ensure proper battery installation for backup functionality.
