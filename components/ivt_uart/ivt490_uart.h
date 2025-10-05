#pragma once
#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/uart/uart.h"
#include <sstream>

namespace esphome {
namespace ivt490_uart {

class IVT490Sensor;

class IVT490Parser : public Component, public uart::UARTDevice {
  public:
   IVT490Parser(uart::UARTComponent *parent) : UARTDevice(parent) {}
 
   void loop() override;
   void set_sensor(uint8_t index, sensor::Sensor *sensor);
 
  protected:
   sensor::Sensor *sensors_[37] = {nullptr}; // Array of sensor pointers
   std::vector<uint8_t> buffer_;                   // Byte buffer for accumulating UART data
 };

class IVT490Sensor : public sensor::Sensor, public Component {
 public:
  void set_index(int index) { _index = index; }
  void set_parent(IVT490Parser *parent) { _parent = parent; }

 protected:
  int _index;
  IVT490Parser *_parent;
};

}  // namespace ivt490_uart
}  // namespace esphome
