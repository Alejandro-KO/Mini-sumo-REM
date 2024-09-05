int S1;
int S2;
int S3;
int S4;
int S5;

void setup() {
  pinMode(2,INPUT);
  pinMode(13,INPUT);
  pinMode(12,INPUT); 
  pinMode(11,INPUT);
  pinMode(10,INPUT); 
  pinMode(3,OUTPUT);//IN1
  pinMode(5,OUTPUT);//IN2
  pinMode(6,OUTPUT);//IN1
  pinMode(9,OUTPUT);//IN2
  pinMode(7,OUTPUT);//LED
  pinMode(8,OUTPUT);//arrancador
  delay(3000);
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
  delay(500);
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
  delay(500);
}

void loop() {
  S1=analogRead(2);
  S2=analogRead(13);
  S3=analogRead(12);
  S4=analogRead(11);
  S5=analogRead(10);
  if(S1==0 && (S2==1 || S4==1) && S3==1 && S5==0)
  {
    analogWrite(3,255);
    analogWrite(5,0);
    analogWrite(6,255);
    analogWrite(9,0);
   }
   else if(S1==1 && S2==0 && S3==0 && S4==0 && S5==0)
  {
    analogWrite(3,0);
    analogWrite(5,0);
    analogWrite(6,255);
    analogWrite(9,0);
   }
   else if(S1==0 && S2==0 && S3==0 && S4==0 && S5==1)
  {
    analogWrite(3,255);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(9,0);
   }
   else if(S1==0 && S2==0 && S3==0 && S4==0 && S5==0)
  {
    analogWrite(3,0);
    analogWrite(5,0);
    analogWrite(6,255);
    analogWrite(9,0);
   }
   else if(S1==0 && S2==1 && S3==1 && S4==0 && S5==0)
  {
    analogWrite(3,0);
    analogWrite(5,0);
    analogWrite(6,255);
    analogWrite(9,0);
   }
   else if(S1==0 && S2==0 && S3==1 && S4==1 && S5==0)
  {
    analogWrite(3,255);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(9,0);
   }
}
