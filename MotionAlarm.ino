
const int trigPin = 11;           //connects to the trigger pin on the distance sensor
const int echoPin = 12;           //connects to the echo pin on the distance sensor
const int ledPin = 13;            
const int speakerPin = 10;
const int buttonPin = 8;

float distance = 0;               //stores the distance measured by the distance sensor
float setDist;                    //stores the calibrated distance
float threshold = 0.10;

void setup()
{
  Serial.begin(9600);        //set up a serial connection with the computer

  pinMode(trigPin, OUTPUT);   //the trigger pin will output pulses of electricity
  pinMode(echoPin, INPUT);    //the echo pin will measure the duration of pulses coming back from the distance sensor
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  setDist = getDistance();
}

void loop() {
  //get distance and determine if it exceeds threshold value
  distance = getDistance();
  //if it exceeds, trigger the alarm/light
  if (distanceThreshold(setDist, distance)) {
    digitalWrite(ledPin, HIGH);
    tone(speakerPin, 1000);
  }
  //if the button is pressed, disable the alarm/light and set the new distance
  if (digitalRead(buttonPin) == LOW) {
    digitalWrite(ledPin, LOW);
    noTone(speakerPin);
    setDist = getDistance();
  }
  delay(100);
}

//------------------FUNCTIONS-------------------------------

//RETURNS THE DISTANCE MEASURED BY THE HC-SR04 DISTANCE SENSOR
float getDistance()
{
  float echoTime;                   //variable to store the time it takes for a ping to bounce off an object
  float calculatedDistance;         //variable to store the distance calculated from the echo time

  //send out an ultrasonic pulse that's 10ms long
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);      //use the pulsein command to see how long it takes for the
  //pulse to bounce back to the sensor

  calculatedDistance = echoTime / 148.0;  //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)

  return calculatedDistance;              //send back the distance that was calculated
}

//DETERMINES IF DISTANCE MEASURED EXCEEDS THRESHOLD VALUE
bool distanceThreshold(float set, float measured)
{
  return (abs((measured - set) / set) > threshold); //determines if the change exceeds the threshold
}
