# Jason Fowler
# September 2016

ESP8266 FTDI232 Arduino IDE How To:

Setup hardware as per picture in this folder.  But also make sure to add a 3.3V battery pack to power up esp8266.

To upload an Arduino IDE sketch, do the following everytime before uploading:
	1) unplug USB from FTDI232 usb to serial
	2) unplug positive from battery pack
	3) plug in USB from FTDI232
	4) plug in positive from battery pack

The LED will turn on which means the esp8266 is ready for an upload.  Once a sketch from the Arduino IDE is uploaded, the LED
will blink off.

Using the serial monitor tool can fug up the sketch upload process.  Wait until sketch upload reaches 100% then open serial monitor.
