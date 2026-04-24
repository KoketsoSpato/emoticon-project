#include "Emoticon.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Define colors for the emojie features
    EMPixel faceColor = {255, 255, 0};  // Yellow face
    EMPixel eyeColor = {139, 69, 19};   // Brown eyes
    EMPixel noseColor = {0, 0, 0};      // Black nose
    EMPixel mouthColor = {255, 255, 255}; // White mouth

    //Emoticon object
    Emoticon myEmoticon(500, 500, faceColor, eyeColor, noseColor, mouthColor);

    // Generating PPM image as a string
    std::string ppmData = myEmoticon.toPPM();

    // Output ppm data to the console
    cout << ppmData << endl;

    ofstream outFile("image.ppm");
    if (outFile)
    {
        outFile << ppmData;
        outFile.close();
        cout << "The PPM file is saved as image.ppm" << endl;
    } else
    {
        cerr << "Failed to create image.ppm" << endl;
    }

    return 0;
}
