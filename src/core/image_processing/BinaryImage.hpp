/*-----------------------------------------------------------------------------	
DESCRIPTION:
============
A 'blob' is defined to be a filled square (pixel) and any square that 
can be reached from that square by moving horizontally or vertically to 
other filled squares. This is a 2D binary image class that opens a binary image
and counts the number of blobs as well as calculating their area and perimeter.

HISTORY:
========
28.04.2005 CPT Finch. Created.
-----------------------------------------------------------------------------*/
#include "blob.hpp"
#include <vector>
#include <string>
#include <utility>

using namespace std;

class BinaryImage
{
public:
  BinaryImage (string infile);
 
  int getBlobSize(int, int);

  int getBlobPerimeter(int, int);

  void countBlobs();

  int getRows() 
  {
    return rows;
  }

  int getColumns() 
  {
    return columns;
  }
  
  bool operator!() const
  {
    if (rows == 0)
    { return true;}
    
    return false;
  }

  bool getFilled(int x, int y) 
  {
    return filled[x*columns + y];
  }

  bool getVisited(int x, int y) 
  {
    return visited[x*columns + y];
  }

  bool getBoundaryVisited(int x, int y) 
  {
    return boundaryVisited[x*columns + y];
  }

  bool getVisitedB(int x, int y) 
  {
    return visitedB[x*columns + y];
  }
    
  void setVisited(int x, int y, bool onOrOff) 
  {
    visited [x*columns + y] = onOrOff;
  }
  
  void setBoundaryVisited(int x, int y, bool onOrOff) 
  {
    boundaryVisited [x*columns + y] = onOrOff;
  }

  void setVisitedB(int x, int y, bool onOrOff) 
  {
    visitedB [x*columns + y] = onOrOff;
  }

private:
  
  int rows;	  
  int columns;
  vector<blob> blobs;

  bool* filled;  		 // filled[r][c] is true if the square at row r, column c is filled.
   
  bool* visited; 		 // visited[r][c] is true if the square at row r, column c has
                         //   has already been visited by the getBlobSize() method.

  bool* boundaryVisited; //boundaryVisited[r][c] is true if the square at row r, column c 
				 // has already been counted as a boundary by the getBlobSize () method.
  bool* visitedB;		 // visitedB[r][c] is true if the square at row r, column c has
                         //   has already been visited by the getBlobPerimeter() method.
  
};
