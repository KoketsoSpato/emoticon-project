#ifndef EMOTICON_H_INCLUDED
#define EMOTICON_H_INCLUDED

#include <string>
#include "Circle.h"
#include "Rectangle.h"
#include "EMPixel.h"

class Emoticon {
public:
    Emoticon();
    Emoticon(int intWidth, int intHeight, EMPixel recFaceColor, EMPixel recEyeColor, EMPixel recNoseColor, EMPixel recMouthColor);
    Emoticon(const Emoticon& objOriginal);
    ~Emoticon();

    void drawFace();
    void drawEyes();
    void drawNose();
    void drawMouth();
    std::string toPPM() const;

private:
    int _width;
    int _height;
    EMPixel** _image;
    Circle* _face;
    Rectangle* _eyes;
    Rectangle* _nose;
    Rectangle* _mouth;

    void alloc(int intWidth, int intHeight);
    void dealloc();
};

#endif // EMOTICON_H_INCLUDED
