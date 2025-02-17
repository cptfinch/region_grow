#include <iostream>
#include <string>
#include <fstream>
//#include "rgbpixel.h"
using namespace std;

class iPNMstream : private ifstream
{
public:
	iPNMstream (string infile);

	~iPNMstream ()
	{
		ifstream::close ();
	};

	void close()
	{
		ifstream::close ();
	}

	bool eof () const
	{
		return (ifstream::eof());
	}

	bool operator!() const
	{
		return ifstream::fail();
	}
	
	bool read (rgbpixel *p, streamsize NumberOfPixels);
	
	int GetNumberOfPixels() {
		return NumberOfPixels;
	}
	int GetWidth() {
		return Width;
	}
	int GetHeight() {
		return Height;
	}
private:
	int Width;
	int Height;	
	streamsize NumberOfPixels;
	
};


