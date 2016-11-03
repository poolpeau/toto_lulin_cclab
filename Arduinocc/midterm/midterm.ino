#include <NewPing.h>

#define trigPin 10
#define echoPin 11
#define ledStrip 3

int minDistance = 0;
int maxDistance = 400;

int  brightness, brightness2;


//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(ledStrip, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(ledStrip, brightness);
 long duration, distance, inches, cm,cm2;

  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  delay(300);

  //fade in 

  duration = pulseIn(trigPin, HIGH);
  ////

  //inches = microSecondsToInches(duration);
     // cm = microsecondsToCm(duration);  

  if (cm<60)   // If Distance is less than 40 cm then do the following:

 {    // Maps the LED brightness inversely proportional to the distance 

  cm2 = 40 - cm;  

  brightness2 = map(cm2 , 0, 60, 0, 255);


  analogWrite(ledStrip, brightness2);  // Writes the fadeValue to pin 9 
 } 
 else
 {
   analogWrite(ledStrip, 0);  //If distance is larger than 40cm then switch off  

 }
}
