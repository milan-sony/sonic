// reference links
// https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1

// Defining pin numbers
const int trigPin = 5;
const int echoPin = 2;

// Defining variables
long duration;
int distance;

void setup() {
  // Setting trigPin as an OUTPUT
  pinMode(trigPin, OUTPUT);
  // Setting the echoPin as an INPUT
  pinMode(echoPin, INPUT);
  // starting the serial communication
  Serial.begin(9600);
}

void loop() {
  // Clears the trigPin, setting the trigPin to LOW for 2 µs
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Setting the trigPin to HIGH for 10 micro seconds - 10 µs
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Using the pulseIn() function we can read the travel time and put that value into the variable duration. 
  // This function has 2 parameters, the first one is the name of the Echo pin and for the second is the state of the pulse we are reading, either High or Low.
  duration = pulseIn(echoPin, HIGH);
  // This returns the sound wave travel time in microseconds

  // Calculating the distance in cm
  distance = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("CM");
  Serial.println("");
}
