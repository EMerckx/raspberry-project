#include <iostream>

#include "port.h"

using std::cout;
using std::endl;

int main() {
    cout << "Hello World!" << endl; 
    
    cout << "Creating output port." << endl; 

    Port<OUTPUT> p(25, 1);

    cout << "Printing output port." << endl;

    cout << p << endl;

    cout << "Setting port to state zero." << endl;

    p.set_state(0);

    cout << "Printing output port." << endl;

    cout << p << endl;

    return 0;

}
