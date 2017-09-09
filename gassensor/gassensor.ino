


void setup() {
// initialize serial communication at 9600 bits per second:
 
 Serial.begin(9600);
}


void loop() {
// read the input on analog pin 0:
int sensorValue = analogRead(A0); 
delay (500);
if (sensorValue >=150){
    Serial.println(sensorValue);
    Serial.println("musst schon doof sein, wenn du jetzt raus gehst");
  }
  else {
    Serial.println(sensorValue);
    Serial.println("wenns unbedingt sein muss kannst du jetzt raus gehen");
  }
  
delay(100);
}
