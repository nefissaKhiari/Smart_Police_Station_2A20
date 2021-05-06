#define PIN_LED1 12 //le numéro de la broche sur laquelle la lampe 2  est branchée
#define PIN_LED2 13 // Le numéro de la broche sur laquelle la lampe 1 
char data; 
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
  //Serial.println(distance_cm);
}

void setup() {

  pinMode(PIN_LED1,OUTPUT);
  analogWrite(PIN_LED1, LOW);
  pinMode(PIN_LED2,OUTPUT);
  digitalWrite(PIN_LED2,LOW);
  pinMode(trigo,OUTPUT); 
  pinMode(echo,INPUT);
  Serial.begin(9600); //Permet d'initialiser le moniteur série à 9600 bauds 
 
}



void loop() {
   distance();
   Serial.println(distance_cm);
    if ( distance_cm<10)
    {
      Serial.write('4');
      
    }
    else 
    {
      Serial.write('5');
    }
    
  
 if (Serial.available()){ 
   data=Serial.read();  
 
    if(data=='1') 
    {
      digitalWrite(PIN_LED2,HIGH);
       digitalWrite(PIN_LED1,LOW);
     // Serial.write('1'); //ON 
     }  
     else if (data=='0') 

     {   digitalWrite(PIN_LED1,HIGH);
        digitalWrite(PIN_LED2,LOW);
      //  Serial.write('0'); //OFF
     
     }   
    
   
 }}
