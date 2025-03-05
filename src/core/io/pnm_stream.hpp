#include <iostream>
#include <string>
#include <fstream>
#include "utils/rgb_pixel.hpp"
#include <queue>

using namespace std;

class pnm_stream : private ifstream
{
public:
	pnm_stream (string infile);

	~pnm_stream ()
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


