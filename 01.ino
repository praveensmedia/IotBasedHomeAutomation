#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "1fd20540afcf436182836089654370ce";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "hmm";
char pass[] = "321321321";

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
   
float vout = analogRead(A0);
vout=(vout*500)/1023;
vout=vout/2;
Blynk.virtualWrite(V0,vout);
}

void setup()
{
  // Debug console
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  pinMode(A0,INPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  // Setup a function to be called every second
  timer.setInterval(1200L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
 
}
BLYNK_WRITE(D2){
  int pinValue = param.asInt();                    // assigning incoming value from pin V1 to a variable
  digitalWrite(2,pinValue);           
 
}
BLYNK_WRITE(D3){
  int pinValue1 = param.asInt();                    // assigning incoming value from pin V1 to a variable
  digitalWrite(3,pinValue1);           
 
}
