void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,INPUT);
  Serial.begin(9600);

}

void loop() {
  Serial.println(analogRead(A0));

  delay(50);
}
