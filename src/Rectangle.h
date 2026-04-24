#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include <string>
#include "EMPixel.h"

class Rectangle {
public:
    Rectangle(EMPixel color);
    ~Rectangle();
    void draw(int startX, int startY, int width, int height, EMPixel** image, int imgWidth, int imgHeight) const;

private:
    EMPixel _color;
};

#endif // RECTANGLE_H_INCLUDED
