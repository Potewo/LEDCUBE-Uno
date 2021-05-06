#include <Arduino.h>
/* #include <AwesomeSerial.h> */
#include <SPT.h>

#define SER 8
#define CLK 9
#define RCLK 10

SPT spt;

uint8_t data[] = {
  0b01010101,
  0b01010101,
  0b01010101,
  0b01010101,
  0b01010101,
  0b01010101,
  0b01010101,
  0b01010101
};


uint8_t data2[] = {
  0b10101010,
  0b10101010,
  0b10101010,
  0b10101010,
  0b10101010,
  0b10101010,
  0b10101010,
  0b10101010
};

void setup() {
  spt.init(SER, CLK, RCLK);
  spt.setup();
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
}

void loop() {
  spt.send(data, 8);
  delay(1000);
  spt.send(data2, 8);
  delay(1000);
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
}
