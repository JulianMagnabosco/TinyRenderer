#include "tgaimage.h"
#include <iostream>

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

TGAImage line (TGAImage image ,int x0,int y0 ,int x1,int y1){
	for(double i=0.; i<=1.; i+=.01){
		std::cout << i << std::endl;
        int x = x0 + (x1-x0)*i; 
        int y = y0 + (y1-y0)*i; 
		image.set(x,y,red);
	}
	return image;
}

int main(int argc, char** argv) {
	TGAImage image(100, 100, TGAImage::RGB);
	image.set(2, 2, red);
	// image.flip_vertically(); //to have the origin at the left bottom corner
	image=line(image,23,32,88,71);
	image.write_tga_file("image.tga");
	return 0;
}
