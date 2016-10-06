  //This example code is in the public domain.

int trig = 8;
int echo = 7;
int ledPin = 9;
int brightness = 0;
long duration, distance; 

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
    pinMode (trig, OUTPUT);
  pinMode( echo, INPUT);
  pinMode(ledPin,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  //int sensorValue = analogRead(A0);
  // print out the value you read:
  //Serial.println(sensorValue);
  //brightness = map(sensorValue, 10, 150, 0, 255);
  //analogWrite(ledPin,brightness);
  //delay(1);        // delay in between reads for stability


  digitalWrite(trig,HIGH);
  delayMicroseconds(700);
  digitalWrite(trig,LOW);
    delayMicroseconds(300);

  duration = pulseIn(echo,HIGH);
  distance = duration/58;
  Serial.println(distance);
  analogWrite (ledPin,distance);

  //delay(100);
  
}
