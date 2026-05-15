#include <WiFi.h>
#include <FirebaseESP32.h>

/*
   Railway Inspection System Using IoT
   Author: Souparnika Dinesh
   Description:
   ESP32-based railway inspection robot with real-time hazard monitoring
   and remote vehicle control using Firebase.
*/

// Wi-Fi Credentials
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

// Firebase Credentials
#define FIREBASE_HOST "YOUR_FIREBASE_DATABASE_URL"
#define FIREBASE_AUTH "YOUR_FIREBASE_AUTH_TOKEN"

// Firebase Objects
FirebaseData firebaseData;
FirebaseJson json;
FirebaseConfig firebaseConfig;
FirebaseAuth firebaseAuth;

// Motor Driver Pins
#define IN1 4
#define IN2 5
#define IN3 18
#define IN4 19

// Sensor Pins
#define FLAME_SENSOR 32
#define WATER_SENSOR 33
#define IR_SENSOR 25
#define TILT_SENSOR 26

bool dangerDetected = false;

void setup() {
  Serial.begin(115200);

  // Wi-Fi Connection
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi Connected Successfully");

  // Firebase Configuration
  firebaseConfig.host = FIREBASE_HOST;
  firebaseConfig.signer.tokens.legacy_token = FIREBASE_AUTH;

  Firebase.begin(&firebaseConfig, &firebaseAuth);
  Firebase.reconnectWiFi(true);

  // Sensor Pin Configuration
  pinMode(FLAME_SENSOR, INPUT);
  pinMode(WATER_SENSOR, INPUT);
  pinMode(IR_SENSOR, INPUT);
  pinMode(TILT_SENSOR, INPUT);

  // Motor Pin Configuration
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.println("Railway Inspection System Ready");
}

void updateSensorData() {
  String fireStatus = digitalRead(FLAME_SENSOR) == LOW ? "YES" : "NO";
  String waterStatus = digitalRead(WATER_SENSOR) == LOW ? "YES" : "NO";
  String obstacleStatus = digitalRead(IR_SENSOR) == LOW ? "YES" : "NO";
  String tiltStatus = digitalRead(TILT_SENSOR) == LOW ? "YES" : "NO";

  // Hazard Detection
  dangerDetected = (
    fireStatus == "YES" ||
    waterStatus == "YES" ||
    obstacleStatus == "YES" ||
    tiltStatus == "YES"
  );

  // Create JSON Data
  json.clear();
  json.set("fire", fireStatus);
  json.set("water", waterStatus);
  json.set("obstacle", obstacleStatus);
  json.set("tilt", tiltStatus);

  // Upload to Firebase
  if (Firebase.updateNode(firebaseData, "/sensor_data", json)) {
    Serial.println("Sensor data uploaded successfully");
  } else {
    Serial.print("Firebase Upload Failed: ");
    Serial.println(firebaseData.errorReason());
  }
}

void stopVehicle() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void controlVehicle() {
  if (dangerDetected) {
    stopVehicle();
    Serial.println("Danger Detected - Vehicle Stopped");
    return;
  }

  if (Firebase.getString(firebaseData, "/vehicle_control")) {
    String direction = firebaseData.stringData();

    Serial.println("Received Command: " + direction);

    if (direction == "FORWARD") {
      moveForward();
    } 
    else if (direction == "BACKWARD") {
      moveBackward();
    } 
    else if (direction == "LEFT") {
      turnLeft();
    } 
    else if (direction == "RIGHT") {
      turnRight();
    } 
    else if (direction == "STOP") {
      stopVehicle();
    }
  } else {
    Serial.println("Failed to fetch control command");
  }
}

void loop() {
  updateSensorData();
  controlVehicle();
  delay(500);
}
