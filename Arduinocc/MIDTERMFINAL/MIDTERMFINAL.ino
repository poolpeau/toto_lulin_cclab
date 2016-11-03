
int trigPin = 10;
int ledStrip = 3;
 
 int  brightness, brightness2 ;
 
void setup()

  {
         Serial.begin(9600);
   }
 
void loop()
 {

   long duration, inches, cm, cm2;
 
 
     pinMode(trigPin, OUTPUT);
     digitalWrite(trigPin, LOW);
     delayMicroseconds(5);
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(5);
     digitalWrite(trigPin, LOW);
 
  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
     
     pinMode(trigPin, INPUT);
    duration = pulseIn(trigPin, HIGH);
 
  // convert the time into a distance
     inches = microsecondsToInches(duration);
     cm = microsecondsToCentimeters(duration);


  if (cm<100) {   

  cm2 = 100 - cm;  
 brightness2 = map(cm , 20, 100, 0, 255);

delay(50);
  analogWrite(ledStrip, brightness2);  // Writes the fadeValue to pin 9 
  //digitalWrite(ledPin, HIGH);
  //delay(5);
  //digitalWrite(ledPin, LOW);
  //delay(5);
 } 
 else
 {
   analogWrite(ledStrip, 0); 

 }


 



    //Serial.print(inches);
    //Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    //Serial.println();
    //Serial.print("Centi 2  :");
    //Serial.print(  brightness2 );
 
   Serial.println();
//-------------End-Debugging------------------------------//

   
  delay(10);  // Short Delay allows for smoother fading

 }  //End Loop

 

//-------------Functions-------------------------------// 
long microsecondsToInches(long microseconds)
 {
   // According to Parallax's datasheet for the PING))), there are
   // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
   // second).  This gives the distance travelled by the ping, outbound
   // and return, so we divide by 2 to get the distance of the obstacle.
   // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
   return microseconds / 74 / 2;
 }
 
long microsecondsToCentimeters(long microseconds)
 {
   // The speed of sound is 340 m/s or 29 microseconds per centimeter.
   // The ping travels out and back, so to find the distance of the
   // object we take half of the distance travelled.
   return microseconds / 29 / 2;
 }


