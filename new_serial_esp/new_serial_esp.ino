#define num_bytes 100

int incomingByte = 0;
int count = 0;
int printed = 0;


char dataReceived[num_bytes];

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()>0){
    printed = 0;
    incomingByte = Serial.read();
    dataReceived[count] = char(incomingByte);

    count++;
  }
  if (printed == 0){
    for(int i = 0;i < 10; i++){
      Serial.print(dataReceived[i]);
    }
    count = 0;
    printed = 1;
  }
}
