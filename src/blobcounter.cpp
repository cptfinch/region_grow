// Convert a file from BMP binary format to BMP 24bit format
#include "rgbpixel.h"
#include "iBMPstream.h"
#include "BinaryImage.h"

int main (int argc, char *argv[]) 
{

/* -------------------------open binary image---------------------*/   
  BinaryImage binaryImage (argv[1]);
  if(!binaryImage)
  {
    cerr << "Error opening binary image" << endl;
    return -1;
  }
  
/* ------------------------- get size of file---------------------*/    
/*  int rows = binaryImage.getRows();
  int columns = binaryImage.getColumns();
*/

/* -------------------------get number of blobs--*/    
  binaryImage.countBlobs();
  
  return 0;
}
