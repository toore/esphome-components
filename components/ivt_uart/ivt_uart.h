#pragma once
#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/uart/uart.h"
#include <sstream>

namespace esphome {
namespace ivt_uart {

class IVTSensor;

class IVTParser : public Component, public uart::UARTDevice {
  public:
   IVTParser(uart::UARTComponent *parent) : UARTDevice(parent) {}
 
   void loop() override;
   void set_sensor(uint8_t index, sensor::Sensor *sensor);
 
  protected:
   sensor::Sensor *sensors_[37] = {nullptr}; // Array of sensor pointers
   std::vector<uint8_t> buffer_;                   // Byte buffer for accumulating UART data
 };

class IVTSensor : public sensor::Sensor, public Component {
 public:
  void set_index(int index) { _index = index; }
  void set_parent(IVTParser *parent) { _parent = parent; }

 protected:
  int _index;
  IVTParser *_parent;
};

}  // namespace ivt_uart
}  // namespace esphome
