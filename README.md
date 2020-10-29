# Median-filter

A console aplication homework from data structures class. It is a median filter for PGM P2 images that uses two different sorting algorithms (bubble and merge) to test their speed for different images and input sizes. 

The input for the console is the following:
- The sorting type (for example: merge)
- The size of the window around the pixel( for example: 3 for 3x3 window size). Must be an odd number
- Name of the source image that needs to be filtered. 
- Name of the image that will be created.

Note: The executable and the input image must be in the same folder , if they aren't, the full path of the images must be specified.
        Example input if the exe and the input image are on the desktop:
        
        >>merge
        
        >>3
        
        >>inputImage.pgm
        
        >>outputImage.pgm
        
-The output image will be created in the same folder. You can also create an empty image beforehand wherever you want and select it as the output        
        

A median filter is a technique for removing noise from images or signals.
A PGM (portable gray map) image is a very simple format for representing black and white images. In pgm p2 images the value of each individual pixel as well as other details are written as text in the file.


More info about PGM images on: http://netpbm.sourceforge.net/doc/pgm.html

A good visual example on how the median filter works (as well as java code for it) can be found here:
https://www.southampton.ac.uk/~msn/book/new_demo/median/

The wikipedia page for the median filter:
https://en.wikipedia.org/wiki/Median_filter#:~:text=The%20median%20filter%20is%20a,edge%20detection%20on%20an%20image).

I also added an example pgm p2 image with noise
