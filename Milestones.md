# Milestones

1. Oct. 20- Getting Started
 * Made github page
 * Decided to make smart boxing gloves
 * start with circuit playground and tap sensing- go from there
 * check out comm_badge.ino
* Oct. 27th - Have working proof of concept for hit sensing using circuit playground
 * got commbadge contacting software to work, produced a change in LED's with impact
 * need to figure out how to record timestamp and view data with processing
 * used millis() command to record the milliseconds and substracts out the start time to make it relative
 * changed code structure to allow for ongoing stream of background data and then the impact interrupts and spits out time and accel data
 * researched and purchased force sensors and data loggers
* Nov. 3rd - Connect pressure sensors and make them work/ Understand how to send data through processing and make it look nice
 * orders have not arrived yet - work on processing
 * was able to get extremely simple graphics on processing from serial data
 * downloaded graphing package called gicentreutils
 * changed to opencv as graphing software for logged data
 * trying to record velocity of glove
 * using V = Vo + at with a dt of 1ms in the loop function for arduino
 * able to measure velocity but the accelerometer is not very accurate
 * basic force sensors, more precise accelerometer, data logger, and SD card arrived
 * able to make force sensing circuit and have it work with circuit playground
 * I need to move to the arduino uno for more pins, plus I dont need the built in accelerometer
* Nov. 10th - Connect Data logger and figure out how to configure more precise force sensor
 * soldered and connected external accelerometer to uno
 * hard coded the calibration for the accelerometer by adding or subtracting offset values
 * able to create proof of concept that spits out speed and force values during impact, also lights up LED
 * differences in speeds are clearly registered
 * use 'better uno glove' code
 * Possibly call device the 'One Punch'?
 * looking into data logger use - https://learn.adafruit.com/adafruit-micro-sd-breakout-board-card-tutorial/wiring
 * formatted SD card - https://www.sdcard.org/downloads/formatter_4/index.html
 * capacitive force sensor did not come with I2C board connector
 * looking into using flexiforce sensor from Miller Lab
 * need to figure out op amp change because I couldn't find the same op amp that was previously used
 * found an op amp that works
 * realized that the force sensor from the lab only has a range till 1 lb but I need like 100 lb
 * should get attachment for capacitor sensor
* Nov. 17th - Complete data logging system in place
 * still waiting for good force sensor connector to come in
 * finished connecting the data logger
 * new information appends to the file and says New Round at the top of new info
 * changed accelerometer code to take in offset value at setup
 * -Problem- accelerometer decalibrates if orientation changes
 * I think it should be fine as long as it is calibrated in punch orientation bec/ error goes away when in correct orientation again
 * Still need to graph data, connect to glove, and calibrate better sensor
* Nov. 22nd - Complete and nice attachment to boxing glove
 * The new pressure sensor connector came in but it requires the use of a computer for all functionality
 * I'll stay with the older sensor
 * Finished coding python for graphing that finds the last round and seperates the information into vectors and then graphs
 * I changed the resistor to 100 Ω in the FSR circuit to increase the sensitivity
 * Connected everything to the glove and make sure it works
 * Moved some things around on the breadboard for better usability, like the data logger to the opening for easy acces to the SD card
 * A running armband contains all of the electronics
* Nov. 29th - Everything must be 100% complete
 * a couple finishing touches, system works well
 * the system is only conncected to the computer for power
 
