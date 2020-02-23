CC = g++

ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
 
CPPFLAGS= -std=c++17 -I$(ROOT_DIR)/include -fomit-frame-pointer -fPIC -DQHASM
LDFLAGS= -shared -L/usr/local/lib -lcrypto -lssl -lpthread

SOURCES = block.cpp proof.cpp  blockchain.cpp
HEADERS = $(shell echo include/*.hpp)
OBJECTS=$(SOURCES:.cpp=.o)

TARGET=libsaber.so

all: $(TARGET)

.PHONY : clean
clean:
	rm -f $(OBJECTS)  $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

install:
	mkdir -p /usr/local/include/saber
	cp $(HEADERS) /usr/local/include/saber
	cp libsaber.so /usr/local/lib
	