#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "core/io/pnm_stream.hpp"
#include "utils/rgb_pixel.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	pnm_stream pnmimage(argv[1]);
	int ImageSize = pnmimage.GetNumberOfPixels();
	int myWidth = pnmimage.GetWidth();
	int myHeight = pnmimage.GetHeight();
	cout << ImageSize << endl;
	cout << "Width = " << myWidth << endl;
	cout << "Height = " << myHeight << endl;
	rgb_pixel buf[ImageSize];
	pnmimage.read(buf, ImageSize);
	cout << (int)buf[0].GetRedValue() << endl;
	ofstream intImage("integer_image.txt");
	intImage << setprecision(2);
	intImage << fixed;
	intImage << left;
/*
	cout << setw(20) << "pixel number" << setw(12) << "Red Value";
	cout << setw(12) << "Green Value" << setw(12) << "Blue Value" << endl;
*/
	for (int i=0; i < ImageSize; i++) {
		intImage << setw(5) << (int)buf[i].GetRedValue();
		if (i % myWidth==0){ intImage << endl; }
	}
	intImage.close();
	pnmimage.close();
	return 0;
}
