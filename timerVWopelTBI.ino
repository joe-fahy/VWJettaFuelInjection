int delArr[] = {6,10,15,20,25,30};//delArr
unsigned long injTimer = millis();
int del = 5;
int tps = 0;
int pointsDel = 100;
unsigned long pulse = 0;
unsigned long prev = millis();
int rpm = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT);

  attachInterrupt(digitalPinToInterrupt(2),injectPulse,RISING);
  Serial.begin(9600);

  Serial.println("VW Timer prog starting....");


  int i = 0;

  while(i<8){
    
  digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);

    delay(100);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
    delay(100);

    i++;

    
    }//while


  //init inj and led pins as low.
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);

  

  

}

void loop() {
  // put your main code here, to run repeatedly:

  //Serial.println(tps);

  if((millis()-injTimer) >= del){

    //Turn off injector.
    digitalWrite(12,LOW);
        digitalWrite(12,LOW);

    
    
    }//if

}//loop()


void injectPulse(){


  pulse = millis()-prev;
  prev = millis();
  rpm = (60000/pulse)*2;

if(rpm >900 && rpm <7000){

Serial.println("Hi!!!!!");
Serial.println(analogRead(7));
  
  //Get a tps val.

  if(analogRead(7)== 0){tps = 0;}else{
  tps = (analogRead(7)-114)/70;
  }//else
  Serial.print("TPS = ");
  Serial.println(tps);

  //Set the inj delay.
  del = delArr[tps];

  //Set led for error checking.
  digitalWrite(13,HIGH);

  //Reset the timer.
  injTimer = millis();

}//if
  
  }//injectPulse()
