#!/bin/sh
g++ main.cpp -lssl -lcrypto -Wall -lboost_system -pthread -o dokucoin
./dokucoin