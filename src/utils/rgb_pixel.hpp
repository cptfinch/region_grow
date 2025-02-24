#ifndef RGBPIXEL_H
#define RGBPIXEL_H
#endif

class rgb_pixel {
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

	rgb_pixel(unsigned char ARedValue, unsigned char AGreenValue, unsigned char ABlueValue);
	rgb_pixel() {}
};


bool operator==(rgb_pixel a, rgb_pixel b);


