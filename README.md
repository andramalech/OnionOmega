# OnionOmega
Different pieces of code I modified/created for the OnionOmega.

## AD7999
The Python code does not reliably work on the Onion Omega2. This is a modified version of the C code provided by NCD.IO. Follow [these instructions](https://docs.onion.io/omega2-docs/c-compiler-on-omega.html) to support building the code on your Omega2.

On my Omega2+ the compile took only a few seconds. Compile with:

`gcc AD7999_4channel.c -o AD7999`
