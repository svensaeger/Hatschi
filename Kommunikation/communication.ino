void setup(){
    Serial.begin(9600);
    delay(2000);
    Serial.println("Verbindung erfolgreich hergestellt !|");
    
}
 
void loop(){
  delay(1000);
  
  Serial.println("Irgendein Text");
  Serial.println("Noch irgendein Text");
}
