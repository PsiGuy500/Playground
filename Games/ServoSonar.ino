
//The setup of this code is based upon the given arduino scripts as well as UBC APSC 101 Code

#define VCC_PIN 13
#define TRIGGER_PIN 12    // sonar trigger pin will be attached to Arduino pin 12
#define ECHO_PIN 11       // sonar echo pint will be attached to Arduino pin 11
#define GROUND_PIN 10     //
#define MAX_DISTANCE 200  // maximum distance set to 200 cm
#include <Servo.h>

// twelve servo objects can be created on most boards

int pos = 0;
int count = 0;    
// defines variables
long duration;
int distance;
Servo myservo;  // create servo object to control a servo

void setup() {
  Serial. begin(9600);            // set data transmission rate to communicate with computer
  pinMode(ECHO_PIN, INPUT) ;  
  pinMode(TRIGGER_PIN, OUTPUT) ;
  pinMode(GROUND_PIN, OUTPUT);    // tell pin 10 it is going to be an output
  pinMode(VCC_PIN, OUTPUT);       // tell pin 13 it is going to be an output
  digitalWrite(GROUND_PIN,LOW);   // tell pin 10 to output LOW (OV, or ground)
  digitalWrite(VCC_PIN, HIGH) ;   // tell pin 13 to output HIGH (+5V)
  myservo.attach(9);
}

void loop() {
  digitalWrite(TRIGGER_PIN, LOW);   // Clears the trigPin
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);  // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(20);
  digitalWrite(TRIGGER_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance= duration*0.034/2;       // Calculating the distance

  // if the distance measurement becomes extremely high, it is likely an error.  
  // Default to a maximum value of MAX_DISTANCE to identify this condition.
  
  if (distance > MAX_DISTANCE)   
    {distance = MAX_DISTANCE ;}
  
  if(distance < 15){
    myservo.write(0);
    delay(2000);
  }
  myservo.write(180);
  delay(2000);
    
  Serial.print("Distance: ") ;      // Prints the distance on the Serial Monitor
  Serial.println(distance);
}
