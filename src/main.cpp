#include <iostream>

#include "port.h"

using std::cout;
using std::endl;

// pin name = pin number
const int ENA = 5;
const int ENB = 6;
const int IN1 = 0;
const int IN2 = 1;
const int IN3 = 2;
const int IN4 = 3;

const unsigned int BIT_HIGH = 1;
const unsigned int BIT_LOW = 0;

Port<OUTPUT> ena;
Port<OUTPUT> enb;


void init() {
  // pins ENA and ENB to state high
  ena = Port<OUTPUT>(ENA, BIT_HIGH);
  enb = Port<OUTPUT>(ENB, BIT_HIGH);
}

void stop() {
  // pins ENA and ENB to state high
  ena.state(BIT_LOW);
  enb.state(BIT_LOW);
}

int main() {
    cout << "Hello World!" << endl; 

    init();

    cout << ena << endl << enb << endl;

    delay(3000);

    /**********/

    cout << "Creating output port." << endl; 

    Port<OUTPUT> p(IN1, BIT_HIGH);

    cout << "Printing output port." << endl;

    cout << p << endl;

    delay(3000);

    cout << "Setting port to state zero." << endl;

    p.set_state(0);

    cout << "Printing output port." << endl;

    cout << p << endl;

    /**********/

    delay(3000);

    stop();

    cout << ena << endl << enb << endl;

    return 0;

}
