#include "rgbpixel.h"

rgbpixel::rgbpixel(unsigned char ARedValue,
		   unsigned char AGreenValue, 
	     	   unsigned char ABlueValue){
	
	RedValue = ARedValue;
	GreenValue = AGreenValue;
	BlueValue = ABlueValue;
}
	
unsigned char rgbpixel::GetRedValue(){
	
	return RedValue;
}

unsigned char rgbpixel::GetGreenValue(){
	
	return GreenValue;
}

unsigned char rgbpixel::GetBlueValue(){
	
	return BlueValue;
}


//Set private variables
void rgbpixel::SetRedValue(unsigned char Value){
	
	RedValue = Value;
}

void rgbpixel::SetGreenValue(unsigned char Value){
	
	GreenValue = Value;
}

void rgbpixel::SetBlueValue(unsigned char Value){
	
	BlueValue = Value;
}


bool operator==(rgbpixel a, rgbpixel b) 
{
  if (a.GetRedValue()==b.GetRedValue() && a.GetGreenValue()==b.GetGreenValue() && a.GetBlueValue()==b.GetBlueValue())
  {
    return true;
  }
  else {return false;}
}


