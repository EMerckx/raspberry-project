#include <iostream>
#include <wiringPi.h>

using std::cout;
using std::endl;

// amount of steps is a product of 4
const int STEPS = 4;
const int DELAY = 1000;

// pin name = pin number
const int IN1 = 0;
const int IN2 = 1;
const int IN3 = 2;
const int IN4 = 3;

void initPins(){
  // pins for lines
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void setStep(const int in1, const int in2,const int in3, const int in4){
  cout << "pin1=" << in1 << " pin2=" << in2 << " pin3=" << in3 << " pin4=" << in4 << endl;
  digitalWrite(IN1, in1);
  digitalWrite(IN2, in2);
  digitalWrite(IN3, in3);
  digitalWrite(IN4, in4);
}

void pauze(const int time){
  setStep(LOW,LOW,LOW,LOW);
  delay(time);
}

void turnOff(){
  setStep(LOW,LOW,LOW,LOW);
}

int main(){
  wiringPiSetup();

  initPins();

  turnOff();
  
  pauze(3* DELAY);

  
  for(int i=0; i<STEPS; i+=4){
    
    cout << "Step " << i + 1 << endl;
    setStep(HIGH, LOW, HIGH, LOW);
    delay(DELAY);
    pauze(500);
    
    cout << "Step " << i + 2 << endl;
    setStep(LOW, HIGH, LOW, HIGH);
    delay(DELAY);
    pauze(500);

    cout << "Step " << i + 3 << endl;
    setStep(HIGH, LOW, LOW, HIGH);
    delay(DELAY);
    pauze(500);

    cout << "Step " << i + 4 << endl;
    setStep(LOW, HIGH, HIGH, LOW);
    delay(DELAY);
    pauze(500);
  }

  turnOff();

  return 0;
}
