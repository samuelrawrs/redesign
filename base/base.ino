/////////////////////IOT CODE START/////////////////////////

#include <WiFi.h>
#include <PubSubClient.h> // https://github.com/knolleary/pubsubclient/releases/tag/v2.3
#include <ArduinoJson.h> // https://github.com/bblanchon/ArduinoJson/releases/tag/v5.0.7

//-------- Customise these values -----------
const char* ssid = "cyanpiggy";
const char* password = "heyheyyouyou";

#define ORG "5csim8"
#define DEVICE_TYPE "NODEMCU"
#define DEVICE_ID "redesign_esp32"
#define TOKEN "ukW?19w_PokNTGLlIg"
//-------- Customise the above values --------

char server[] = ORG ".messaging.internetofthings.ibmcloud.com";
char authMethod[] = "use-token-auth";
char token[] = TOKEN;
char clientId[] = "d:" ORG ":" DEVICE_TYPE ":" DEVICE_ID;

const char eventTopic1[] = "iot-2/evt/touch1/fmt/json";
const char eventTopic2[] = "iot-2/evt/touch2/fmt/json";
const char eventTopic3[] = "iot-2/evt/touch3/fmt/json";
const char eventTopic4[] = "iot-2/evt/needy/fmt/json";

const char eventTopic5[] = "iot-2/evt/touch1data/fmt/json";
const char eventTopic6[] = "iot-2/evt/touch2data/fmt/json";
const char eventTopic7[] = "iot-2/evt/touch3data/fmt/json";

WiFiClient wifiClient;

void callback(char* topic, byte* payload, unsigned int payloadLength) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < payloadLength; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

PubSubClient client(server, 1883, callback, wifiClient);

int publishInterval = 500; // 5 seconds//Send adc every 5sc
long lastPublishMillis;

/////////////////////IOT CODE END/////////////////////////



#include "pitches.h"
#include "Tone32.h"
#include "Unistep2.h"

// define pins
#define SPEAKER_PIN 2
#define VIBRATOR_PIN 13
#define TOUCH_PIN_1 4
#define TOUCH_PIN_2 12
#define TOUCH_PIN_3 14

#define LED1_PIN 17
#define LED2_PIN 5


// define channels
#define SPEAKER_CHANNEL 0
#define VIBRATE_CHANNEL 2
#define NO_VIBRATE_CHANNEL 4

//define intervals
#define INTERVAL1 10
#define INTERVAL2 500
#define INTERVAL3 20
 
unsigned long time_1 = 0;
unsigned long time_2 = 0;
unsigned long time_3 = 0;
unsigned long time_4 = 0;
unsigned long notouch_start = 0;

 

// define others
#define freq 800000
#define resolution 8
#define tempo 200

//assign variables
unsigned long curTime;
unsigned long beginTime;

int TOUCH_SENSOR_VALUE1 = 0;
int TOUCH_SENSOR_VALUE2 = 0;
int TOUCH_SENSOR_VALUE3 = 0;

int VALUE_THRESHOLD1 = 0;
int VALUE_THRESHOLD2 = 0;
int VALUE_THRESHOLD3 = 0;

int sensitivity = 8;
int extra_sensitive = 3;

int touch1_count = 0;
int touch1_state = 0; // 0 means not touched, 1 means touched
int detect1_state = 0;
int touch2_count = 0;
int touch2_state = 0;
int detect2_state = 0;
int touch3_count = 0;
int touch3_state = 0;
int detect3_state = 0;

int needy_state = 0;

int incomingByte = 0;

int countno = 5;
int needytime = 180000;
int needy_placeholder = needytime;


int curState[3] = {0, 0, 0};
int simple_state;
int ledState = LOW;             // ledState used to set the LED


void setup()
{
  Serial.begin(115200);
  // sets the pins as outputs:
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(SPEAKER_PIN , OUTPUT);
  ledcAttachPin(SPEAKER_PIN, SPEAKER_CHANNEL);
  pinMode(VIBRATOR_PIN , OUTPUT);
  digitalWrite(VIBRATOR_PIN, LOW);

  // set up the channel where piezzo motor will NOT vibrate if connected to it
  ledcSetup(NO_VIBRATE_CHANNEL, freq, resolution);
  ledcWrite(NO_VIBRATE_CHANNEL, 0);

  // set up the channel where piezzo motor will vibrate if connected to it
  ledcSetup(VIBRATE_CHANNEL, freq, resolution);
  ledcWrite(VIBRATE_CHANNEL, 255);
  // get average readings of touch sensors
  dynamic_threshold_test();
  wifiConnect();
  mqttConnect();
  Serial.println("Setup is complete");
}

int dynamic_threshold_test() {
  for (int i=0; i<7; i++) {
    VALUE_THRESHOLD1 += touchRead(TOUCH_PIN_1);
    VALUE_THRESHOLD2 += touchRead(TOUCH_PIN_2);
    VALUE_THRESHOLD3 += touchRead(TOUCH_PIN_3);
    Serial.println(String(touchRead(TOUCH_PIN_1)) + " " + String(touchRead(TOUCH_PIN_2)) + " " + String(touchRead(TOUCH_PIN_3)) + "\n");
    delay(50);
  }
  VALUE_THRESHOLD1 = (VALUE_THRESHOLD1 / 7) - extra_sensitive;
  VALUE_THRESHOLD2 = (VALUE_THRESHOLD2 / 7) - sensitivity;
  VALUE_THRESHOLD3 = (VALUE_THRESHOLD3 / 7) - sensitivity;
  Serial.println("value_threshold1 is: " + String(VALUE_THRESHOLD1) + "\n");
  Serial.println("value_threshold2 is: " + String(VALUE_THRESHOLD2) + "\n");
  Serial.println("value_threshold3 is: " + String(VALUE_THRESHOLD3) + "\n");
}


void check_LEDs() {
  if (millis() >= time_2 + INTERVAL2 ) {
    time_2+=INTERVAL2;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW && needy_state == 1) {
      ledState = HIGH;
      Serial.println("LED HIGH");
    } else {
      ledState = LOW;
      Serial.println("LED LOW");
    }
    // set the LED with the ledState of the variable:
    digitalWrite(LED1_PIN, ledState);
    digitalWrite(LED2_PIN, ledState);
  }

}

void needy_mode(int simple_state){
//  Serial.print("interval, needy_state:");
//  Serial.print(millis()-notouch_start);
//  Serial.print(" ");
//  Serial.println(needy_state);
  if (millis() >= time_3 + INTERVAL3) {
   time_3+=INTERVAL3;
   
   if (needy_state == 3){  //special case
    Serial.println("i entered the loop");
    playSong(4); // needy tune
    needy_state = 1; //needing touch
    needy_placeholder = 0;
   }
   
   else if (simple_state == 0 && notouch_start == 0 || simple_state !=0 && needy_state == 0 || simple_state == 0 && needy_state == 2){  // restart timer (first instance and when another touch is detected)
    notouch_start = millis();
    needy_state = 0; //not needing touch
    countno = 5;
   }
   else if (simple_state !=0 && needy_state == 1){
    needy_state = 2;  //now not needing touch, and no sound playing
    countno = 100;
    needy_placeholder = needytime;
   }
   else if (simple_state == 0 && notouch_start > 0){  //if untouched and timer still going
    if (millis()-notouch_start > needy_placeholder){
      playSong(4); // needy tune
      needy_state = 1; //needing touch
    } 
   }
   }
  }




// this fn checks for 2s to determine the final state (which sensors have been triggered) after the 2 seconds
void check_touch_sensors(int curState[]) {
  if (millis() >= time_1 + INTERVAL1) {
    time_1+=INTERVAL1;

    //Serial.println("CURRENT TIME IS: " + String(millis() - beginTime));
    TOUCH_SENSOR_VALUE1 = touchRead(TOUCH_PIN_1);
    TOUCH_SENSOR_VALUE2 = touchRead(TOUCH_PIN_2);
    TOUCH_SENSOR_VALUE3 = touchRead(TOUCH_PIN_3);
    //uncomment
    Serial.print("touch sensors: " + String(TOUCH_SENSOR_VALUE1));
    Serial.print(" " + String(TOUCH_SENSOR_VALUE2));
    Serial.print(" " + String(TOUCH_SENSOR_VALUE3));
    Serial.println("  State:" + String(curState[0]) + String(curState[1]) + String(curState[2]));

    // sensor 1 first successful touch
    if(TOUCH_SENSOR_VALUE1 < VALUE_THRESHOLD1 && TOUCH_SENSOR_VALUE1 > 0 && touch1_state == 0) {
      Serial.println(String(TOUCH_SENSOR_VALUE1));
      touch1_state = 1;
    }
     // sensor 1 subsequent touches
    else if(TOUCH_SENSOR_VALUE1 < VALUE_THRESHOLD1 && touch1_state == 1) {
      touch1_count+= 1;
      if (touch1_count > countno+4) {
        touch1_state = 0;
        touch1_count = 0;
        curState[0] = 1;
        detect1_state = 1;
      }
    }
    else {
      touch1_state = 0;
      touch1_count = 0;
      curState[0] = 0;
      detect1_state = 0;
    }

    // sensor 2 first successful touch
    if(TOUCH_SENSOR_VALUE2 < VALUE_THRESHOLD2 && TOUCH_SENSOR_VALUE2 > 0 && touch2_state == 0) {
      Serial.println(String(TOUCH_SENSOR_VALUE2));
      touch2_state = 1;
    }
     // sensor 2 subsequent touches
    else if(TOUCH_SENSOR_VALUE2 < VALUE_THRESHOLD2 && touch2_state == 1) {
      touch2_count+= 1;
      if (touch2_count > countno) {
        touch2_state = 0;
        touch2_count = 0;
        curState[1] = 1;
        detect2_state = 1;
      }
    }
    else {
      touch2_state = 0;
      touch2_count = 0;
      curState[1] = 0;
      detect2_state = 0;
    }

    // sensor 3 first successful touch
    if(TOUCH_SENSOR_VALUE3 < VALUE_THRESHOLD3 && TOUCH_SENSOR_VALUE3 > 0 && touch3_state == 0) {
      Serial.println(String(TOUCH_SENSOR_VALUE3));
      touch3_state = 1;
    }
     // sensor 1 subsequent touches
    else if(TOUCH_SENSOR_VALUE3 < VALUE_THRESHOLD3 && touch3_state == 1) {
      touch3_count+= 1;
      if (touch3_count > countno) {
        touch3_state = 0;
        touch3_count = 0;
        curState[2] = 1;
        detect3_state = 1;
      }
    }
    else {
      touch3_state = 0;
      touch3_count = 0;
      curState[2] = 0;
      detect3_state = 0;
    }
  }

}


// this fn takes in the result of check_touch_sensor and plays the corresponding tone
void playState(int simple_state) {
  // check ALL permutations
  if (needy_state!=2){
    if (simple_state == 1) {
    Serial.println("melody 1 should be playing");
    playSong(1);
  } else if (simple_state == 2) {
    Serial.println("melody 2 should be playing");
    playSong(2);
  } else if (simple_state == 3) {
    Serial.println("melody 3 should be playing");
    playSong(3);
  } 
}
}

int state_simpler(int curState[]) {
  // check ALL permutations
  if (curState[0] == 0 && curState[1] == 0 && curState[2] == 0) {
    simple_state = 0;
  } else if (curState[0] == 1 && curState[1] == 0 && curState[2] == 0) {
    simple_state = 1;
  } else if (curState[0] == 0 && curState[1] == 1 && curState[2] == 0) {
    simple_state = 2;
  } else if (curState[0] == 0 && curState[1] == 0 && curState[2] == 1) {
    simple_state = 3;
  } else if (curState[0] == 1 && curState[1] == 1 && curState[2] == 0) {
    simple_state = 4;
  } else if (curState[0] == 1 && curState[1] == 0 && curState[2] == 1) {
    simple_state = 5;
  } else if (curState[0] == 0 && curState[1] == 1 && curState[2] == 1) {
    simple_state = 6;
  } else if (curState[0] == 1 && curState[1] == 1 && curState[2] == 1) {
    simple_state = 7;
  }
  return(simple_state);
}

//////////// IOT STUFF START/////////////

void wifiConnect() {  //combined wifi and mqqt connect together
  Serial.print("Connecting to "); Serial.print(ssid);
  WiFi.begin(ssid, password);
  time_4 = millis();
  while (WiFi.status() != WL_CONNECTED) {
    if (millis()-time_4<250){
    Serial.print(".");
    delay(50);
    }
    else{
      time_4 = 0;
      Serial.print("WIFI DID NOT CONNECT");
      block_blink_led(0);
      break;
    }
  }
  if (WiFi.status() == WL_CONNECTED){
    block_blink_led(1);
    Serial.print("WiFi connected, IP address: "); Serial.println(WiFi.localIP());
}
}

void mqttConnect() {
    time_4 = millis();
    while (!client.connect(clientId, authMethod, token)) {
      if (millis()-time_4<250){
      Serial.print(".");
      delay(50);
      }
      else{
        time_4 = 0;
        Serial.print("MQQT DID NOT CONNECT");
        break;
      }
  }
}



void block_blink_led(int x){
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
  if (x == 0) { //error
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
    delay(500);
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, HIGH);
    delay(500);
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
    delay(500);
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, HIGH);
    delay(500);
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
  }
  else if (x == 1) {  //good to go
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    delay(500);
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
  } 
}



void publishData() {

  String payload1 = "{\"Sensor_data\":{\"Touch 1\":";
  payload1 += String(detect1_state, DEC);
  payload1 += "}}";

  String payload2 = "{\"Sensor_data\":{\"Touch 2\":";
  payload2 += String(detect2_state, DEC);
  payload2 += "}}";

  String payload3 = "{\"Sensor_data\":{\"Touch 3\":";
  payload3 += String(detect3_state, DEC);
  payload3 += "}}";

  String payload4 = "{\"Sensor_data\":{\"Needy\":";
  payload4 += String(needy_state, DEC);
  payload4 += "}}";

  String payload5 = "{\"Sensor_data\":{\"Touch1_data\":";
  payload5 += String(TOUCH_SENSOR_VALUE1, DEC);
  payload5 += "}}";

  String payload6 = "{\"Sensor_data\":{\"Touch2_data\":";
  payload6 += String(TOUCH_SENSOR_VALUE2, DEC);
  payload6 += "}}";

  String payload7 = "{\"Sensor_data\":{\"Touch3_data\":";
  payload7 += String(TOUCH_SENSOR_VALUE3, DEC);
  payload7 += "}}";


  Serial.print("Sending payload: "); 

  if (client.publish(eventTopic1, (char*) payload1.c_str())) {
    Serial.println("Publish1 OK");
  } else {
    Serial.println("Publish1 FAILED");
  }
  if (client.publish(eventTopic2, (char*) payload2.c_str())) {
    Serial.println("Publish2 OK");
  } else {
    Serial.println("Publish2 FAILED");
  }
  if (client.publish(eventTopic3, (char*) payload3.c_str())) {
    Serial.println("Publish3 OK");
  } else {
    Serial.println("Publish3 FAILED");
  }
  if (client.publish(eventTopic4, (char*) payload4.c_str())) {
    Serial.println("Publish4 OK");
  } else {
    Serial.println("Publish4 FAILED");
  }
  if (client.publish(eventTopic5, (char*) payload5.c_str())) {
    Serial.println("Publish5 OK");
  } else {
    Serial.println("Publish5 FAILED");
  }
  if (client.publish(eventTopic6, (char*) payload6.c_str())) {
    Serial.println("Publish6 OK");
  } else {
    Serial.println("Publish6 FAILED");
  }
   if (client.publish(eventTopic7, (char*) payload7.c_str())) {
    Serial.println("Publish7 OK");
  } else {
    Serial.println("Publish7 FAILED");
  }
}

//////////// IOT STUFF END/////////////
void esp_arduino_debug(){
  if (Serial.available() > 0) {
  incomingByte = Serial.read();
  if (incomingByte == 49){  //input 1 in serial monitor to restart the esp
    Serial.println(" RESTARTING ESP NOW");
    ESP.restart();
  }
  else if (incomingByte == 50){
    needy_state = 3;
    Serial.println("needy_state is now 3");
  }
  }
}

void loop(){
  esp_arduino_debug();
  needy_mode(simple_state);
  check_LEDs();

  check_touch_sensors(curState);
  
  simple_state = state_simpler(curState);
  
  playState(simple_state);

  if (millis() - lastPublishMillis > publishInterval) {
    publishData();
    lastPublishMillis = millis();
  }
}
