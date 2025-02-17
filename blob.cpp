#include "blob.h"

blob::blob(int anArea, int aPerimeter){
	
	area = anArea;
	perimeter = aPerimeter;
}
	
int blob::getArea(){
	
	return area;
}

int blob::getPerimeter(){
	
	return perimeter;
}

//Set private variables
void blob::setArea(int anArea){
	
	area = anArea;
}

void blob::setPerimeter(int aPerimeter){
	
	perimeter = aPerimeter;
}




