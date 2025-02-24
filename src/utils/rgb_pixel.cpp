#include "utils/rgb_pixel.hpp"
#include <iostream>

using namespace std;
rgb_pixel::rgb_pixel(unsigned char ARedValue, unsigned char AGreenValue, unsigned char ABlueValue){
	RedValue = ARedValue;
	GreenValue = AGreenValue;
	BlueValue = ABlueValue;
}
	
unsigned char rgb_pixel::GetRedValue(){
	return RedValue;
}

unsigned char rgb_pixel::GetGreenValue(){
	return GreenValue;
}

unsigned char rgb_pixel::GetBlueValue(){
	return BlueValue;
}

//Set private variables
void rgb_pixel::SetRedValue(unsigned char Value){
	RedValue = Value;
}

void rgb_pixel::SetGreenValue(unsigned char Value){
	GreenValue = Value;
}

void rgb_pixel::SetBlueValue(unsigned char Value){
	BlueValue = Value;
}

bool operator==(rgb_pixel a, rgb_pixel b) 
{
  if (a.GetRedValue()==b.GetRedValue() && a.GetGreenValue()==b.GetGreenValue() && a.GetBlueValue()==b.GetBlueValue())
  {
    return true;
  }
  else {return false;}
}
