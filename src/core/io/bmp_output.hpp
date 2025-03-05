#include <fstream>
#include <iostream>
#include <string>
#include "utils/rgb_pixel.hpp"

using namespace std;

class bmp_output : private ofstream
{
public:
	bmp_output (string outfile, unsigned int Height, unsigned int Width);

	~bmp_output ()
	{
		close ();
	};

	void close()
	{
		ofstream::close ();
	}

	bool eof () const
	{
		return (ofstream::eof());
	}

	bool operator!() const
	{
		return ofstream::fail();
	}
	
	bool write (rgbpixel *p, streamsize NumberOfPixels);
	
	unsigned int GetWidth() {
		return ImageWidth;
	}
	unsigned int GetHeight() {
		return ImageHeight;
	}
private:
	unsigned int ImageWidth;
	unsigned int ImageHeight;	
	unsigned char BytePadding;
	unsigned int nWritten;
};
