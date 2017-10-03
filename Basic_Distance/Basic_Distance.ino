// custom defines for trigger pin and other pins
#define TRIGGER_PIN 12
#define ECHO_INPUT_PIN 10
#define SPEED_OF_SOUND_MTRS_BY_SEONDS 340

//variable to store time adn distance
int time = 0;
float distance = 0;

// this is used to setup your hardware and inittilaze varibales
void setup(){
  
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_INPUT_PIN, INPUT);

  Serial.begin(9600);

  delay(1000);

}

// this function will run again and again for the rest of the application lifetime
void loop(){

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  time = pulseIn(ECHO_INPUT_PIN, HIGH);
  distance = (time * SPEED_OF_SOUND_MTRS_BY_SEONDS)/ (1000000);

  Serial.println("Distance from the obstacle is : " + distance + " meters");
}