char textZumUebertragen[] = "test|";

void uebertragen() {
  for(int i = 0; i<sizeof(textZumUebertragen); i++) {
    Serial.println(textZumUebertragen[i], DEC);
  }
}

void setup(){
    Serial.begin(9600);
    delay(5000);
    uebertragen();
}
 
void loop(){
  delay(1000);
  uebertragen();
  delay(1000);
  uebertragen();
}
