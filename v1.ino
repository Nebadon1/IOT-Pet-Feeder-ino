#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo1;
#define SERVO1 5


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "AUTH TOKEN";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SSID";
char pass[] = "PASSWORD";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  servo1.attach(SERVO1);
}

void loop()
{

  Blynk.run();
}

BLYNK_WRITE(V1) { //Button Widget is writing to pin V1

  int pinData = param.asInt();

  //Blynk.notify("Hey! I just fed your cat!");
  Blynk.email("EMAIL ADDRESS", "Cat Feeder", "Hey, your pet feeder here! I just fed your cat!");


  servo1.write(180); //85 is more like a speed instead of an angle.
  delay(1);
  servo1.write(90); //Stop
}

/********************************
   0 = Max clockwise
   90 = Stop
   180 = Max counter clockwise
 * ******************************/
