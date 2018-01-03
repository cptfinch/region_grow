#include <iostream>
#include <string>
#include <fstream>



using namespace std;

class oBMPstream : private ofstream
{
public:
	oBMPstream (string outfile, unsigned int Height, unsigned int Width);

	~oBMPstream ()
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
	//streamsize NumberOfPixels = ImageWidth * ImageHeight;

	unsigned char BytePadding;
	
	unsigned int nWritten;
};


