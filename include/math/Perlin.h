#ifndef PERLIN_H
#define PERLIN_H

#include <cmath>
#include <iostream>

class Perlin {
    
    public:
        Perlin(int width, int height, int seed)
        : width(width), height(height), seed(seed) {};
        Perlin(int width, int height);
    
        double getPixelHeight(int x, int y);
        void generateMap();

    private:
        int width, height, seed;
        double *heightMap;
        double rand2D(double x, double y, int s);
};

#endif /* PERLIN_H */
