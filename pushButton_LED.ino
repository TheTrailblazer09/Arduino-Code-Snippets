void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(4,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(4)){
  digitalWrite(2,HIGH);
  delay(1000);
  }
  else{
  digitalWrite(2,LOW);
  delay(1000);
  }

}
