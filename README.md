# Median-filter
Basically console aplication homework from data structures class. It is median filter for pgm 2 images that uses two different sorting algorithms (bubble and merge) to test their speed for different images and input sizes. 

The input for the console is the following:
-The sorting type (for example: merge)
- The size of the window around the pixel( for example: 3 for 3x3 window size). Must be an odd number
- Name of the source image that needs to be filtered. Full math must be specified (For example: C:\Users\user\Desktop\source_image.pgm)
- You will also need to create a destination pgm image before starting the program to write the filtered image to and specifity it's name in the program after the source image. (For example: C:\Users\user\Desktop\destination_image.pgm )

A median filter is a tehnique for removing noise from images or signals.
A PGM (portable gray map) image, which is of two types (p2 and p5) is a very simple format for representing black and white images. In pgm p2 images the value of each individual pixel as well as other details are written as text in the file.


More info about PGM images on: http://netpbm.sourceforge.net/doc/pgm.html

A good visual example on how the median filter works (as well as java code for it) can be found here:
https://www.southampton.ac.uk/~msn/book/new_demo/median/

The wikipedia page for the median filter:
https://en.wikipedia.org/wiki/Median_filter#:~:text=The%20median%20filter%20is%20a,edge%20detection%20on%20an%20image).

I also added an example pgm p2 image with noise
