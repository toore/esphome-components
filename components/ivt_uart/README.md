``` yaml
# example configuration:

esphome:
  name: ivt490-gateway
  friendly_name: IVT 490

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
    name: "Framledning GT1"
    unit_of_measurement: "°C"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 2
    name: "Ute GT2"
    unit_of_measurement: "°C"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 3
    name: "Tappvarmvatten Topp GT3-1"
    unit_of_measurement: "°C"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 4
    name: "Varmvatten Mitt GT3-2"
    unit_of_measurement: "°C"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 5
    name: "Värmevatten Botten GT3-3"
    unit_of_measurement: "°C"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 6
    name: "Rumstemp GT5"
    unit_of_measurement: "°C"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 7
    name: "Hetgas GT6"
    unit_of_measurement: "°C"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 8
    name: "Extra Acc-Tank GT3-4"
    unit_of_measurement: "°C"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 9
    name: "Tryckvakt avfrostning GP3"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 10
    name: "Högtrycksvakt HP"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 11
    name: "Lågtrycksvakt LP"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 12
    name: "Semester aktiv"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 13
    name: "Kompressor aktiv"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 14
    name: "Shuntventil öppna SV1"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 15
    name: "Shuntventil stäng SV1"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 16
    name: "Cirkulationspump P1"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 17
    name: "Fläkt"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 18
    name: "Larm aktiv"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 19
    name: "Extern P2"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 20
    name: "LLT GT1"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 21
    name: "LL GT1"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 22
    name: "Börvärde framledning GT1"
    unit_of_measurement: "°C"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 23
    name: "UL GT1"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 24
    name: "LL GT3:2"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 25
    name: "ULT GT3:2"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 26
    name: "UL GT3:2"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 27
    name: "LL GT3:3"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 28
    name: "BV GT3:3"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 29
    name: "SV3 BV Förskjutning"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 30
    name: "Effekt inkopplad vid VV behov"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 31
    name: "Tillskottstimer VV behov"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 32
    name: "Tappvatten prioritet"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 33
    name: "Elpatron tillskott"
    unit_of_measurement: "%"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 34
    name: "Tillskott RAD"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 35
    name: "Tillskott Tillägg"
    parent_id: ivt_uart_main

  - platform: ivt_uart
    index: 36
    name: "SV2 Öppen"
    parent_id: ivt_uart_main
