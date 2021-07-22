#include <WiFi.h>
#include <PubSubClient.h>
#include <SparkFunMPU9250-DMP.h>

MPU9250_DMP imu;
#define SerialPort Serial

const char* ssid = "jicamarca";
const char* password = "radioobservatory";
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(100)
char msg[MSG_BUFFER_SIZE];
int value = 0;

int button=23;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    //digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
  } else {
    //digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
  }

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  //pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  pinMode(button, INPUT_PULLUP);
  
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
    imu.setAccelFSR(2); // Set accel to +/-2g
    imu.setLPF(5); // Set LPF corner frequency to 5Hz
    imu.setSampleRate(10); // Set sample rate to 10Hz
    imu.setCompassSampleRate(10); // Set mag rate to 10Hz

    
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if ((now - lastMsg > 2000) && imu.dataReady() && digitalRead(button)==0) {  
    lastMsg = now;
    //++value;

    imu.update(UPDATE_ACCEL | UPDATE_GYRO | UPDATE_COMPASS);
    float accelX = imu.calcAccel(imu.ax);
    float accelY = imu.calcAccel(imu.ay);
    float accelZ = imu.calcAccel(imu.az);
    float gyroX = imu.calcGyro(imu.gx);
    float gyroY = imu.calcGyro(imu.gy);
    float gyroZ = imu.calcGyro(imu.gz);
    float magX = imu.calcMag(imu.mx);
    float magY = imu.calcMag(imu.my);
    float magZ = imu.calcMag(imu.mz);
    
    snprintf (msg, MSG_BUFFER_SIZE, "(%f,%f,%f,%f,%f,%f,%f,%f,%f)", accelX, accelY, accelZ, gyroX, gyroY, gyroZ, magX,magY, magZ);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("modulo/mpu9250/ml", msg);
  }
}
