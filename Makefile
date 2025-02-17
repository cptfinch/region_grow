GPP = c:/mingw/bin/g++
LD = c:/mingw/bin/g++

CFLAGS = -c -Wall -mwindows -mconsole
LDFLAGS = -Wall -mwindows -mconsole -s

all : blobcounter.exe

blobcounter.exe : blobcounter.o BinaryImage.o iBMPstream.o rgbpixel.o blob.o
	$(LD) $(LDFLAGS) -o $@ $^

blobcounter.o : blobcounter.cpp
	$(GPP) $(CFLAGS) -o $@ $^

iBMPstream.o : iBMPstream.cpp
	$(GPP) $(CFLAGS) -o $@ $^

rgbpixel.o : rgbpixel.cpp
	$(GPP) $(CFLAGS) -o $@ $^

BinaryImage.o : BinaryImage.cpp
	$(GPP) $(CFLAGS) -o $@ $^

blob.o : blob.cpp
	$(GPP) $(CFLAGS) -o $@ $^

clean:
	del blobcounter.o
	del blobcounter.exe
	del iBMPsteam.o
	del BinaryImage.o
	del rgbpixel.o
	del blob.o

