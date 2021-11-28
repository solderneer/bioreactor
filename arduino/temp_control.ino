

int control_temp(int temp)
{
  if(temp<512){
    digitalWrite(13,HIGH);
  }
  else {
    digitalWrite(13,LOW);
  }
  
}

int control_pH(float pH)
{
  if(pH<219.43 || pH>512)
  {
    digitalWrite(12,HIGH);
  }
  else 
    digitalWrite(12,LOW);
}
  

void setup() {
  pinMode(13,OUTPUT);
  pinMode(A1,INPUT) ;
  pinMode(A0,INPUT) ;
}

void loop() {
  int temp= analogRead(A1);
  control_temp(temp);
  float pH= analogRead(A0);
  control_pH(pH);
 
}
