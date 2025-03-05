// Convert a file from BMP binary format to BMP 24bit format
#include "core/image_processing/BinaryImage.hpp"
#include "core/io/bmp_stream.hpp"
#include "utils/rgb_pixel.hpp"

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
