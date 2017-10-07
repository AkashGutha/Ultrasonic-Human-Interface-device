// custom defines for trigger pin and other pins
#define TRIGGER_PIN 11
#define ECHO_INPUT_PIN 10
#define SPEED_OF_SOUND_MTRS_BY_MICROSEONDS 340/1000000

//variable to store time adn distance
unsigned long time = 0;
unsigned long distance = 0;

// this is used to setup your hardware and inittilaze varibales
void setup(){
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_INPUT_PIN, INPUT);

  Serial.begin(115200);
}

// this function will run again and again for the rest of the application lifetime
void loop(){

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  time = pulseIn(ECHO_INPUT_PIN, HIGH, 28);
  distance = (time * SPEED_OF_SOUND_MTRS_BY_MICROSEONDS);

  Serial.println("Distance from the obstacle is : " );
  Serial.print(distance)
  Serial.println(" meters");

  delay(1000);
}
