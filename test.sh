#!/bin/sh
g++ main.cpp -lssl -lcrypto -Wall -lboost_system -pthread
./a.out