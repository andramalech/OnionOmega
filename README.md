# OnionOmega
Different pieces of code I modified/created for the OnionOmega.

## AD7999
The Python code does not reliably work on the Onion Omega2. This is a modified version of the C code provided by NCD.IO. Follow [these instructions](https://docs.onion.io/omega2-docs/c-compiler-on-omega.html) to support building the code on your Omega2.

On my Omega2+ the compile took only a few seconds. Compile with:

`gcc AD7999_4channel.c -o AD7999`

## ADC121C_MQ5
Version of [this](https://github.com/ControlEverythingCommunity/CE_PYTHON_LIB/blob/master/ADC121C_MQ5.py) code that has been updated to work on Onion Omega. Code executes OK, but readings from the sensor do not change when propane is introduced to the sensor.

## PECMAC
Version modified to work on the Onion Omega. You will need to [load some extra kernel modules](https://community.onion.io/topic/2312/i2c-detect-slave-method) to make this work properly. I've tested this with the 70A, 3 channel model.
