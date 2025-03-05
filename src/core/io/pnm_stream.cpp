#include "core/io/pnm_stream.hpp"
#include "utils/rgb_pixel.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

pnm_stream::pnm_stream (string infile)
	{
		
		ifstream::open (infile.c_str(), ios::in | ios::binary);
		 	    		
		char buf[1024];
		
		for (int i=0; i<2; i++) {
			ifstream::getline(buf,1024);
		cout << buf << endl;
		}
		
		ifstream::operator>>(Width);
		ifstream::operator>>(Height);

		NumberOfPixels = (Width)*(Height);

		ifstream::getline(buf,1024);
		cout << buf << endl;
		ifstream::getline(buf,1024);
		cout << buf << endl;

	}


bool pnm_stream::read (rgbpixel *p, streamsize NumberOfPixels)
{
	unsigned char RedByte;
	unsigned char GreenByte;
	unsigned char BlueByte;

	for (int i=0; i<NumberOfPixels; i++) {
		
		if (ifstream::eof()) {
			return false;
		}
		
		ifstream::read ((char*)&RedByte, 1);
		ifstream::read ((char*)&GreenByte, 1);
		ifstream::read ((char*)&BlueByte, 1);

		p[i] = rgbpixel(RedByte,GreenByte,BlueByte);
	}
	return true;
}
