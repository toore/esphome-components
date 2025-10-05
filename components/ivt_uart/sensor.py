import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_ID, CONF_INDEX

DEPENDENCIES = ["uart"]

ivt490_uart_ns = cg.esphome_ns.namespace("ivt490_uart")
IVT490Sensor = ivt490_uart_ns.class_("IVT490Sensor", sensor.Sensor, cg.Component)
IVT490Parser = ivt490_uart_ns.class_("IVT490Parser", cg.Component)

CONF_PARENT_ID = "parent_id"

CONFIG_SCHEMA = sensor.sensor_schema().extend({
    cv.Required(CONF_INDEX): cv.int_,
    cv.Required(CONF_PARENT_ID): cv.use_id(IVT490Parser),
    cv.GenerateID(): cv.declare_id(IVT490Sensor),
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    parent = await cg.get_variable(config[CONF_PARENT_ID])
    sens = await sensor.new_sensor(config)
    cg.add(parent.set_sensor(config[CONF_INDEX], sens))

sensor.register_sensor("ivt490_uart", IVT490Sensor)
