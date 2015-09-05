# raspberrypi-project
Raspberry pi project to create a rover

## Compile and run
On the Raspberry Pi, the g++ version is 4.6 and doesn't support -std=c++11. That is why we use g++-4.7.

To install run
    sudo apt-get install g++-4.7
    
To compile run
    g++-4.7 -std=c++11 file.cpp -lwiringPi

## Captain's log

5 sep 2015
* [Raspberry Pi][1] running [Raspbian][2] OS
* Installed [Wiring Pi][3]
* First LED functionality added

[1]: https://www.raspberrypi.org/
[2]: https://www.raspberrypi.org/downloads/raspbian/
[3]: http://wiringpi.com/
