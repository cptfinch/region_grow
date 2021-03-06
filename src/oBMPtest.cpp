// Convert a file from PNM format to BMP format
#include "rgbpixel.h"
#include "oBMPstream.h"


int main (int argc, char *argv[]) {
  
  //rgbpixel pixarray;

  unsigned int width = 200;
  unsigned int height = 200;
  // get size of file
  //unsigned int ImageSize = width * height;

  //rgbpixel* pixarray = new rgbpixel [ImageSize];

  //pixarray[i].SetRedvalue(


  oBMPstream outfile ("oBMPtest.bmp", width, height);
 
  if(!outfile)
  {
    cerr << "Error opening BMP file for writing to" << endl;

    return -1;
  }




  // write chequered pattern to BMP file with different colours in each quadrant

  rgbpixel RedPix(255,0,0);
  rgbpixel GreenPix(0,255,0);
  rgbpixel BluePix(0,0,255);
  rgbpixel YellowPix(255, 255, 128);
  
  unsigned int nWrittenInRow = 0;
  

  for (unsigned int i=0; i<height/2; i++)
  {
    for (unsigned int j=0; j<width; j++)
    {
	if (nWrittenInRow <= width/2)
	{
	  outfile.write (&RedPix, 1);
	  nWrittenInRow++;
	}
	else 
	{
	  outfile.write (&GreenPix, 1);
	  nWrittenInRow++;
	}
    }
    nWrittenInRow = 0;
  }

   for (unsigned int i=0; i<height/2; i++)
  {
    for (unsigned int j=0; j<width; j++)
    {
	if (nWrittenInRow <= width/2)
	{
	  outfile.write (&BluePix, 1);
	  nWrittenInRow++;
	}
	else 
	{
	  outfile.write (&YellowPix, 1);
	  nWrittenInRow++;
	}
    }
    nWrittenInRow = 0;
  }

  outfile.close();

  return 0;
}
