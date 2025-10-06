# esphome-components

This repository contains ESPHome components (https://esphome.io/components/external_components) that can be used with Home Assistant and ESPHome Add-on (https://www.home-assistant.io/addons/).

### ivt_uart

A component to extend the functionality of an IVT 490 air-to-air heat pump with Rego 411 controller, version 5.12. It probably works with no or little modifications with other models and/or controller versions.

Features:
- Switch control to close a relay that can be used to control vacation mode override.
- Logging of all exposed data parameters from the heat pump.

Prototype hardware requirements:
- ESP32-C3-Zero (https://www.waveshare.com/wiki/ESP32-C3-Zero)
- Arduino 5V Relay Module
- Sullins 2x5 2.54mm connector ("CONN EDGE DUAL FMALE 10POS 0.100")
- Casing, experiment board and connector cables.
- Soldering tools, glue and cutters.

![Image of prototype hardware for ivt490_rego411 component](/assets/images/ivt_gateway_prototype.jpg)
