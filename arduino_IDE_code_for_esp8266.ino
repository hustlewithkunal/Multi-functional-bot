#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "ssid";
const char* password = "password";

ESP8266WebServer server(80);

const int leftMotorPin1 = D1;
const int leftMotorPin2 = D2;
const int rightMotorPin1 = D3;
const int rightMotorPin2 = D4;
const int leftMotorENB = D0;
const int rightMotorENB = D5;
bool botMotion = false;
int direction = 0;

void setup() {
  Serial.begin(250000);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Initialize motor pins
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(leftMotorENB, OUTPUT);
  pinMode(rightMotorENB, OUTPUT);

  // Define the control routes for movement
  server.on("/", [](){
    String htmlContent = "<!DOCTYPE html><html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><style>body {font-family: Arial, sans-serif;background-image: url('https://giffiles.alphacoders.com/214/214311.gif');background-size: cover;background-position: center;background-repeat: no-repeat;color: #ccc; opacity: 1;} .container {display: flex; flex-direction: row; justify-content: center; align-items: center;}.arrow {font-size: 40px; padding: 20px; color: grey;} .view-data {font-size: 20px; padding: 10px 20px; margin-top: 20px; border: none; background-color: transparent; cursor: pointer; color: #ccc;} h1 {text-align: center; color: #2596be; font-size: 36px; font-weight: lighter; border: 2px solid #2596be; padding: 10px; opacity: 1;}</style></head><body><h1>CONTROL MY ROBOT</h1><div class=\"container\"><div class=\"arrow\" onclick=\"sendCommand('/forward')\">&#8593;</div><div class=\"arrow\" onclick=\"sendCommand('/left')\">&#8592;</div><div class=\"arrow\" onclick=\"sendCommand('/stop')\">&#10033;</div><div class=\"arrow\" onclick=\"sendCommand('/right')\">&#8594;</div><div class=\"arrow\" onclick=\"sendCommand('/backward')\">&#8595;</div></div><div style=\"text-align:center; margin-top: 20px;\"><div class=\"arrow\" onclick=\"sendCommand('/retrace')\">&#x21B7;</div><div class=\"arrow\" onclick=\"sendCommand('/reset')\">&#x21BA;</div><button class=\"view-data\" onclick=\"viewData()\">View Data</button></div><div class=\"data-container\" id=\"dataContainer\"></div><script>function sendCommand(command) { fetch(command); } function viewData() { fetch('/view-data') .then(response => response.text()) .then(data => { document.getElementById('dataContainer').innerHTML = '<h2>Data:</h2><div>' + data + '</div>'; }); }</script></body></html>";
    server.send(200, "text/html", htmlContent);
  });

  // Motion control routes
  server.on("/forward", [](){ startMoving(1); });
  server.on("/backward", [](){ startMoving(2); });
  server.on("/left", [](){ startMoving(3); });
  server.on("/right", [](){ startMoving(4); });
  server.on("/retrace", [](){ rotate180Degrees(); });
  server.on("/stop", [](){ stopMoving(); });

  server.begin();
}

void loop() {
  server.handleClient();

  if (botMotion) {
    switch (direction) {
      case 0: stopMoving(); break;
      case 1: moveForward(); break;
      case 2: moveBackward(); break;
      case 3: moveLeft();  break;
      case 4: moveRight();  break;
      default: stopMoving(); break;
    }
    delay(250);
  }
}

void moveBackward() {
  digitalWrite(leftMotorENB, HIGH);
  digitalWrite(rightMotorENB, HIGH);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

void moveForward() {
  digitalWrite(leftMotorENB, HIGH);
  digitalWrite(rightMotorENB, HIGH);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
}

void moveLeft() {
  digitalWrite(leftMotorENB, HIGH);
  digitalWrite(rightMotorENB, HIGH);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);

}

void moveRight() {
  digitalWrite(leftMotorENB, HIGH);
  digitalWrite(rightMotorENB, HIGH);
  digitalWrite(leftMotorPin1,LOW );
  digitalWrite(leftMotorPin2, HIGH);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);

}

void startMoving(int dir) {
  botMotion = true;
  direction = dir;
}

void stopMoving() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
  botMotion = false;
  direction = 0;
}

void rotate180Degrees() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
  delay(1500); // Adjust delay to suit the bot's rotation speed
  stopMoving();
}

