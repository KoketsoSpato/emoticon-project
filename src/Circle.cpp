#include "Circle.h"
#include <cmath>

Circle::Circle(EMPixel color)
    : _color(color)
{
}

Circle::~Circle()
{
}

void Circle::draw(int centerX, int centerY, int radius, EMPixel** image, int width, int height) const
{
    for (int r = 0; r < height; ++r)
    {
        for (int c = 0; c < width; ++c)
        {
            if (sqrt(pow(r - centerY, 2) + pow(c - centerX, 2)) <= radius)
            {
                image[r][c] = _color;
            }
        }
    }
}
