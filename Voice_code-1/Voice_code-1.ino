#include <SoftwareSerial.h>
String voice;
SoftwareSerial BTSerial(2, 3); // RX | TX
int BULB1 = 13;

void On() {
  digitalWrite (BULB1, HIGH);
}

void of() {
  digitalWrite (BULB1, LOW);
}

void setup() {
  pinMode(BULB1, OUTPUT); // Trigger for Bulb 1
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void voiceCode() {
   while(BTSerial.available()){
    delay(10);
    char c = BTSerial.read();
    if (c == '#')
    {
      break;
    }
    voice += c;
  }
  if (voice.length() > 0) {
    Serial.println(voice);
    if ((voice == "off road")||(voice == "of"))
    {
      On();
    }
    if ((voice == "computer can you please turn on the light")||(voice == "on")  )
    {
      of();
    }
    voice = "";
  }
}

void onOff() {
  if(BTSerial.available())
  {
    Serial.println("BTSerial is available");
    char data=BTSerial.read();
    switch (data) {
    case 'a':
      digitalWrite(BULB1,1);
      Serial.println("Changed the BULB1 value to HIGH");
      break;
    case 'b':
      digitalWrite(BULB1,0);
      Serial.println("Changed the BULB1 value to LOW");
      break;
    default: 
    break;
    }
  }
}

void loop() {
  int external = BTSerial.read();
   if (external = 49) {
    Serial.println(external);
    voiceCode();
   }
   else {
    Serial.println(external);
    onOff();
   }
}
















