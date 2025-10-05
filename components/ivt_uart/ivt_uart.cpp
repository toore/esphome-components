#include "ivt_uart.h"
#include "esphome/core/log.h"
#include <sstream>

namespace esphome {
namespace ivt_uart {

static const char *const TAG = "IVT";

void IVTParser::set_sensor(uint8_t index, sensor::Sensor *sensor) {
  if (index < 37) {
    sensors_[index] = sensor;
  }
}

void IVTParser::loop() {
  while (available()) {
    uint8_t byte = read();

    if (byte == '\r') {
      // End of line — parse buffer
      std::string line(buffer_.begin(), buffer_.end());
      buffer_.clear();

      std::vector<std::string> parts;
      std::string token;
      std::stringstream stream(line);

      while (std::getline(stream, token, ';')) {
        parts.push_back(token);
      }

      for (size_t i = 0; i < 37 && i < parts.size(); ++i) {
        if (sensors_[i] != nullptr) {
          char* endptr = nullptr;
          int value = std::strtol(parts[i].c_str(), &endptr, 10);
          if (endptr != parts[i].c_str() && *endptr == '\0') {
            sensors_[i]->publish_state(static_cast<float>(value));
          } else {
            ESP_LOGW(TAG, "Invalid integer at index %d: %s", static_cast<int>(i), parts[i].c_str());
          }
        }
      }
    } else {
      buffer_.push_back(byte);
      if (buffer_.size() > 512) {
        ESP_LOGW(TAG, "Buffer overflow — clearing");
        buffer_.clear();
      }
    }
  }
}

}  // namespace ivt_uart
}  // namespace esphome
