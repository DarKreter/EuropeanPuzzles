#include <Servo.h>

#define PLAIN_PIN 7
#define FIRST_ROW_PIN 2
#define SECOND_ROW_PIN 3
#define THIRD_ROW_PIN 4
#define FOURTH_ROW_PIN 5

const short lpop = 25, rpop = 155, mpop = (lpop + rpop) / 2; //LeftPositionOfPlain

Servo plain;

void Fly(const int smallPause = 9, const int bigPause = 500)
{  
  digitalWrite(FIRST_ROW_PIN, LOW);
  digitalWrite(SECOND_ROW_PIN, LOW);
  digitalWrite(THIRD_ROW_PIN, LOW);
  digitalWrite(FOURTH_ROW_PIN, LOW);
  digitalWrite(FIRST_ROW_PIN, HIGH);
  for(int i = mpop;i<rpop;i++)
  {
    plain.write(i);
    delay(smallPause);
  }
  delay(bigPause);
  //digitalWrite(FIRST_ROW_PIN, LOW);
  digitalWrite(SECOND_ROW_PIN, HIGH);
  for(int i = rpop;i>mpop;i--)
  {
    plain.write(i);
    delay(smallPause);
  }
  delay(bigPause);
  //digitalWrite(SECOND_ROW_PIN, LOW);
  digitalWrite(THIRD_ROW_PIN, HIGH);
  for(int i = mpop;i>lpop;i--)
  {
    plain.write(i);
    delay(smallPause);
  }
  delay(bigPause);
  //digitalWrite(THIRD_ROW_PIN, LOW);
  digitalWrite(FOURTH_ROW_PIN, HIGH);
  for(int i = lpop;i<mpop;i++)
  {
    plain.write(i);
    delay(smallPause);
  }
  delay(bigPause);
}

void setup() {
  plain.attach(PLAIN_PIN);
  plain.write(mpop);
  pinMode(FIRST_ROW_PIN, OUTPUT);
  pinMode(SECOND_ROW_PIN, OUTPUT);
  pinMode(THIRD_ROW_PIN, OUTPUT);
  pinMode(FOURTH_ROW_PIN, OUTPUT);

  digitalWrite(FIRST_ROW_PIN, LOW);
  digitalWrite(SECOND_ROW_PIN, LOW);
  digitalWrite(THIRD_ROW_PIN, LOW);
  digitalWrite(FOURTH_ROW_PIN, LOW);
}

void loop() {
  Fly();
}
