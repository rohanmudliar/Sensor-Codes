int relay = 8;
volatile byte relayState = LOW;
int PIRInterrupt = 2;
long lastDebounceTime = 0;  
long debounceDelay = 5000;
void setup() {
  pinMode(relay, OUTPUT); // Pin for relay module set as output
  digitalWrite(relay, HIGH);
  pinMode(PIRInterrupt, INPUT); // PIR motion sensor set as an input
  attachInterrupt(digitalPinToInterrupt(PIRInterrupt), detectMotion, RISING);
  Serial.begin(9600);
}
void loop() {
    if((millis() - lastDebounceTime) > debounceDelay && relayState == HIGH){  // If 10 seconds have passed, the relay is turned off
    digitalWrite(relay, HIGH);
    relayState = LOW;
    Serial.println("OFF");
  }delay(50);
}

void detectMotion() {
  Serial.println("Motion");
  if(relayState == LOW){
    digitalWrite(relay, LOW);
  }
  relayState = HIGH;  
  Serial.println("ON");
  lastDebounceTime = millis();
}
