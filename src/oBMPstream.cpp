#include "rgbpixel.h"
#include "oBMPstream.h"


oBMPstream::oBMPstream (string outfile, unsigned int Width, unsigned int Height)
	{
		
		ImageWidth = Width;	//Initialise private variables
		ImageHeight = Height;
		nWritten = 0;		//nWritten to keep track of number of pixels 
						//outputted so padding can be done
		
		struct BitMapFileHeader 
		{
		  char bfType[2];
		  unsigned int bfSize;
		  unsigned short bfReserved1;
		  unsigned short bfReserved2;
		  unsigned int bfOffBits;
		} __attribute__ ((packed));


		struct BitMapInfoHeader 
		{
		  unsigned int biSize;
		  unsigned int biWidth;
		  unsigned int biHeight;
		  
		  unsigned short biPlanes;
		  unsigned short biBitCount;

		  unsigned int biCompression;
		  unsigned int biSizeImage;
		  unsigned int biXPelsPerMeter;
		  unsigned int biYPelsPerMeter;
		  unsigned int biClrUsed;
		  unsigned int biClrImportant;
		} __attribute__ ((packed));

		BitMapFileHeader bf;
		BitMapInfoHeader bi;

		bi.biSize = sizeof(BitMapInfoHeader);
		bi.biWidth = Width;
		bi.biHeight = Height;
		bi.biPlanes = 1;
		bi.biBitCount = 24;
   		bi.biCompression = 0;
		bi.biSizeImage = 0;
		bi.biXPelsPerMeter = 0;
		bi.biYPelsPerMeter = 0;
		bi.biClrUsed = 0;
		bi.biClrImportant = 0;

 		unsigned char BytesPerPixel = bi.biBitCount / 8;
 		unsigned int BytesPerRow = BytesPerPixel * Width;
 		
 		unsigned char BytePaddingPerRow = 4 - ( BytesPerRow )% 4;
 		if( BytePaddingPerRow == 4 )
 		{ BytePaddingPerRow = 0; }
		
		BytePadding = BytePaddingPerRow; //initialise private variable
		
		unsigned int ActualBytesPerRow = BytesPerRow + BytePaddingPerRow;
 		unsigned int TotalPixelBytes = Height * ActualBytesPerRow;
 
 		int PaletteSize = 0;
 
 		unsigned int TotalFileSize = 14 + bi.biSize + PaletteSize + TotalPixelBytes;

		bf.bfType[0] = 'B';
		bf.bfType[1] = 'M';
		bf.bfSize = TotalFileSize / 4;	//Size in longwords (4-byte units) of the file
		bf.bfReserved1 = 0;
		bf.bfReserved2 = 0;
		bf.bfOffBits = 0;

		ofstream::open (outfile.c_str(), ios::out | ios::binary);

		ofstream::write ((char*)&bf, sizeof(bf));
		ofstream::write ((char*)&bi, sizeof(bi));

	}


bool oBMPstream::write (rgbpixel *p, streamsize NumberOfPixels)
{

	char* Temp = new char [BytePadding];	//Create new char array for byte												//padding at end of each row 
	
  	for (int i=0; i<NumberOfPixels; i++) 
	{
	  if (nWritten >= ImageWidth*ImageHeight)
	  {
		return false;
	  }

	  unsigned char r = p[i].GetRedValue();
	  unsigned char g = p[i].GetGreenValue();
	  unsigned char b = p[i].GetBlueValue();

	  ofstream::write ((char*) &b, 1);
	  ofstream::write ((char*) &g, 1);
	  ofstream::write ((char*) &r, 1);
	  
	  nWritten++;	

	  if (nWritten % ImageWidth == 0)
	  {
	    ofstream::write (Temp, BytePadding);
	    
	  }
	
	}
	
	delete[] Temp;

	return true;
}




