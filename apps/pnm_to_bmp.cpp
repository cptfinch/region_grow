// Convert a file from PNM format to 24bit BMP format
#include "rgbpixel.h"
#include "oBMPstream.h"
#include "iPNMstream.h"

int main (int argc, char *argv[]) {
  
  
  rgbpixel inout;

  // open files for reading and writing to  
  iPNMstream infile (argv[1]);
  if(!infile)
  {
    cerr << "Error opening PNM file" << endl;
    return -1;
  }
  
  oBMPstream outfile ("new.bmp", infile.GetWidth(), infile.GetHeight());
 
  if(!outfile)
  {
    cerr << "Error writing to BMP file" << endl;
    infile.close();
    return -1;
  }

  // get size of file
  long ImageSize = infile.GetNumberOfPixels();

  // read stream from PNM file and write to BMP file
  for (int i=0; i<ImageSize; i++) {

		infile.read (&inout , 1);

		outfile.write (&inout, 1);

		}

  outfile.close();
  infile.close();
  return 0;
}
