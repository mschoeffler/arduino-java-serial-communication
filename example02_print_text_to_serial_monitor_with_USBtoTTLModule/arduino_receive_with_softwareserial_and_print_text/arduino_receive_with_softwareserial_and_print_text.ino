// (c) Michael Schoeffler 2017, http://www.mschoeffler.de
#include <SoftwareSerial.h>
 
SoftwareSerial sserial(5,6); // receive pin (used), transmit pin (unused)

void setup() {
  Serial.begin(9600); // used for printing to serial monitor of the Arduino IDE
  sserial.begin(9600); // used to receive digits from the Java application
  while (!Serial) {
    ; // wait for serial port to connect. 
  }
}

void loop() {
  if (sserial.available() > 0) {
    byte incomingByte = 0;
    incomingByte = sserial.read();
    if (incomingByte != -1) {
      Serial.print("I received: "); // print out to serial monitor
      Serial.println(incomingByte); // print out to serial monitor
    }
  }
}
