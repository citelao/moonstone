#include "Perlin.h"

Perlin::Perlin(int width, int height)
: width(width), height(height) {
    seed = arc4random();
    std::cerr << "No Seed Given to Perlin Noise" << std::endl;
}

void Perlin::generateMap() {
    heightMap = new double[width*height];
    
    double x;
    double y;
    double value;

    double minX;
    double maxX;
    double minY;
    double maxY;
    
    double one; // top-left value
    double two; // top-right value
    double three; // bottom-left value
    double four; // bottom right value
    
    int scale; // as we zoom out (depth gets bigger) the affect on terrain is larger
    for(int i=0; i<width*height; i++) {
        scale = 1;
        value = 0;
        x = i % width;
        y = floor(i/width);
        
        for(int depth=0; depth<7; depth++) { // bigger "depth" implies larger-scale terrain
            scale *= 2;
            if((int)x % scale==0) {
                x += .001;
            }
            if((int)y % scale==0) {
                y += .001;
            }
            minX = floor(x/scale) * scale;
            maxX = ceil(x/scale) * scale;
            if(maxX>=width) { // cycle horizontally
                maxX -= width;
            }
            minY = floor(y/scale) * scale;
            maxY = ceil(y/scale) * scale;
            if(maxX>=height) { // cycle vertically
                maxY -= height;
            }
            
            one = rand2D(minX, minY, seed*depth);
            two = rand2D(maxX, minY, seed*depth);
            three = rand2D(minX, maxY, seed*depth);
            four = rand2D(maxX, maxY, seed*depth);
            
            minX = cos(3.1415926536*(x - minX)/scale)/2+.5;
            maxX = cos(3.1415926536*(maxX - x)/scale)/2+.5;
            minY = cos(3.1415926536*(x - minY)/scale)/2+.5;
            maxY = cos(3.1415926536*(maxY - y)/scale)/2+.5;
            
            one *= minX * minY;
            two *= maxX * minY;
            three *= minX * maxY;
            four *= maxX * maxY;
            
            value += (one + two + three + four) * scale;
        }
        value /= 396; // just a guess; find this value pls
        if(value > 1) {
            value = 1;
        }
        else if(value < 0) {
            value = 0;
        }
        heightMap[i] = value;
    }
}
double Perlin::getPixelHeight(int x, int y) {
    return heightMap[x + width * y];
}
double Perlin::rand2D(double x, double y, int s) {
    double r = (double)(width * y + x); // yields unique integer for every pixel
    r = sin(r + .01 * (double)s) * (double)s; // generate random number
    r -= floor(r); // make it from 0 to 1
    return r;
}