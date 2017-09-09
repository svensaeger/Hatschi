#include "DHT.h"
#include "DS1302RTC.h"
#include "Time.h"

#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);
DS1302RTC RTC(5, 6, 7);

void setup() {
  Serial.begin(9600);

  uhrzeit_s();

  
  dht.begin();
}

void loop() {
    gassensor_v();
  dtv_v();
  uhrzeit_v();

}

void gassensor_v ()
{
int sensorValue = analogRead(A0);

    Serial.print("Gassensor: ");
    Serial.println(sensorValue);
    
}

void dtv_v ()
{
    // Wait a few seconds between measurements.
  delay(2000);
  

  // Read relative humidity in percent
  float h = dht.readHumidity();
  // Read temperature in degree Celsius
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Es tut mir leid aber ihr seid zu eingeschraengt mich richtig zu verkabeln!!!");
    return;
  }

  // Compute saturation vapor pressure
  // https://en.wikipedia.org/wiki/Clausius-Clapeyron_relation
  float es = 6.1094*exp(17.625*t/(243.04+t));
  // Compute vapor pressure
  // https://en.wikipedia.org/wiki/Humidity#Relative_humidity
  float e = t*h/100.;
  // Compute absolute humidity
  // https://en.wikipedia.org/wiki/Humidity#Absolute_humidity
  // http://planetcalc.com/2167/
  float af = (e*100)/(461.52*(t+273.15))*1000.;

  Serial.print("Messungen::\t");
  Serial.print("Relative Feuchtigkeit: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatur: ");
  Serial.print(t);
  Serial.println(" *C");

  Serial.print("Kalkulation::\t");
  Serial.print("saettigungsdampfdruck: ");
  Serial.print(es);
  Serial.print(" hPa\t");
  Serial.print("Luftdruck: ");
  Serial.print(e);
  Serial.print(" hPa\t");
  Serial.print("absulute Feuchtigkeit: ");
  Serial.print(af);
  Serial.println(" g/m^3");

}

void uhrzeit_s ()
{
    delay(500);

  // Check clock oscillation  

  setSyncProvider(RTC.get); // the function to get the time from the RTC
  
   
  delay (2000);

  setSyncProvider(RTC.get); // the function to get the time from the RTC

 
  Serial.begin(9600);
  delay(1000);
  Serial.print("DS1302RTC");
  Serial.println(" test!");
}

void uhrzeit_v ()
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


