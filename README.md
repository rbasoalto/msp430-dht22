# MSP430 <3 DHT22

This is a test program / proof of concept of reading the [DHT22](http://www.lmgtfy.com/?q=DHT22) using Timer1A in the MSP430G2553 on the Launchpad (or whatever).

## Hardware

You'll need:
- MSP430 Launchpad with MSP430G2553 (or something else)
- DHT22 with required pullup resistor

Connect the data pin of the DHT22 to P2.0 on the Launchpad (that's pin 8 on J1).

Build, program, and see the temperature and humidity on your favorite serial console program.

# License

The MIT License (MIT)

Copyright (c) 2014 Rodrigo Basoalto

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
