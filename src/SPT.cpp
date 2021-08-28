// Serial-Parallel-Transportation
#include "SPT.h"

void SPT::init(uint8_t SER, uint8_t CLK, uint8_t RCLK) {
  SPT::SER = SER;
  SPT::CLK = CLK;
  SPT::RCLK = RCLK;
}

void SPT::setup() {
  pinMode(SPT::SER, OUTPUT);
  pinMode(SPT::CLK, OUTPUT);
  pinMode(SPT::RCLK, OUTPUT);
  digitalWrite(SPT::SER, LOW);
  digitalWrite(SPT::CLK, LOW);
  digitalWrite(SPT::RCLK, LOW);
}

void SPT::send(const uint8_t data[], int n) {
  digitalWrite(SPT::RCLK, LOW);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      // uint8_t status = data[i] >> j & 0b00000001;
      digitalWrite(SPT::SER, !!(data[i] & (1L << j)));
      digitalWrite(SPT::CLK, HIGH);
      digitalWrite(SPT::CLK, LOW);
    }
    /* shiftOut(SPT::SER, SPT::CLK, LSBFIRST, data[i]); */
  }
  digitalWrite(SPT::RCLK, HIGH);
  /* digitalWrite(SPT::RCLK, LOW); */
}
