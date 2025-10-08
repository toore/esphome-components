# esphome-components

This repository contains [ESPHome components](https://esphome.io/components/external_components) that can be used with [Home Assistant and the ESPHome Add-on](https://www.home-assistant.io/addons/).

### ivt_uart

A component designed to extend the functionality of the IVT 490 air-to-air heat pump equipped with a Rego 411 controller (version 5.12).  
It may also work with other models and controller versions with minimal or no modifications.  
Examples of potentially compatible models include: IVT 490, IVT 690, Bosch EHP EW, and Carrier 30NQ2EA.

Features:
- Relay switch control for vacation mode override
- Full logging of all exposed heat pump data parameters

Prototype hardware requirements:
- [ESP32-C3-Zero](https://www.waveshare.com/wiki/ESP32-C3-Zero)
- Arduino 5V relay module
- [Sullins 2x5 2.54mm connector](https://www.digikey.se/sv/products/detail/sullins-connector-solutions/EBC05DRXN/1318485)
- Casing, experiment board, and connector cables
- Soldering tools, glue, and cutters

![Prototype hardware for IVT 490 Rego 411 component](/assets/images/ivt_gateway_prototype.jpg)

Home Assistant example:

![Home Assistant screenshot on Android](/assets/images/home_assistant_example.jpg)
