#include <RTClib.h>
#include <TM1637Display.h>

// Define pins for the TM1637 display
#define CLK 9
#define DIO 10

RTC_DS3231 rtc;
TM1637Display display(CLK, DIO);

void setup() {
  Serial.begin(115200);
  display.setBrightness(0x0f);  // Set maximum brightness

  // Check if the RTC module is connected properly
  if (!rtc.begin()) {
    Serial.println("RTC module is NOT found");
    Serial.flush();
    while (1)
      ;  // Stay here if RTC is not found
  }
}

void loop() {
  DateTime now = rtc.now();  // Get current date/time from RTC

  // Store current time values
  int hour = now.hour();
  int minute = now.minute();

  // Convert to 12-hour format
  if (hour > 12) {
    hour -= 12;  // Subtract 12 for PM hours (13-23 becomes 1-11)
  }
  if (hour == 0) {
    hour = 12;  // 12:00 for midnight
  }

  // Show hour and minute on display (HHMM)
//   display.setBrightness(7, true);  // Turn on
  display.showNumberDecEx(hour * 100 + minute, 0b01000000, true);  // Format: HHMM, true for leading zeros
  delay(1000);  // Update every second
}