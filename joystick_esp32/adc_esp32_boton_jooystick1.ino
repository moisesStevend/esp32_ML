#define frecuency 50 // 50 hz
#define interval_ms (1000/(frecuency+1))

int x, y;
static unsigned long last_interval_ms=0;
const int adc0=4;
const int adc1=15; //gpio2 led

void setup() {
  Serial.begin(115200);

}

void loop() {
  if (millis()> (last_interval_ms + interval_ms)) {
    last_interval_ms=millis();
    
    x = analogRead(adc0);
    y = analogRead(adc1);

    Serial.print(x);
    Serial.print(",");
    Serial.println(y);
  }
  //delay(100);
}
