# Emoticon Project (C++)

## About the project
This is a C++ project I worked on that generates a simple emoticon image using object-oriented programming. The idea was to practice working with classes, dynamic memory, and basic graphics concepts by manually building an image pixel by pixel.
The program creates a face using shapes like circles and rectangles, then exports the result as a PPM image file.

## What I learned
While doing this project, I got more comfortable with:

- Object-oriented programming (classes and objects)
- Constructors and destructors
- Dynamic memory (2D arrays)
- Working with multiple files in C++
- Basic idea of how images are stored using pixels

## How it works
The program builds an image in memory using a 2D array of pixels. Different shapes (like eyes, nose, and mouth) are drawn onto the image using simple math and then combined to form an emoticon face.
Finally, the image is written into a `.ppm` file which can be opened using an image view

## How to run it
Compile the project on the terminal using:
1. g++ main.cpp Emoticon.cpp Circle.cpp Rectangle.cpp -o emoticon
2. Run it: emoticon -> This will generate a `.ppm` file output.
3. I used Gimp to View the image

## Future improvements

If I continue improving it, I would like to:
- Add more shapes
- Allow user input for colors and size
- Maybe convert output to other image formats
