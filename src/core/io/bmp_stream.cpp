#include "core/io/bmp_stream.hpp"
#include "utils/rgb_pixel.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

/*---------------------------------------------------------------------------*/
/* Constructor for bmp_stream reads in header info, calculates byte-padding */
/*---------------------------------------------------------------------------*/
bmp_stream::bmp_stream (string infile)
	{
	
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

		struct RGBQUAD 
		{
		  unsigned char rgbBlue;
		  unsigned char rgbGreen;
		  unsigned char rgbRed;
		  unsigned char rgbReserved;
		} __attribute__ ((packed));

		BitMapFileHeader bf;
		BitMapInfoHeader bi;


		nRead = 0;				//initialise nRead to keep track of number of pixels 
							//inputted so padded bytes can be skipped over
		numberOfRowsRead = 0;

		ifstream::open (infile.c_str(), ios::in | ios::binary);
		
		if(ifstream::fail())
		{
    		  cerr << "Error opening input file" << endl;
    		  return;
	      }
		    

		ifstream::read ((char*)&bf, sizeof(BitMapFileHeader));	//Read file header into file header struct
		ifstream::read ((char*)&bi, sizeof(BitMapInfoHeader));	//Read image header into image header struct

		Width = bi.biWidth;				//Set private variables
		Height = bi.biHeight;
		NumberOfPixels = Width * Height;
		startOfImage = bf.bfOffBits;

		cout << "Width = " << Width << endl;
		cout << "Height = " << Height << endl;
		cout << "bi.biClrUsed = " << bi.biClrUsed << endl;
		cout << "bf.bfOffBits = " << bf.bfOffBits << endl;
		cout << "bi.biSize = " << bi.biSize << endl;

/*---------------------------------------------------------------------------*/
/*Read in colour map to array of RGBQUAD structs*/
/*Change colour map from array of RGBQUAD structs to array of rgbpixel objects..*/
/*private pointer variable colourMap is made to point to space on heap for storing rgbpixel colourmap*/ 
/*---------------------------------------------------------------------------*/

		RGBQUAD* icolourMap = new RGBQUAD [bi.biClrUsed];	//create space on heap to read in colour map
		ifstream::read ((char*)icolourMap, sizeof(RGBQUAD)*bi.biClrUsed);	//Read colour map

		cout << "icolourMap[0].rgbRed = " << (int)icolourMap[0].rgbRed << endl;
		cout << "icolourMap[0].rgbGreen = " << (int)icolourMap[0].rgbGreen << endl;
		cout << "icolourMap[0].rgbBlue = " << (int)icolourMap[0].rgbBlue << endl;

		cout << "icolourMap[1].rgbRed = " << (int)icolourMap[1].rgbRed << endl;
		cout << "icolourMap[1].rgbGreen = " << (int)icolourMap[1].rgbGreen << endl;
		cout << "icolourMap[1].rgbBlue = " << (int)icolourMap[1].rgbBlue << endl;

		colourMap = new rgbpixel[bi.biClrUsed];		
		for (unsigned int i=0; i < bi.biClrUsed; i++)
		{
		  colourMap[i].SetRedValue(icolourMap[i].rgbRed);
		  colourMap[i].SetGreenValue(icolourMap[i].rgbGreen);
		  colourMap[i].SetBlueValue(icolourMap[i].rgbBlue);
		}

		cout << "colourMap[0].GetRedValue() = " << (int)colourMap[0].GetRedValue() << endl;
		cout << "colourMap[0].GetGreenValue() = " << (int)colourMap[0].GetGreenValue() << endl;
		cout << "colourMap[0].GetBlueValue() = " << (int)colourMap[0].GetBlueValue() << endl;

		cout << "colourMap[1].GetRedValue() = " << (int)colourMap[1].GetRedValue() << endl;
		cout << "colourMap[1].GetGreenValue() = " << (int)colourMap[1].GetGreenValue() << endl;
		cout << "colourMap[1].GetBlueValue() = " << (int)colourMap[1].GetBlueValue() << endl;
		
		delete[] icolourMap;


/*---------------------------------------------------------------------------*/
/* calculate byte padding per row */
/*---------------------------------------------------------------------------*/


		unsigned int BytesPerRow = (bi.biBitCount * Width) / 8;
		cout << "BytesPerRow = " << BytesPerRow << endl;
 		
 		BytePaddingPerRow = 4 - ( BytesPerRow )% 4;
 		if( BytePaddingPerRow == 4 )
 		{ BytePaddingPerRow = 0; }
		
		cout << "BytePaddingPerRow = " << (int)BytePaddingPerRow << endl;
 		
/*---------------------------------------------------------------------------*/
/* determine size of image data, including byte padding  */
/*---------------------------------------------------------------------------*/	

		ActualBytesPerRow = BytesPerRow + BytePaddingPerRow;
		cout << "ActualBytesPerRow = " << ActualBytesPerRow << endl;
 		
 		unsigned int TotalPixelBytes = Height * ActualBytesPerRow;
		cout << "TotalPixelBytes = " << TotalPixelBytes << endl;
 		
 
 		int PaletteSize = (bi.biClrUsed)*sizeof(RGBQUAD);
 
 		unsigned int TotalFileSize = 14 + bi.biSize + PaletteSize + TotalPixelBytes;

		cout << "TotalFileSize = " << TotalFileSize << endl;
	
 		

}

/*===========================================================================*/



bool bmp_stream::read (rgbpixel *p, streamsize NumberOfPixels)

/*-----------------------------------------------------------------------------	
DESCRIPTION:
============
Reads in a data stream by taking pixel data from the front of a queue.

HISTORY:
========
18.04.2005 CPT Finch. Created.
-----------------------------------------------------------------------------*/	

{
  	for (streamsize i=0; i<NumberOfPixels; i++) 
	{
	  if (nRead >= Width * Height)
	  {
		return false;
	  }

        if (pixq.empty())
        {
          inflate ();
        }

        p[i] = pixq.front();
        pixq.pop ();

	}

	return true;

}

/*===========================================================================*/


bool bmp_stream::inflate ()
/*-----------------------------------------------------------------------------	
DESCRIPTION:
============
Reads a byte from the input stream, decodes it and pushes each bit onto queue 
after converting each to rgbpixel type
i.e. populates a pixel queue with image pixels and not any byte padding.

HISTORY:
========
19.04.2005 CPT Finch. Created.
-----------------------------------------------------------------------------*/		
{
  unsigned char byte;
  char* Temp = new char [BytePaddingPerRow];
  int index[8];
/*---------------------------------------------------------------------------*/
/*check for end of file*/
/*---------------------------------------------------------------------------*/

  if (numberOfRowsRead == Height)
  {
    return false;
  }

/*---------------------------------------------------------------------------*/
/*read a byte from the (file) stream and decode it.. */
/*read from last row to be consistent with PNM top-left bottom-right stream order*/ 
/*---------------------------------------------------------------------------*/
  ifstream::seekg(startOfImage + ActualBytesPerRow*(Height-1-numberOfRowsRead), ios::beg);
  
  for (int i=0; i < (int)BytesPerRow; i++)
  {
    ifstream::read ((char *)&byte, 1);

    index[0] = ((byte & 0x80) >> 7);
    index[1] = ((byte & 0x40) >> 6);
    index[2] = ((byte & 0x20) >> 5);
    index[3] = ((byte & 0x10) >> 4);
    index[4] = ((byte & 0x08) >> 3);
    index[5] = ((byte & 0x04) >> 2);
    index[6] = ((byte & 0x02) >> 1);
    index[7] = ((byte & 0x01) >> 0);

    for(int j=0; j<8; j++)
    {
      pixq.push (colourMap[index[j]]);
      nRead++;
    }

     if (nRead % Width == 0)
    {
      ifstream::read (Temp, BytePaddingPerRow);
	break;
    }

  }


  numberOfRowsRead++;
  delete[] Temp;

  return true;

}