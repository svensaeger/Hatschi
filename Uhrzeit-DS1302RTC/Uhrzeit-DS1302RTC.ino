// Timur Maksiomv 2014
//
// A quick demo of how to use DS1302-library to make a quick
// clock using a DS1302 and a 16x2 LCD.
//
// I assume you know how to connect the DS1302 and LCD.
// DS1302:  CE pin    -> Arduino Digital 27
//          I/O pin   -> Arduino Digital 29
//          SCLK pin  -> Arduino Digital 31
//          VCC pin   -> Arduino Digital 33
//          GND pin   -> Arduino Digital 35
//
// LCD:     DB7       -> Arduino Digital 7
//          DB6       -> Arduino Digital 6 
//          DB5       -> Arduino Digital 5
//          DB4       -> Arduino Digital 4
//          E         -> Arduino Digital 9
//          RS        -> Arduino Digital 8


#include "DS1302RTC.h"
#include "Time.h"

// Init the DS1302
// Set pins:  CE, IO,CLK
DS1302RTC RTC(5, 6, 7);



void setup()
{
 
 
  delay(500);

  // Check clock oscillation  

  setSyncProvider(RTC.get); // the function to get the time from the RTC
  if(timeStatus() == timeSet)
   
  delay ( 2000 );

  setSyncProvider(RTC.get); // the function to get the time from the RTC

 
  Serial.begin(9600);
  delay(1000);
  Serial.print("DS1302RTC");
  Serial.println(" test!");

}

void loop()
{

  // Display time centered on the upper line
  Serial.print("hour: ");
  Serial.print(hour());
  Serial.print("\n");
  Serial.print("minute: ");
  Serial.print(minute());
  Serial.print("\n");
  Serial.print("second: ");
  Serial.print(second());
  Serial.print("\n");
  Serial.print("weekday: ");
  Serial.print(dayShortStr(weekday()));
  Serial.print("\n");
  Serial.print("day: ");
  Serial.print(day());
  Serial.print("\n");
  Serial.print("month: ");
  Serial.print(month());
  Serial.print("\n");

  delay ( 1000 ); // Wait approx 1 sec
}


