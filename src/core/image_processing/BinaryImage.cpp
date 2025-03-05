#include "core/image_processing/BinaryImage.hpp"
#include "core/io/bmp_stream.hpp"
#include "utils/rgb_pixel.hpp"
#include <utility>
#include <iostream>
#include <vector>

using namespace std;

/*---------------------------------------------------------------------------
Constructor for 2Dbinaryimage reads in a stream and converts it to 2D binary
---------------------------------------------------------------------------*/
BinaryImage::BinaryImage (string stream)
{

  rows = 0;		//initialise variables - if they are still 0 after opening stream then 
  columns = 0;	//can assume constructor has failed.
  rgb_pixel inpixel; //rgbpixel to read stream

  iBMPstream infile (std::move(stream));
  if(!infile)
  {
    cerr << "Error opening input file" << endl;
  }
  
  rows = infile.GetHeight();
  columns = infile.GetWidth();

//define the pixel as on if it has same colour as 
  rgb_pixel on = infile.getColourAt(0);
  rgb_pixel off = infile.getColourAt(1);

//filled stores binary image as boolean values
  filled = new bool[rows*columns];

//visited is for telling if a pixel has already been visited
  visited = new bool[rows*columns];

//visitedB serves same purpose as visited but is used during boundary count
  visitedB = new bool[rows*columns];

//boundaryVisited is for telling if a boundary pixel has already been counted
  boundaryVisited = new bool[rows*columns];

//read the image into 2D array - filled
  for (int i = 0; i < rows*columns; i++)
  {
    infile.read(&inpixel,1);
	
    if (inpixel==on)
    {
	filled[i]=true;
    }
    
    if (inpixel==off)
    {
	filled[i]=false;
    }
    
  }
}// end of constructor

void BinaryImage::countBlobs() 
{
// Find the number of blobs in the grid and report the number to screen.
  int size = 0; // Size of blob/s.
  int perimeter = 0; // perimeter/s.
         /* First clear out the visited array. The getBlobSize() method will
         mark every filled square that it finds by setting the corresponding
         element of the array to true.  Once a square has been marked as
         visited, it will stay marked until all the blobs have been counted.
         This will prevent the same blob from being counted more than once. */
      
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < columns; c++)
    {
      setVisited(r,c,false);
      setVisitedB(r,c,false);
	setBoundaryVisited(r,c,false);
    }
  }
   
      /* For each position in the grid, call getBlobSize() to get the size
         of the blob at that position.  If the size is not zero, count a blob.
         Note that if we come to a position that was part of a previously
         counted square, getBlobSize() will return 0 and the blob will not
         be counted again. */
            
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < columns; c++)
    {
      size = getBlobSize(r,c);
	perimeter = getBlobPerimeter(r,c);
	if (size > 0)
	{        
	  blob b;
	  b.setArea(size); 
	  b.setPerimeter(perimeter);
	  blobs.push_back(b);
        
        for (int r = 0; r < rows; r++)		//set boundary visited = false 
        {
          for (int c = 0; c < columns; c++)
          {
            setBoundaryVisited(r,c,false);
          }
        }
      }
    }
  }                  
  
  for (auto &blob : blobs) {
    cout << "Area " << blob.getArea() << endl;
    cout << "Perimeter = " << blob.getPerimeter() << endl;
  }            

} // end countBlobs()


int BinaryImage::getBlobSize(int r, int c) {
         // Counts the squares in the blob at position (r,c) in the
         // grid.  Squares are only counted if they are filled and
         // unvisited.  If this routine is called for a position that
         // has been visited, the return value will be zero.
      if (r < 0 || r >= rows || c < 0 || c >= columns) 
	{
            // This position is not in the grid, so there is
            // no blob at this position.
         return 0;
      }
      if (!getFilled(r, c) || getVisited(r, c))
	{
           // This square is not part of a blob, or else it has
           // already been counted, so return zero.
         return 0;
      }
      setVisited(r,c,true);   // Mark the square as visited so that
                              //    we won't count it again during the
                              //    following recursive calls to this method.
      int size = 1;  // Count the square at this position, then count the
                     //   the blobs that are connected to this square
                     //    horizontally or vertically.
      size += getBlobSize(r-1,c);
	size += getBlobSize(r+1,c);
      size += getBlobSize(r,c-1);
      size += getBlobSize(r,c+1);
      return size;
   }  // end getBlobSize()
   

int BinaryImage::getBlobPerimeter(int r, int c) {
         // Counts the squares in the blob at position (r,c) in the
         // grid.  Squares are only counted if they are filled and
         // unvisited.  If this routine is called for a position that
         // has been visited, the return value will be zero.
      if (r < 0 || r >= rows || c < 0 || c >= columns) 
	{
            // This position is not in the grid, so there is
            // no blob at this position.
         return 0;
      }
      if (!getFilled(r, c) || getVisitedB(r, c))
	{
           // This square is not part of a blob, or else it has
           // already been counted, so return zero.
         return 0;
      }
      setVisitedB(r,c,true);   // Mark the square as visited so that
                              //    we won't count it again during the
                              //    following recursive calls to this method.
      int boundary = 0;  // Count the square at this position, then count the
                     //   the blobs that are connected to this square
                     //    horizontally or vertically.
      if (!getFilled(r - 1, c) && !getBoundaryVisited(r - 1, c))   // Count boundary squares.
	{
	  boundary ++;
	  setBoundaryVisited(r-1,c,true);
	}     
	
	if (!getFilled(r + 1, c) && !getBoundaryVisited(r + 1, c))   // Count boundary squares.
	{
	  boundary ++;
	  setBoundaryVisited(r+1,c,true);
	}               
      
	if (!getFilled(r, c - 1) && !getBoundaryVisited(r, c - 1))   // Count boundary squares.
	{
	  boundary ++;
	  setBoundaryVisited(r,c-1,true);
	}   
 
	if (!getFilled(r, c + 1) && !getBoundaryVisited(r, c + 1))   // Count boundary squares.
	{
	  boundary ++;
	  setBoundaryVisited(r,c+1,true);
	}    

	boundary += getBlobPerimeter(r-1,c);
	boundary += getBlobPerimeter(r+1,c);
      boundary += getBlobPerimeter(r,c-1);
      boundary += getBlobPerimeter(r,c+1);
      return boundary;
   }  // end getPerimeter Size()
