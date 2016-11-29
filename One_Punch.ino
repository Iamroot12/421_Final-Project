
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

//set up time
unsigned long count;
unsigned long starttime = millis();

int fsrPin = 0;     // the FSR and 10K pulldown are connected to pin #10
int fsrread;     // the analog reading from the FSR resistor divider

// Set up accelerometer data
Adafruit_MMA8451 mma = Adafruit_MMA8451();

//data logger
const int chipSelect = 10;


//Prepare initial velocity values - also can calibrate against offsets
float velx = 0;
float vely = 0;
float velz = 0;

int xoff;
int yoff;
int zoff;



void setup(void) {

Serial.begin(9600);   // Start Serial communication line

 Serial.println("Adafruit MMA8451 test!");


// necessary for serial port to start  
  if (! mma.begin()) {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_8_G);  // +-2g range
  
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");

// Read the 'raw' accelerometer data in 14-bit counts
mma.read();

// find offset acceleration values
xoff = mma.x;
yoff = mma.y;
zoff = mma.z;

// setup for SD card

    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");

  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println();
    dataFile.println();
    dataFile.println("----------------------------------------"); // makes break between data sets
    dataFile.println("New Round");
    dataFile.println();
    dataFile.close();
    // print to the serial port too:
    Serial.println("New Round");
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }



}



float sped = 0;


void datalog() {
  // make a string for assembling the data to log:
  String dataString = "";

  // add values to string
//    dataString += String("Time: ");
    dataString += String(count);
    dataString += String(" ");
//    dataString += String("Force: ");
    dataString += String(fsrread);
    dataString += String(" ");
//    dataString += String("Speed: ");
   dataString += String(sped);



  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}

void loop() {

  //measure force
fsrread = analogRead(A0); 

// Flash LED when force threshold is reached
  if (fsrread > 100) {
float force = fsrread;


 // Light up LED
analogWrite(3, 2);   //(pin #, intensity 0-255)

  //record a timestamp
  count = millis() - starttime;
  
// call function to log data on chip
datalog();

 // Turn off LED
analogWrite(3, 0);

  }

// Read the 'raw' accelerometer data in 14-bit counts
mma.read();

// calculate velocity

//calculate velocity in all 3 directions
float velx = velx + (mma.x - xoff)*0.001;
float vely = vely + (mma.y - yoff)*0.001;
float velz = velz + (mma.z - zoff)*0.001;

//calculate speed
sped = sqrt(sq(velx) + sq(vely) + sq(velz));

//Updates acceleration every millisecond
delay(1);

}
