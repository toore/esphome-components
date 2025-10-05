import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_INDEX

DEPENDENCIES = ["uart"]

ivt_uart_ns = cg.esphome_ns.namespace("ivt_uart")
IVTSensor = ivt_uart_ns.class_("IVTSensor", sensor.Sensor, cg.Component)
IVTParser = ivt_uart_ns.class_("IVTParser", cg.Component)

CONF_PARENT_ID = "parent_id"

CONFIG_SCHEMA = sensor.sensor_schema().extend({
    cv.Required(CONF_INDEX): cv.int_,
    cv.Required(CONF_PARENT_ID): cv.use_id(IVTParser),
    cv.GenerateID(): cv.declare_id(IVTSensor),
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    parent = await cg.get_variable(config[CONF_PARENT_ID])
    sens = await sensor.new_sensor(config)
    cg.add(parent.set_sensor(config[CONF_INDEX], sens))

sensor.register_sensor("ivt_uart", IVTSensor)
