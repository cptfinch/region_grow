GPP = c:/mingw/bin/g++
LD = c:/mingw/bin/g++

CFLAGS = -c -Wall -mwindows -mconsole
LDFLAGS = -Wall -mwindows -mconsole -s

all : iPNMstream.exe

iPNMstream.exe : iPNMstream.o
	$(LD) $(LDFLAGS) -o $@ $^

iPNMstream.o : iPNMstream.cpp
	$(GPP) $(CFLAGS) -o $@ $^

clean:
	del iPNMstream.o
	del iPNMstream.exe