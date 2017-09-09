char text[] = "test|";

void uebertragen() {
  for(int i = 0; i<(sizeof(text)); i++) {
    Serial.println(text[i], DEC);
  }
}

void setup(){
    Serial.begin(9600);
    delay(2000);
    uebertragen();
}

int wert = 0;
 
void loop(){
  delay(1000);
  wert++;
  uebertragen();
}
