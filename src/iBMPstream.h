/*-----------------------------------------------------------------------------	
DESCRIPTION:
============
A file stream reader class for BMP binary files.  This inherits from ifstream, but only exposes certain methods, so that a user of the class can only call methods that result in an uncompressed stream.

BMP files are image files that begin with a file/image header, colour palette, and image data.  Each row is padded to a 4-byte boundary.  Binary format consists of 1 bit per pixel which results in two colours for values 0 and 1 (as defined by the colour palette).  For example, 0 is usually mapped to white and 1 to black.  In the constructor, the colour map is defined as rgbpixel types.

The read() method of this class returns the next pixel(s) of an inflated stream.  To a user of this class, the source file is read as a stream of uncompressed rgb pixel values.

HISTORY:
========
19.04.2005 CPT Finch. Created.
-----------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
//#include "rgbpixel.h"
using namespace std;

class iBMPstream : private ifstream
{
public:
	iBMPstream (string infile);

	~iBMPstream ()
	{
	  delete[] colourMap;
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

	rgbpixel getColourAt(int colourIndex)
	{
	  return colourMap[colourIndex];
	}

private:
	int Width;
	int Height;	
	streamsize NumberOfPixels;
	unsigned int startOfImage;

	rgbpixel* colourMap;
	unsigned char BytePaddingPerRow;
	unsigned int ActualBytesPerRow;
	unsigned int BytesPerRow;
	
	int nRead;
	int numberOfRowsRead;

	queue<rgbpixel>	pixq;

	bool inflate ();
	
};

