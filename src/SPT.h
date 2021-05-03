// Serial-Parallel-Transformation
#include <Arduino.h>
class SPT {
  public:
    uint8_t SER;
    uint8_t CLK;
    uint8_t RCLK;

    void init(uint8_t SER, uint8_t CLK, uint8_t RCLK);
    void setup();
    void send(uint8_t data[], int n);
};
