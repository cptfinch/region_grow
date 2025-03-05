// Convert a file from BMP binary format to BMP 24bit format
#include "core/image_processing/BinaryImage.hpp"
#include "core/io/bmp_stream.hpp"
#include "src/utils/rgb_pixel.hpp"

int main (int argc, char *argv[]) 
{
  rgbpixel inout;

/* -------------------------open binary image---------------------*/   
  iBMPstream infile (argv[1]);
  if(!infile)
  {
    cerr << "Error opening input file" << endl;
    return -1;
  }
  

/* -------------------------open output file---------------------*/   

  oBMPstream outfile ("iBMPoBMP.bmp", infile.GetWidth(), infile.GetHeight());
 
  if(!outfile)
  {
    cerr << "Error opening output file" << endl;
    infile.close();
    return -1;
  }

/* ------------------------- get size of file---------------------*/    
  long ImageSize = infile.GetNumberOfPixels();

/* -------------------------read and write stream pixel by pixel--*/    
  for (int i=0; i<ImageSize; i++) 
  {
    infile.read (&inout , 1);
    outfile.write (&inout, 1);
  }

  outfile.close();
  infile.close();

  return 0;
}
