#include <vector>

using namespace std;

class blob 
{
private:
	int area;
	int perimeter;
	
public:
	int getArea();
	int getPerimeter();
	
	void setArea(int);
	void setPerimeter(int);

	blob(int anArea, int aPerimeter);

	blob() {}

};

typedef vector<blob>::iterator blobIterator;

