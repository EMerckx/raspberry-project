CXX=g++-4.7
OPT=-std=c++11 -pedantic -c
WIR=-lwiringPi

abstractport.o: abstractport.cpp abstractport.h
    $(CXX) $(OPT) abstractport.cpp