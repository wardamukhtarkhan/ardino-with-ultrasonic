int echoPin = 2;
int trigPin = 3;
int blueLed = 4;
int greenLed = 5;

float duration;
float distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop()
{
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delay(100);
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin,LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2;
  
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance <= 100)
  {  
   digitalWrite( blueLed, HIGH);
   delay(100);
   digitalWrite( greenLed , LOW);
   delay(100);
  }
  else if (distance >= 200)
  {
   digitalWrite( greenLed, HIGH);
   delay(100);
   digitalWrite(blueLed, LOW);
   delay(100);
  }  
  else
  {
    digitalWrite(blueLed, LOW );
    digitalWrite(greenLed, LOW);
  }
}