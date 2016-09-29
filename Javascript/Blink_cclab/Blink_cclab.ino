int ledPin = 3;

bool ledState = true;

int buttonPin = 5;
int debounceDelay = 10;


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  int oldButtonState = 0;
  int newButtonState = 0;

    oldButtonState = digitalRead(buttonPin);
  delay(debounceDelay);
  newButtonState = digitalRead(buttonPin);

  if (oldButtonState != newButtonState) {
    if (newButtonState == LOW) {
      ledState = !ledState;
    }
    }

if (ledState) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
    


}
