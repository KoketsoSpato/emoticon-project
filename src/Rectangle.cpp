#include "Rectangle.h"

Rectangle::Rectangle(EMPixel color)
    : _color(color)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw(int startX, int startY, int width, int height, EMPixel** image, int imgWidth, int imgHeight) const
{
    for (int r = startY; r < startY + height; ++r) {
        for (int c = startX; c < startX + width; ++c) {
            if (r >= 0 && r < imgHeight && c >= 0 && c < imgWidth) {
                image[r][c] = _color;
            }
        }
    }
}
