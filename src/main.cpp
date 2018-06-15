#include <ctime>
#include <iostream>
#include <string>
#include <wiringPi.h>

using std::cout;
using std::endl;
using std::string;

// amount of steps is a product of 4
const int STEPS = 4;
const int DELAY = 1000;

// pin name = pin number
const int IN1 = 0;
const int IN2 = 1;
const int IN3 = 2;
const int IN4 = 3;

//********************************************************************************************

string getCurrentTime() {
  std::time_t result = std::time(nullptr);
  string str = std::asctime(std::localtime(&result));
  return str.substr(0, str.length() - 1);
}

string getLogPrefix() {
  string str;
  str.append(getCurrentTime());
  str.append(" - ");
  return str;
}

//********************************************************************************************

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


//********************************************************************************************

void leftWheelsForward() {
  setStep(HIGH, LOW, LOW, LOW);
}

void leftWheelsBackward() {
  setStep(LOW, HIGH, LOW, LOW);
}

void rightWheelsForward() {
  setStep(LOW, LOW, HIGH, LOW);
}

void rightWheelsBackward() {
  setStep(LOW, LOW, LOW, HIGH);
}


//********************************************************************************************

void goForward() {
  cout << getLogPrefix() << "Going forward." << endl;
  setStep(HIGH, LOW, HIGH, LOW);
}

void goBackward() {
  cout << getLogPrefix() << "Going backward." << endl;
  setStep(LOW, HIGH, LOW, HIGH);
}

void goLeft() {
  cout << getLogPrefix() << "Going left." << endl;
  setStep(LOW, HIGH, HIGH, LOW);
}

void goRight() {
  cout << getLogPrefix() << "Going right." << endl;
  setStep(HIGH, LOW, LOW, HIGH);
}

//********************************************************************************************

int main(){
  wiringPiSetup();

  initPins();

  turnOff();
  
  pauze(3 * DELAY);

  cout << "time: " << getCurrentTime() << endl;

  
  for(int i=0; i<STEPS; i+=4){

    cout << "Step " << i + 1 << endl;
    goForward();
    //delay(3 * DELAY);
    pauze(2000);

    cout << "Step " << i + 2 << endl;
    goBackward();
    //delay(3 * DELAY);
    pauze(2000);

    cout << "Step " << i + 3 << endl;
    goLeft();
    //delay(3 * DELAY);
    pauze(2000);

    cout << "Step " << i + 4 << endl;
    goRight();
    //delay(3 * DELAY);
    pauze(2000);
  }

  turnOff();

  return 0;
}
