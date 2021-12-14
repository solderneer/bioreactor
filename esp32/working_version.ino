#include <WiFi.h>
#include <ThingsBoard.h>
#include <ArduinoHttpClient.h>
#include "esp_wpa2.h" 
#define EAP_IDENTITY "zcabznf@ucl.ac.uk"
#define EAP_PASSWORD "Hadraezak@0809"
const char* ssid = "eduroam";
#define TOKEN               "McrggnEOPaTrnwPTcrZm"
#define THINGSBOARD_SERVER  "thingsboard.cloud"
WiFiClient espClient;
ThingsBoard tb(espClient);
int messageCounter = 0;
int status = WL_IDLE_STATUS;

float updateDelay = 10000;
int lastUpdate  = 0;    
bool subscribed = false;  
void sendCommandPacket(bool rw, uint8_t subsystem, uint8_t value_type, double value);
float phGoal = 6.7, tempGoal = 30, speedGoal = 1000;

#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

#include <Wire.h>

#define SLAVE_ADDR 9
#define I2C_SDA 21
#define I2C_SCL 22

// Union datatype for processing doubles
union float_buf { float f; byte b[4]; };
typedef struct {
  double setpoint;
  double input;
  double output;
  double kp;
  double ki;
  double kd;
} PIDLog;

RPC_Response processSetPh(const RPC_Data &data)
{
  phGoal = data;
//  Serial.print("Received setPh with value");
//  Serial.println(phGoal);

  sendCommandPacket(1, 2, 0, phGoal);
  return RPC_Response(NULL, phGoal);
}

RPC_Response processGetPh(const RPC_Data &data)
{
//  Serial.println("Received the getPh method");

  return RPC_Response(NULL, phGoal);
}



RPC_Response processSetTemp(const RPC_Data &data)
{

  tempGoal = data;
//  Serial.print("Received setTemp with value");
//  Serial.println(tempGoal);

  sendCommandPacket(1, 1, 0, tempGoal);
  return RPC_Response(NULL, tempGoal);
}

RPC_Response processGetTemp(const RPC_Data &data)
{
//  Serial.println("Received the getTemp method");

  return RPC_Response(NULL, tempGoal);
}



RPC_Response processSetSpeed(const RPC_Data &data)
{
  speedGoal = data;
//  Serial.print("Received setSpeed with value");
//  Serial.println(speedGoal);
  sendCommandPacket(1, 3, 0, speedGoal);
  return RPC_Response(NULL, speedGoal);
}

RPC_Response processGetSpeed(const RPC_Data &data)
{
//  Serial.println("Received the getSpeed method");/

  return RPC_Response(NULL, speedGoal);
}

RPC_Callback callbacks[] = {
  { "getPh",         processGetPh },
  { "setPh",         processSetPh },
  { "getTemp",         processGetTemp },
  { "setTemp",         processSetTemp },
  { "getSpeed",         processGetSpeed },
  { "setSpeed",         processSetSpeed },
};

/********** UTILITY FUNCTIONS PROTOTYPES ****************/
// Receive the log packet into a PIDLog struct
int receiveLogPacket(PIDLog* log);

// Unload the log packet from some byte buffer
PIDLog unloadLogPacket(byte* buffer);

// Unload a float from a buffer at some offset
double unloadFloat(byte* buffer, int offset);

// Load a float into a buffer at some offset
void loadFloat(double f, byte* buffer, int offset);

// rw: 0->read, 1->write
// subsystem: 0->nothing, 1->temp, 2->ph, 3->motor
// value: 0->setpoint, 1->kp, 2->ki, 3->kd


void connectWifi() {
  Serial.println();
  Serial.print(F("Connecting to "));
  Serial.println(ssid);
  WiFi.disconnect(true); 
  WiFi.mode(WIFI_STA);   
  esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY));
  esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD));
  esp_wifi_sta_wpa2_ent_enable();
  WiFi.begin(ssid);       //connect to wifi
  while (WiFi.status() != WL_CONNECTED) {
delay(500);
    Serial.print(F("."));
  }
  Serial.println("");
  Serial.println(F("WiFi is connected!"));
  Serial.println(F("IP address set: "));
  Serial.println(WiFi.localIP()); //print LAN IP
}





void setup() {
  Serial.begin(115200);
  connectWifi();
    // put your setup code here, to run once:
  Wire.begin(I2C_SDA, I2C_SCL); // Configure the pins

  // Setting the setpoint of the pH subsystem to 10.0
  sendCommandPacket(1, 2, 0, 10.0);
  delay(100);
  // Setting the Kp of the pH subsystem to 5.0
  sendCommandPacket(1, 2, 1, 5.0);
}

void loop() {
  long now = millis();
  delay(1100);
    // Request the pH subsystem data
    if(messageCounter % 3 ==0){
      sendCommandPacket(0, 1, 0, 0.0);
    }
    else if(messageCounter % 3 == 1){
      sendCommandPacket(0, 2, 0, 0.0);
    }
    else if(messageCounter % 3 == 2){
      sendCommandPacket(0, 3, 0, 0.0);
    }
  
  // Receive the pH subsystem data
  PIDLog out; 
  int stat = receiveLogPacket(&out);

  Serial.println("------------------");
  Serial.println(stat);
  Serial.println(out.setpoint);
  Serial.println(out.input);
  Serial.println(out.output);
  Serial.println(out.kp);
  Serial.println(out.ki);
  Serial.println(out.kd);
  Serial.println("------------------");
//-----------------------------------------------------------TAHA
  
//-----------------------------------------------------------TAHA
  delay(1000);
  // Reconnect to WiFi, if needed
  if (WiFi.status() != WL_CONNECTED) {
    connectWifi();
    return; }
  // Reconnect to ThingsBoard, if needed
  if (!tb.connected()) {
// Connect to the ThingsBoard Serial.print("Connecting to: "); Serial.print(THINGSBOARD_SERVER); Serial.print(" with token "); Serial.println(TOKEN);
    if (!tb.connect(THINGSBOARD_SERVER, TOKEN)) {
      Serial.println("Failed to connect");
      return;
} }

if (!subscribed) {
    Serial.println("Subscribing for RPC...");

    // Perform a subscription. All consequent data processing will happen in
    // callbacks as denoted by callbacks[] array.
    if (!tb.RPC_Subscribe(callbacks, COUNT_OF(callbacks))) {
      Serial.println("Failed to subscribe for RPC");
      return;
    }

    Serial.println("Subscribe done");
    subscribed = true;
  }

  if (now > lastUpdate + updateDelay) {
    
    tb.sendTelemetryInt("ph_Val", 12.3);    
    
    lastUpdate += updateDelay;
  }
  
   Serial.print("phGoal value is ");
   Serial.println(phGoal);
   
   Serial.print("tempGoal value is ");
   Serial.println(tempGoal);
   
   Serial.print("speedGoal value is ");
   Serial.println(speedGoal);

   Serial.println(" ");

  if(messageCounter % 3 == 0){
    tb.sendTelemetryFloat("Temperature", out.input);
    tb.sendTelemetryFloat("User Temperature", tempGoal);    
    tb.sendTelemetryFloat("Output Temperature", out.output);
    tb.sendTelemetryFloat("Temperature P", out.kp);
    tb.sendTelemetryFloat("Temperature I", out.ki);
    tb.sendTelemetryFloat("Temperature D", out.kd);
  }
  else if(messageCounter  % 3 == 1){
    tb.sendTelemetryFloat("pH", out.input);   
    tb.sendTelemetryFloat("User pH", phGoal); 
    tb.sendTelemetryFloat("Output pH", out.output);
    tb.sendTelemetryFloat("pH P", out.kp);
    tb.sendTelemetryFloat("pH I", out.ki);
    tb.sendTelemetryFloat("pH D", out.kd);
  }
  else if(messageCounter % 3 == 2){
    tb.sendTelemetryFloat("Rotating speed", out.input); 
    tb.sendTelemetryInt("User Rotating speed", speedGoal);  
    tb.sendTelemetryFloat("Output Rotating speed", out.output);
    tb.sendTelemetryFloat("Rotating speed P", out.kp);
    tb.sendTelemetryFloat("Rotating speed I", out.ki);
    tb.sendTelemetryFloat("Rotating speed D", out.kd);
  }
  tb.loop();

  if(messageCounter == 1001){
    messageCounter == 0;
  }
  else{
    messageCounter ++;
  }
  
}

/************* UTILITY FUNCTIONS *******************/
void sendCommandPacket(bool rw, uint8_t subsystem, uint8_t value_type, double value) {
  byte command[5] = {0, 0, 0, 0, 0};
  command[0] |= (rw << 7);
  command[0] |= (subsystem & 0b00000011) << 5;
  command[0] |= (value_type & 0b00000011) << 3;
  loadFloat(value, command, 1);

  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(command, 5);
  Wire.endTransmission();
}

double unloadFloat(byte* buffer, int offset) {
  int i;
  union float_buf data;

  for(i = 0; i < 4; i++) {
    data.b[i] = buffer[i + offset];
  }

  return (double)data.f;
}

int receiveLogPacket(PIDLog* log) {
  byte buf[24];
  int i = 0;

  uint16_t received = 0;
  Wire.requestFrom(SLAVE_ADDR, 24);
  delay(100);
  while(Wire.available()) {
    buf[received] = Wire.read();
    received++;
  }

  if(received != 24) {
    return -1;
  }
  
  log->setpoint = unloadFloat(buf, 0);
  log->input = unloadFloat(buf, 4);
  log->output = unloadFloat(buf, 8);
  log->kp = unloadFloat(buf, 12);
  log->ki = unloadFloat(buf, 16);
  log->kd = unloadFloat(buf, 20);

  return 0;
}

void loadFloat(double f, byte* buffer, int offset) {
  int i;
  union float_buf data;
  data.f = (float)f;

  for(i = 0; i < 4; i++) {
    buffer[i + offset] = data.b[i];
  }
}

// Takes the log packet and populates the transmit buffer
void loadLogPacket(PIDLog* log, byte* buffer) {
  loadFloat(log->setpoint, buffer, 0); 
  loadFloat(log->input, buffer, 4); 
  loadFloat(log->output, buffer, 8);  
  loadFloat(log->kp, buffer, 12);
  loadFloat(log->ki, buffer, 16);
  loadFloat(log->kd, buffer, 20);
}
