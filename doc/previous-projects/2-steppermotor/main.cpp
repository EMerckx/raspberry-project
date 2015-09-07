#include <iostream>
#include <wiringPi.h>

using std::cout;
using std::endl;

// amount of steps is a product of 4
const int STEPS = 12;
const int DELAY = 1000;

// pin name = pin number
const int ENA = 5;
const int ENB = 6;
const int IN1 = 0;
const int IN2 = 1;
const int IN3 = 2;
const int IN4 = 3;

void initPins(){
  // pins ENA and ENB
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);

  // pins for lines
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void setStep(const int in1, const int in2,const int in3, const int in4){
  digitalWrite(IN1, in1);
  digitalWrite(IN2, in2);
  digitalWrite(IN3, in3);
  digitalWrite(IN4, in4);
}

void turnOff(){
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);

  setStep(LOW,LOW,LOW,LOW);
}

int main(){
  wiringPiSetup();

  initPins();
  
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  
  for(int i=0; i<STEPS; i+=4){
    cout << "Step " << i + 1 << endl;
    setStep(HIGH, LOW, HIGH, LOW);
    delay(DELAY);
    cout << "Step " << i + 2 << endl;
    setStep(LOW, HIGH, HIGH, LOW);
    delay(DELAY);
    cout << "Step " << i + 3 << endl;
    setStep(LOW, HIGH, LOW, HIGH);
    delay(DELAY);
    cout << "Step " << i + 4 << endl;
    setStep(HIGH, LOW, LOW, HIGH);
    delay(DELAY);
  }

  turnOff();

  return 0;
}
