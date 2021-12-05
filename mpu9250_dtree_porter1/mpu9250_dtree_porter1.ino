/************************************************************
Moises Meza
*************************************************************/
#include <SparkFunMPU9250-DMP.h>

#define SerialPort Serial

MPU9250_DMP imu;

//double features[9];
#define MSG_BUFFER_SIZE  (100)
char msg[MSG_BUFFER_SIZE];
//int classes[3];

void setup() 
{
  SerialPort.begin(115200);

  if (imu.begin() != INV_SUCCESS)
  {
    while (1)
    {
      SerialPort.println("Unable to communicate with MPU-9250");
      SerialPort.println("Check connections, and try again.");
      SerialPort.println();
      delay(5000);
    }
  }

  imu.setSensors(INV_XYZ_GYRO | INV_XYZ_ACCEL | INV_XYZ_COMPASS);


  imu.setGyroFSR(2000); // Set gyro to 2000 dps
  // Accel options are +/- 2, 4, 8, or 16 g
  imu.setAccelFSR(2); // Set accel to +/-2g
  // Note: the MPU-9250's magnetometer FSR is set at 
  // +/- 4912 uT (micro-tesla's)

  // setLPF() can be used to set the digital low-pass filter
  // of the accelerometer and gyroscope.
  // Can be any of the following: 188, 98, 42, 20, 10, 5
  // (values are in Hz).
  imu.setLPF(5); // Set LPF corner frequency to 5Hz

  // The sample rate of the accel/gyro can be set using
  // setSampleRate. Acceptable values range from 4Hz to 1kHz
  imu.setSampleRate(10); // Set sample rate to 10Hz

  // Likewise, the compass (magnetometer) sample rate can be
  // set using the setCompassSampleRate() function.
  // This value can range between: 1-100Hz
  imu.setCompassSampleRate(10); // Set mag rate to 10Hz
}

void loop() 
{
  // dataReady() checks to see if new accel/gyro data
  // is available. It will return a boolean true or false
  // (New magnetometer data cannot be checked, as the library
  //  runs that sensor in single-conversion mode.)
  if ( imu.dataReady() )
  {
    // Call update() to update the imu objects sensor data.
    // You can specify which sensors to update by combining
    // UPDATE_ACCEL, UPDATE_GYRO, UPDATE_COMPASS, and/or
    // UPDATE_TEMPERATURE.
    // (The update function defaults to accel, gyro, compass,
    //  so you don't have to specify these values.)
    imu.update(UPDATE_ACCEL | UPDATE_GYRO | UPDATE_COMPASS);
    printIMUData();
  }
}

void printIMUData(void)
{  
  // After calling update() the ax, ay, az, gx, gy, gz, mx,
  // my, mz, time, and/or temerature class variables are all
  // updated. Access them by placing the object. in front:

  // Use the calcAccel, calcGyro, and calcMag functions to
  // convert the raw sensor readings (signed 16-bit values)
  // to their respective units.
  float accelX = imu.calcAccel(imu.ax);
  float accelY = imu.calcAccel(imu.ay);
  float accelZ = imu.calcAccel(imu.az);
  float gyroX = imu.calcGyro(imu.gx);
  float gyroY = imu.calcGyro(imu.gy);
  float gyroZ = imu.calcGyro(imu.gz);
  float magX = imu.calcMag(imu.mx);
  float magY = imu.calcMag(imu.my);
  float magZ = imu.calcMag(imu.mz);

  /*
  SerialPort.println("Accel: " + String(accelX) + ", " +
              String(accelY) + ", " + String(accelZ) + " g");
  SerialPort.println("Gyro: " + String(gyroX) + ", " +
              String(gyroY) + ", " + String(gyroZ) + " dps");
  SerialPort.println("Mag: " + String(magX) + ", " +
              String(magY) + ", " + String(magZ) + " uT");
  SerialPort.println("Time: " + String(imu.time) + " ms");
  SerialPort.println();
  */
  /* Features: */
    double features[9];
       
    //int i;
    //for (i = 1; i < argc; i++) {
    //    features[i-1] = atof(argv[i]);
    //}
    features[0]=(accelX - 0.311670)/0.441356; 
    features[1]=(accelY - 0.487976)/0.469048;
    features[2]=(accelZ - 0.371448)/0.435148;
    features[3]=(gyroX - (-0.179878))/10.502656;
    features[4]=(gyroY - 2.013720)/8.330894;
    features[5]=(gyroZ - (-3.158537))/8.413968;
    features[6]=(magX - 1.519130)/11.302699;
    features[7]=(magY - (-3.634659))/3.342960;
    features[8]=(magZ - (-41.189048))/8.887321;
    /* Prediction: */
     //snprintf (msg, MSG_BUFFER_SIZE, "%d", predict(features));
    int classes[3];
    //Serial.printf(msg);
    
        
    if (features[6] <= 0.12603363394737244) {
        if (features[0] <= 0.41869865357875824) {
            classes[0] = 0; 
            classes[1] = 7; 
            classes[2] = 0; 
        } else {
            classes[0] = 9; 
            classes[1] = 0; 
            classes[2] = 0; 
        }
    } else {
        classes[0] = 0; 
        classes[1] = 0; 
        classes[2] = 14; 
    }

    int index = 0;
    for (int i = 0; i < 3; i++) {
        index = classes[i] > classes[index] ? i : index;
    }
    Serial.println(index); 
}
