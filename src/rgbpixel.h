#ifndef RGBPIXEL_H
#define RGBPIXEL_H
#endif

class rgbpixel {
private:
	unsigned char RedValue;
	unsigned char GreenValue;
	unsigned char BlueValue;

public:
	unsigned char GetRedValue();
	unsigned char GetGreenValue();
	unsigned char GetBlueValue();

	void SetRedValue(unsigned char);
	void SetGreenValue(unsigned char);
	void SetBlueValue(unsigned char);


	rgbpixel(unsigned char ARedValue,
		   unsigned char AGreenValue, 
	     	   unsigned char ABlueValue);

	rgbpixel() {}

};


bool operator==(rgbpixel a, rgbpixel b);


