int button = 5;
int buzzer =  3;
int buttonValue = 0;
//int tone = random(100,200);

void setup() {
  // put your setup code here, to run once:

 Serial.begin(9600); 
pinMode( button, INPUT);
pinMode(buzzer, OUTPUT);

 

}

void loop() {
  // put your main code here, to run repeatedly:

  
buttonValue = digitalRead(button);
if (buttonValue == HIGH) {
  digitalWrite(buzzer,HIGH);
    tone(3,300,10);
  }else {
   
  digitalWrite(buzzer, LOW);
  }

}

