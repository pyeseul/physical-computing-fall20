// set up variables for pins and values (button)
int buttonPin = 2;
int buttonState = 0;

// set up variables for pins and values (potentiometer)
int potPin = A0;
int potState =0;
int potState_mapped =0;

// set up variables for pins and values (LEDs)
int ledPinG = 3;
int ledPinY = 4;

void setup() {

  // setting up pin modes for a button, a potentiometer, and two LEDs
  pinMode(buttonPin, INPUT);
  pinMode(potPin, INPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinY, OUTPUT);

  // initiate serial with 9600 baud
  Serial.begin(9600);
}

void loop() {

  // digitalRead() the button state, and control green led accordingly using digitalWrite()
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(ledPinG, HIGH);
  } else {
    digitalWrite(ledPinG, LOW);  
  }

  // analogRead() the potentiometer state, map the value, and use the mapped value to control the brightness of yellow led
  potState = analogRead(potPin);  
  potState_mapped = map(potState, 0, 1023, 0, 255);
  analogWrite(ledPinY, potState_mapped*85);
  
  delay(30);

  // print out potState and potState_mapped on the serial monitor
  Serial.print(potState);
  Serial.print(" , ");
  Serial.println(potState_mapped);
  
}
