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
int i = 0;

void versenden(int temp, int luftf, int luftdruck, int af) {
  char buffer[1024];
  snprintf(buffer, sizeof(buffer), "{'temp':'%d','luftf':'%d','luftd':'%d','af':'%d'}", temp, luftf, luftdruck, af);
  Serial.println(buffer);
}

void setup() {
  Serial.begin(9600);

  setSyncProvider(RTC.get);
  
  dht.begin();
}

void loop() {
  //Buffer-Vorlage:
    /*int sensorValue = analogRead(A0);
    char buffer [100];
    i=sprintf(buffer,"Gassensor: %d",char(sensorValue));
    for(int l=0;l<=i;l++)
    {
      Serial.print(buffer[l]);
    }
    Serial.print("\n");*/
  //Ende Buffer-Vorlage
    
  // Read relative humidity in percent
  float h = dht.readHumidity();
  // Read temperature in degree Celsius
  float t = dht.readTemperature();

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

  /*Serial.print("Relative Feuchtigkeit: ");
  Serial.print(h);
  Serial.println(" %");
  
  Serial.print("Temperatur: ");
  Serial.print(t);
  Serial.println(" *C");

  Serial.print("Saettigungsdampfdruck: ");
  Serial.print(es);
  Serial.println(" hPa");
  
  Serial.print("Luftdruck: ");
  Serial.print(e);
  Serial.println(" hPa");
  
  Serial.print("absulute Feuchtigkeit: ");
  Serial.print(af);
  Serial.println(" g/m^3");*/

//  Serial.print("hour: ");
//  Serial.println(hour());

//  Serial.print("minute: ");
//  Serial.println(minute());

//  Serial.print("second: ");
//  Serial.println(second());

  delay ( 1000 ); // Wait approx 1 sec

  versenden(t, h, e, af);
}







