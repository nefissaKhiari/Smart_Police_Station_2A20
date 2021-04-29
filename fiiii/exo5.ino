#include<Servo.h>
int led_rouge=13,led_verte=12, mvt=0;
int trigo=5,echo=3;
long distance_cm,temp;


void distance(){
  digitalWrite(trigo,LOW);
  delayMicroseconds(2);
  digitalWrite(trigo,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigo,LOW);
  temp=pulseIn(echo,HIGH); //pulseIn compteur qui compte l temps suite a l'mission du sign au niv trigo
  distance_cm=temp*0.034/2;// 0.034=celerité 
    Serial.println(distance_cm);
}



void setup() {
  
   pinMode(led_rouge,OUTPUT);
   pinMode(led_verte,OUTPUT); 
   pinMode(trigo,OUTPUT); 
   pinMode(echo,INPUT); 
     Serial.begin(9600);
 // myservo.attach(11);//le pin sur laquelle on va attacher 
}

void loop() {

 myservo.write(0); //angle du servo
 digitalWrite(led_rouge,HIGH);
 digitalWrite(led_verte,LOW);
 delay(3000); //attendre le servo pour qu'+il arrive
 myservo.write(90); //angle du servo
  digitalWrite(led_rouge,LOW);
 digitalWrite(led_verte,HIGH);
 delay(3000);
  distance();  // distance_cm=12
  if ( distance_cm<10)
{  myservo.write(90);
   digitalWrite(led_rouge,LOW);
 digitalWrite(led_verte,HIGH);}
 else 
 {myservo.write(0);
  digitalWrite(led_rouge,HIGH);
 digitalWrite(led_verte,LOW);
 }
}
