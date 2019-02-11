const int ledPin = 8;   
const int ldrPin = A0;  

void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  
  pinMode(ldrPin, INPUT);   
}

void loop() {
   int ldrStatus = analogRead(ldrPin);  

  //check if the LDR status is <= 300
  //if it is, the LED is HIGH

   if (ldrStatus < 1000) { //use flashlight to act as sun..
     digitalWrite(ledPin, HIGH);               //turn LED on
    //Serial.println("LDR is DARK, LED is ON");
    }
  else {

    digitalWrite(ledPin, LOW);          //turn LED off
    //Serial.println("---------------");
  }
  Serial.println(ldrStatus);
}
