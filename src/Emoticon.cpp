#include "Emoticon.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

Emoticon::Emoticon()
    : Emoticon(200, 200, {255, 255, 0}, {139, 69, 19}, {0, 0, 0}, {255, 255, 255})
{
}

Emoticon::Emoticon(int intWidth, int intHeight, EMPixel recFaceColor, EMPixel recEyeColor, EMPixel recNoseColor, EMPixel recMouthColor)
    : _width(intWidth), _height(intHeight)
{
    alloc(_width, _height);
    _face = new Circle(recFaceColor);
    _eyes = new Rectangle(recEyeColor);
    _nose = new Rectangle(recNoseColor);
    _mouth = new Rectangle(recMouthColor);

    drawFace();
    drawEyes();
    drawNose();
    drawMouth();
}

Emoticon::Emoticon(const Emoticon& objOriginal)
    : _width(objOriginal._width), _height(objOriginal._height)
{
    alloc(_width, _height);
    _face = new Circle(*objOriginal._face);
    _eyes = new Rectangle(*objOriginal._eyes);
    _nose = new Rectangle(*objOriginal._nose);
    _mouth = new Rectangle(*objOriginal._mouth);

    drawFace();
    drawEyes();
    drawNose();
    drawMouth();
}

Emoticon::~Emoticon()
{
    delete _face;
    delete _eyes;
    delete _nose;
    delete _mouth;
    dealloc();
}

void Emoticon::alloc(int intWidth, int intHeight)
{
    _image = new EMPixel*[intHeight];
    for (int r = 0; r < intHeight; ++r)
    {
        _image[r] = new EMPixel[intWidth];
        for (int c = 0; c < intWidth; ++c)
        {
            _image[r][c] = {255, 255, 255};
        }
    }
}

void Emoticon::dealloc()
{
    for (int r = 0; r < _height; ++r)
        {
        delete[] _image[r];
    }
    delete[] _image;
}

void Emoticon::drawFace()
{
    _face->draw(_width/2, _height/2, std::min(_width, _height)/2, _image, _width, _height);
}

void Emoticon::drawEyes()
{
    int eyeSize = std::min(_width, _height)/10;
    int eyeY = _height/3 - eyeSize/2;
    _eyes->draw(_width/3 - eyeSize/2, eyeY,eyeSize, eyeSize, _image, _width, _height);
    _eyes->draw(2 * _width/3 - eyeSize/2, eyeY,eyeSize, eyeSize,_image, _width, _height);
}

void Emoticon::drawNose()
{
    int noseWidth = std::min(_width, _height)/8;
    int noseHeight = std::min(_width, _height)/10;
    int noseX = _width/2 - noseWidth/2;
    int noseY = _height/2 - noseHeight/2;
    _nose->draw(noseX, noseY, noseWidth, noseHeight, _image, _width, _height);
}

void Emoticon::drawMouth()
{
    int mouthWidth = std::min(_width, _height)/4;
    int mouthHeight = std::min(_width, _height)/10;
    int mouthX = _width/2 - mouthWidth/2;
    int mouthY = _height/2 + std::min(_width, _height)/4;
    _mouth->draw(mouthX, mouthY, mouthWidth, mouthHeight, _image, _width, _height);
}

string Emoticon::toPPM() const
{
    stringstream ssPPM;
    ssPPM << "P3\n" << _width << ' ' << _height << "\n255\n";
    for (int r = 0; r < _height; ++r)
    {
        for (int c = 0; c < _width; ++c)
        {
            ssPPM << _image[r][c].intRed << ' '
                  << _image[r][c].intGreen << ' '
                  << _image[r][c].intBlue << ' ';
        }
        ssPPM << endl;
    }
    return ssPPM.str();
}
