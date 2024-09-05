int S=0;

void setup()
{
  Serial.begin(9600);
  pinMode(12,INPUT);
}

void loop()
{
  S=digitalRead(12);
  Serial.println(S);
}
