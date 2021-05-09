#include <Servo.h>

int dht_pin =A0;
int motor_pin = A1;
int ldr_pin = A2;

Servo servo_pin;

float LDR;
int sensor;
double sicaklik;
float deger;

void setup() {
  
  pinMode(dht_pin,INPUT);
  pinMode(ldr_pin,INPUT);
  pinMode(motor_pin,OUTPUT);
  
 
  Serial.begin(9600);
  servo_pin.attach(9);
}
void loop() {
  
  sensor =analogRead(dht_pin);
  
  LDR = analogRead(ldr_pin);
  
  sicaklik = (double)sensor/ 1024;       
  sicaklik = sicaklik * 5;                 
  sicaklik = sicaklik - 0.5;               
  sicaklik = sicaklik * 100;
  
  if(sicaklik<25)
  {
    Fan_dur();
    Serial.println("----------------------");
    Serial.println("FAN DURUMU: DEAKTIF ---");
    Serial.print("-------------------------");
  	
  
  	
  }
  else if(sicaklik>=25)
  {
    Fan_calis();
    Serial.println("----------------------");
    Serial.println("FAN DURUMU: AKTIF ---");
    Serial.print("-------------------------");
 
  }
  
  if (LDR <100){
      Servo_aktif();
      //Serial.println("LDR DURUMU: ");
      //Serial.print(LDR);
  }
  else if (LDR>100){
      Servo_deaktif();
      //Serial.println("LDR DURUMU: ");
      //Serial.print(LDR);
  }
  
  delay(1000);
}
void Fan_calis(){
  analogWrite(motor_pin, 1023);
}
void Fan_dur(){
  analogWrite(motor_pin,0);
}
  
void Servo_aktif(){
	servo_pin.write(0);
}


void Servo_deaktif(){
    for(int i=0;i<=180;i++)
    {     
      servo_pin.write(i);
    }
}
