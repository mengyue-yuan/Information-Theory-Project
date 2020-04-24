#include <stdio.h>
#include "jpeg_encoder.h"
#include<iostream>
using namespace std;

//-------------------------------------------------------------------------------
int main(int argc, char* argv[])
{

	JpegEncoder encoder;
	encoder.readFromBMP("lena.bmp");
	encoder.encodeToJPG("out1.jpg", 1);

	return 0;
}

