#define enA 9
#define in1 10
#define in2 11

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in2, HIGH);
  // Set initial rotation direction for the motor
  digitalWrite(in1, LOW);
}

void loop() {
  
  int potValue = analogRead(A0);// <- This should be changed accordingly
  int pwmOutput = map(potValue, 0, 1023, -255, 255);
  
  if(abs(pwmOutput) < 20) {
    pwmOutput = 0;
  }
  
  analogWrite(enA, abs(pwmOutput));
  
  if(pwmOutput < 0){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  delay(20);
}
