
int S1=2;
int S2=15;
int S3=14;
int S4=16;
int S5=10;
int MI1=3;
int MI2=5;
int MD1=6;
int MD2=9;
int LED=7;
int ARR=8;

int LS1;
int LS2;
int LS3;
int LS4;
int LS5;
int A;

void setup() {
  pinMode(S1,INPUT);
  pinMode(S2,INPUT);
  pinMode(S3,INPUT); 
  pinMode(S4,INPUT);
  pinMode(S5,INPUT); 
  pinMode(MI1,OUTPUT);//IN1
  pinMode(MI2,OUTPUT);//IN2
  pinMode(MD1,OUTPUT);//IN1
  pinMode(MD2,OUTPUT);//IN2
  pinMode(LED,OUTPUT);//LED
  pinMode(ARR,OUTPUT);//arrancador
}

void loop() {
  LS1=digitalRead(S1);
  LS2=digitalRead(S2);
  LS3=digitalRead(S3);
  LS4=digitalRead(S4);
  LS5=digitalRead(S5);
  A=digitalRead(ARR);

    if(LS1==0 && LS2==1 && LS3==1 && LS4==1 && LS5==0)
    {
      digitalWrite(MI1,HIGH);
      digitalWrite(MI2,LOW);
      digitalWrite(MD1,HIGH);
      digitalWrite(MD2,LOW);
    }
    else if(LS1==1 && LS2==0 && LS3==0 && LS4==0 && LS5==0)
    {
      digitalWrite(MI1,LOW);
      digitalWrite(MI2,LOW);
      digitalWrite(MD1,HIGH);
      digitalWrite(MD2,LOW);
    }
    else if(LS1==0 && LS2==1 && LS3==1 && LS4==0 && LS5==0)
    {
      digitalWrite(MI1,LOW);
      digitalWrite(MI2,LOW);
      digitalWrite(MD1,HIGH);
      digitalWrite(MD2,LOW);
    }
    else if(LS1==0 && LS2==0 && LS3==0 && LS4==0 && LS5==1)
    {
      digitalWrite(MI1,HIGH);
      digitalWrite(MI2,LOW);
      digitalWrite(MD1,LOW);
      digitalWrite(MD2,LOW);
    }
    else if(LS1==0 && LS2==0 && LS3==1 && LS4==1 && LS5==0)
    {
      digitalWrite(MI1,HIGH);
      digitalWrite(MI2,LOW);
      digitalWrite(MD1,LOW);
      digitalWrite(MD2,LOW);
    }
    else if(LS1==0 && LS2==0 && LS3==0 && LS4==0 && LS5==0)
    {
      digitalWrite(MI1,HIGH);
      digitalWrite(MI2,LOW);
      digitalWrite(MD1,LOW);
      digitalWrite(MD2,LOW);
    }
  
  
}
