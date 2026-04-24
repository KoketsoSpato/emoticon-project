#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include <string>
#include "EMPixel.h"

class Circle {
public:
    Circle(EMPixel color);
    ~Circle();
    void draw(int centerX, int centerY, int radius, EMPixel** image, int width, int height) const;

private:
    EMPixel _color;
};

#endif // CIRCLE_H_INCLUDED
