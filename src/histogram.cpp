#include <iostream>
#include "iPNMstream.h"
#include <string>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{
	iPNMstream pnmimage(argv[1]);
	
	int ImageSize = pnmimage.GetNumberOfPixels();

	rgbpixel p;

	unsigned char RedArray[ImageSize];
	unsigned char GreenArray[ImageSize];
	unsigned char BlueArray[ImageSize];
	
	for (int i=0; i<ImageSize; i++) {

		pnmimage.read (&p , 1);

		RedArray[p.GetRedValue()]+=1;
		GreenArray[p.GetGreenValue()]+=1;
		BlueArray[p.GetBlueValue()]+=1;
		}

	cout << fixed;
	cout << left;

	cout << setw(20) << "Intensity" << setw(12) << "Red Value";
	cout << setw(12) << "Green Value" << setw(12) << "Blue Value" << endl;
	
	for (int i=0; i<256; i++) {
		
	cout << setw(20) << i << setw(12) << (int)RedArray[i];
	cout << setw(12) << (int)GreenArray[i] << setw(12) << (int)BlueArray[i] << endl;
	
		}

	pnmimage.close();
	return 0;
}


