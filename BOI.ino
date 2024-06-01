int trig = 9;
int echo = 10;
int feedback = 11;
long time;
int distance;
int range = 8;
int buzz = 7;
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(feedback, OUTPUT);
  pinMode(buzz,OUTPUT);
}
void loop() {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    time = pulseIn(echo, HIGH);
    distance = time * 0.034 / 2;
    Serial.print("Distance is ");
    Serial.println(distance);
    if (distance < 100 && distance>30) 
    {
      analogWrite(feedback, 222);
      delay(distance*2);
      analogWrite(feedback, 0);
      delay(distance*2);
    }
    else if(distance<30)
    {
      digitalWrite(buzz,HIGH);
      delay(100);
      digitalWrite(buzz,LOW);
      delay(100);
    }
 }
