//Init global variables
int tps = 0;
int rpm = 0;
unsigned long injTimer = 6;

unsigned long prev = millis();
unsigned long pulse = 0;

int delMap[] = {6,10,15,18,21,22,12,15,18,22,25,30};



void setup() {
  
//pin to trigger injector.  
pinMode(12,OUTPUT);

//Pulse in from negative side of coil.
attachInterrupt(digitalPinToInterrupt(2),injectPulse,RISING);

//Serial line.
Serial.begin(9600);

int i = 0;
while(i<10){
digitalWrite(12,HIGH);
delay(100);
digitalWrite(12,LOW);
delay(50);
i++;
}//while

}//setup()

void loop() {

//The ISR updates global variables, so loop just prints those to the screen.
if(injTimer){}//if



}//loop()


void injectPulse(){
  
  pulse = millis()-prev;
  prev = millis();
  rpm = (60000/pulse)*2;

if(rpm>100 && rpm<7000){
      tps = (analogRead(7)-114)/70;

//Update a timer here.....NO DELAYS!!!!!
      digitalWrite(12,HIGH);
      delay(delMap[tps]);
      

      Serial.print("rpm = ");
Serial.print(rpm);
Serial.print("  tps = ");
Serial.print(tps);
Serial.print("  inj = ");
Serial.print(delMap[tps]);
Serial.print("  pulseWidth = ");
Serial.println(pulse);
      
  
  }//if

  
  }//injectPulse()
