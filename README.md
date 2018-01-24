# OnionOmega
Different pieces of code I modified/created for the OnionOmega.

## AD7999
The Python code does not reliably work on the Onion Omega2. This is a modified version of the C code provided by NCD.IO. Follow [these instructions](https://docs.onion.io/omega2-docs/c-compiler-on-omega.html) to support building the code on your Omega2.

On my Omega2+ the compile took only a few seconds. Compile with:

`gcc AD7999_4channel.c -o AD7999`

## ADC121C_MQ5
The most basic version to just read the raw ADC value. For my own needs I don't need absolute ppm values. I've tested this in clear air and introduced small amounts of propane and I get reproducable results. A quick test for your own sensor is to point a propane torch (for plumbing use) at it an open it. This will spike the reading to the highest you should ever see.

You can probably pull the required math from [this](https://github.com/ControlEverythingCommunity/CE_PYTHON_LIB/blob/master/ADC121C_MQ5.py). But the updated code for the Omega did not provide meaningfull results
 
## PECMAC
Version modified to work on the Onion Omega. You will need to [load some extra kernel modules](https://community.onion.io/topic/2312/i2c-detect-slave-method) to make this work properly. I've tested this with the 70A, 3 channel model.
