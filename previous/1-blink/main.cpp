#include <iostream>
#include <wiringPi.h>

using std::cout;
using std::endl;

int main() {
    wiringPiSetup();
    pinMode(0, OUTPUT);
    for (int i = 0; i < 100; i++) {
        digitalWrite(0, HIGH);
        cout << "LED on" << endl;
        delay(500);
        digitalWrite(0, LOW);
        cout << "LED off" << endl;
        delay(500);
    }

    return 0;
}
