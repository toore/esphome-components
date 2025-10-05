import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart
from esphome.const import CONF_ID, CONF_UART_ID

DEPENDENCIES = ["uart"]

ivt490_uart_ns = cg.esphome_ns.namespace("ivt490_uart")
IVT490Parser = ivt490_uart_ns.class_("IVT490Parser", cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(IVT490Parser),
    cv.Required(CONF_UART_ID): cv.use_id(uart.UARTComponent),
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    uart_comp = await cg.get_variable(config[CONF_UART_ID])
    parser = cg.new_Pvariable(config[CONF_ID], uart_comp)
    await cg.register_component(parser, config)