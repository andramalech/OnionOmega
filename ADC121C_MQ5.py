# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# ADC121C_MQ5
# This code is designed to work with the ADC121C_I2CGAS_MQ2 I2C Mini Module available from ControlEverything.com.
# https://shop.controleverything.com/products/lpg-lng-natural-gas-iso-butane-propane-gas-sensor

from OmegaExpansion import onionI2C
import time
import math

# Get I2C bus
i2c = onionI2C.OnionI2C()

data = i2c.readBytes(0x50, 0x00, 2)

# Convert the data to 12 - bits
raw_adc = (data[0] & 0x0F) * 256 + data[1]

print raw_adc
