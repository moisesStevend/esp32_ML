#include "Window.h"
#include "Classifier.h"
//#include <Ufox.h>

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#define btn   13
#define RXLED  17

//Ufox wisol;

Adafruit_MPU6050 mpu;

Window window;
Eloquent::ML::Port::Classifier clf;

void setup(void) {
  pinMode(5, OUTPUT);
  pinMode(btn, INPUT);
  pinMode(RXLED, OUTPUT);

  Serial.begin(115200);
  //wisol.begin(9600);

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("");
  delay(100);
}

void loop() {

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  //  //Serial.print("AccelX:");
  //  Serial.print(a.acceleration.x);
  //  Serial.print(",");
  //  //Serial.print("AccelY:");
  //  Serial.print(a.acceleration.y);
  //  Serial.print(",");
  //  //Serial.print("AccelZ:");
  //  Serial.print(a.acceleration.z);
  //  Serial.print(", ");
  //  //Serial.print("GyroX:");
  //  Serial.print(g.gyro.x);
  //  Serial.print(",");
  //  //Serial.print("GyroY:");
  //  Serial.print(g.gyro.y);
  //  Serial.print(",");
  //  //Serial.print("GyroZ:");
  //  Serial.print(g.gyro.z);
  //  Serial.println("");

  float sample[] = {a.acceleration.x, a.acceleration.y, a.acceleration.z, g.gyro.x, g.gyro.y, g.gyro.z};

  // feed data to the window and wait until the window is full
  if (!window.transform(sample))
    return;

  Serial.print("Gesture: ");
  String result = clf.predictLabel(window.features);
  Serial.println(result);

  if (result.startsWith("anom")) {
    digitalWrite(5, LOW);
//    digitalWrite(RXLED, LOW);
//    wisol.RST();
//
//    String valor ="ok";
//    wisol.SEND(valor);
//    
//    digitalWrite(RXLED, HIGH);
//    wisol.SLEEP();

  } else {
    digitalWrite(5, HIGH);
  }

  delay(10);
}
