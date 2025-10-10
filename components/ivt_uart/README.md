# yaml example configuration

``` yaml
# example configuration

esphome:
  name: ivt490-gateway
  friendly_name: IVT 490

esp32:
  board: esp32-c3-devkitm-1
  framework:
    type: esp-idf

external_components:
  source:
    type: git
    url: https://github.com/toore/esphome-components
    ref: main
  components: [ivt_uart]

switch:
  - platform: gpio
    pin: GPIO0
    id: relay1
    name: "Vacation Mode Override"
    restore_mode: RESTORE_DEFAULT_OFF

uart:
  id: ivt_uart
  rx_pin: GPIO1
  baud_rate: 9600

ivt_uart:
  id: ivt_uart_main
  uart_id: ivt_uart

sensor:
  - platform: ivt_uart
    index: 0
    name: "Löpnummer"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 1
    name: "Framledning värme GT1"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 2
    name: "Ute GT2"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 3
    name: "Tappvarmvatten GT3:1"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 4
    name: "Varmvatten GT3:2"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 5
    name: "Värmevatten GT3:3"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 6
    name: "Rum GT5"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 7
    name: "Kompressor GT6"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 8
    name: "Ackumulatortank GT3:4"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 9
    name: "Avfrostningsvakt GP3"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 10
    name: "Högtrycksvakt GP2"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 11
    name: "Lågtrycksvakt GP1"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 12
    name: "Semesterfunktion aktiv"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 13
    name: "Kompressor aktiv"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 14
    name: "Öppna shuntventil SV1 mot värmesystem"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 15
    name: "Stäng shuntventil SV1 mot värmesystem"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 16
    name: "Cirkulationspump P1"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 17
    name: "Fläkt G22"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 18
    name: "Larm aktiv"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 19
    name: "Extern pump P2"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 20
    name: "Minsta tillåtna beräknat värde GT1"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 21
    name: "Undre gränsvärde GT1"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 22
    name: "Framledning värme beräknad GT1"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 23
    name: "Övre gränsvärde GT1"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 24
    name: "Undre gränsvärde GT3:2"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 25
    name: "Inställning för tappvarmvattentemperatur"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 26
    name: "Övre gränsvärde GT3:2"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 27
    name: "Undre gränsvärde GT3:3"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 28
    name: "Beräknad GT3:3"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 29
    name: "Beräknad förskjutning SV3"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 1
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 30
    name: "Effekt inkopplad vid varmvattenbehov"
    unit_of_measurement: "kW"
    device_class: power
    accuracy_decimals: 2
    filters:
      - multiply: 0.01
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 31
    name: "Tillskottstimer varmvattenbehov"
    unit_of_measurement: "min"
    device_class: duration
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 32
    name: "Sänkt framledning pga varmvattenprioritet"
    unit_of_measurement: "°C"
    device_class: temperature
    accuracy_decimals: 0
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 33
    name: "Elpatron tillskott"
    id: elpatron_tillskott
    unit_of_measurement: "%"
    device_class: power_factor
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main
  
  - platform: template
    name: "Elpatron tillskott effekt"
    unit_of_measurement: "kW"
    device_class: power
    accuracy_decimals: 1
    lambda: |-
      return id(elpatron_tillskott).state / 100.0 * 9; // Depends on the installed immersion heater power (9 kW)

  - platform: ivt_uart
    index: 34
    name: "Radiator tillskott"
    unit_of_measurement: "%"
    device_class: power_factor
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 35
    name: "Tillägg tillskott"
    unit_of_measurement: "%"
    device_class: power_factor
    filters:
      - multiply: 0.1
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 36
    name: "Shuntventil SV2 Öppen"
    parent_id: ivt_uart_main
