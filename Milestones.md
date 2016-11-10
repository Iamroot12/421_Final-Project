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
 * looking into data logger use
* Nov. 17th - Complete data logging system in place
* Nov. 22nd - Complete and nice attachment to boxing glove
* Nov. 29th - Everything must be 100% complete
 
