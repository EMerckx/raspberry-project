# raspberrypi-project
Raspberry pi project to create a rover. The rover's name is Wanderlust.

## Compile and run
On the Raspberry Pi, the g++ version is 4.6 and doesn't support -std=c++11. That is why we use g++-4.7.

The install command

    sudo apt-get install g++-4.7
    
The compile command

    g++-4.7 -std=c++11 file.cpp -lwiringPi

## Captain's log

5 sep 2015
* [Raspberry Pi][1] running [Raspbian][2] OS
* Installed [Wiring Pi][3]
* First LED functionality added

6 sep 2015
* First attempt to control a stepper motor
* Controlling a 6V motor
* Configuring WiFi adapter, connects on boot (finally)

7 sep 2015
* Built the rover (first design)
* Coded the first test ride
* Runned the first test ride (successful)
* Named the rover Wanderlust
* Added basic OO classes for the motors

8 sep 2015
* Rebuilt the rover (second design)

[1]: https://www.raspberrypi.org/
[2]: https://www.raspberrypi.org/downloads/raspbian/
[3]: http://wiringpi.com/
