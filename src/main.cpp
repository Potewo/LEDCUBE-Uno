#include <Arduino.h>
#include <PacketSerial.h>
#include <SPT.h>

#define SER 8
#define CLK 9
#define RCLK 10

SPT spt;
PacketSerial ps;

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

const int cathods[] = {
  11,
  12,
  2,
  3,
  4,
  5,
  6,
  7
};

const int cathodsn = sizeof(cathods) / sizeof(cathods[0]);

void onPacketReceived(const uint8_t* buffer, size_t size);

const uint8_t* buf;
size_t buf_size = 0;

void setup() {
  delay(1000);
  spt.init(SER, CLK, RCLK);
  spt.setup();
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  ps.begin(9600);
  ps.setPacketHandler(&onPacketReceived);
  spt.send(data, 8);
  for (int i = 0; i < cathodsn; i++) {
    pinMode(cathods[i], OUTPUT);
  }
}

void loop() {
  ps.update();
  if (ps.overflow()) {
  }
  for (int i = 0; i < cathodsn; i++) {
    spt.send(buf, buf_size);
    digitalWrite(i, LOW);
    delay(3);
    digitalWrite(i, HIGH);
  }
}

void onPacketReceived(const uint8_t* buffer, size_t size) {
  buf = buffer;
  buf_size = size;
  spt.send(buffer, size);
}
