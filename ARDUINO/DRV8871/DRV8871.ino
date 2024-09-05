void setup() 
{
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);

}

void loop() 
{
  digitalWrite(5,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  delay(5000);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  delay(500);
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(6,HIGH);
  delay(5000);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  delay(500);
  

}
