//LECTURA
int S1;
int S2;
int S3;
int S4;
int S5;
int G;
int R;

//CONTROL
int SS1 = A4;
int SS2 = A3;
int SS3 = A2;
int SS4 = A1;
int SS5 = A0;                     
int M1I = 10;
int M1D = 9;
int M2I = 6;
int M2D = 5;
int RDY = 2;
int GO = 3;

void setup() 
{
  Serial.begin(9600);     // inicializa comunicacion serie a 9600 bps
  pinMode(SS1,INPUT);
  pinMode(SS2,INPUT);
  pinMode(SS3,INPUT);
  pinMode(SS4,INPUT);
  pinMode(SS5,INPUT);
  pinMode(RDY,INPUT);
  pinMode(GO,INPUT);
  pinMode(M1I,OUTPUT);
  pinMode(M1D,OUTPUT);
  pinMode(M2I,OUTPUT);
  pinMode(M2D,OUTPUT);
} 

void loop() 
{
  G=digitalRead(GO);
  R=digitalRead(RDY);
  if(G==1)
  {
    S1=digitalRead(SS1);
    S2=digitalRead(SS2);
    S3=digitalRead(SS3);
    S4=digitalRead(SS4);
    S5=digitalRead(SS5);
    /*Serial.print(S1);
    Serial.print(";");
    Serial.print(S2);
    Serial.print(";");
    Serial.print(S3);
    Serial.print(";");
    Serial.print(S4);
    Serial.print(";");
    Serial.println(S5);
    delay(500);*/
    if(S1==0 && S2==1 && S3==1 && S4==1 && S5==0)
    {//FRENTE
        analogWrite(M1I,255);
        analogWrite(M1D,0);
        analogWrite(M2I,0);
        analogWrite(M2D,255);
    }
    else if(S1==0 && S2==1 && S3==1 && S4==0 && S5==0)
    {//BUSQUEDA IZQ
        analogWrite(M1I,100);
        analogWrite(M1D,0);
        analogWrite(M2I,0);
        analogWrite(M2D,0);
    }
    else if(S1==1 && S2==0 && S3==0 && S4==0 && S5==0)
    {//BUSQUEDA IZQ
        analogWrite(M1I,100);
        analogWrite(M1D,0);
        analogWrite(M2I,0);
        analogWrite(M2D,0);
    }
    else if(S1==0 && S2==0 && S3==0 && S4==0 && S5==1)
    {//BUSQUEDA DER
        analogWrite(M1I,0);
        analogWrite(M1D,0);
        analogWrite(M2I,0);
        analogWrite(M2D,100);
    }
    else if(S1==0 && S2==0 && S3==1 && S4==1 && S5==0)
      {//BUSQUEDA DER
        analogWrite(M1I,0);
        analogWrite(M1D,0);
        analogWrite(M2I,0);
        analogWrite(M2D,100);
    }  
    else if(S1==0 && S2==0 && S3==0 && S4==0 && S5==0)
    {//BUSQUEDA 
        analogWrite(M1I,60);
        analogWrite(M1D,0);
        analogWrite(M2I,60);
        analogWrite(M2D,0);
    }
    }
    else if(G==0)
    {
      analogWrite(M1I,0);
      analogWrite(M1D,0);
      analogWrite(M2I,0);
      analogWrite(M2D,0);
    }
}
