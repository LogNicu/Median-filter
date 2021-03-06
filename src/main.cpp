#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

template < class T >
void bubbleSort( std::vector<T> &toSort );


template <typename T>
void mergeSort(typename std::vector<T>::iterator begin , typename std::vector<T>::iterator  end );


int main() {

    std::string sortType;
    std::cout<<"Choose the sorting algorithm (merge/bubble): ";
    std::cin>>sortType;

    while (sortType != "merge" && sortType != "bubble") {
        std::cout<<"Invalid sorting method. Choose either \"merge\" or \"bubble\".\n You can try again or  else enter enter \"exit\"  ";
        std::cin>>sortType;
        if(sortType=="exit") {
            return 0;
        }
    }

    int sortingWindowSize;
    std::cout << "Choose the size of the sorting window (must be an odd number): ";
    std::cin >> sortingWindowSize;

    while(sortingWindowSize % 2 == 0) {

        std::cout << "The window size must be an odd number. You can try again, else enter enter \"-1\" \n";
        std::cin>>sortingWindowSize;
        if(sortingWindowSize==-1) {
            return 0;
        }

    }
    //Note: when specifying the input image or output image name, the full path must be specified
    //  if the executable and the images are not in the same folder;
    std::string tempStrForInputs;
    std::cout << "Choose the input image ";
    std::cin >> tempStrForInputs;

    std::ifstream inputImage;

    inputImage.open(tempStrForInputs);
    if (!inputImage) {
        std::cout << "Unable to open the input image. Enter any key to exit \n";
        std::cin.ignore();
        std::cin.get();
       return 0;
    }
    std::cout << "Choose the output image: " ;
    std::cin >> tempStrForInputs;

        std::fstream outputImage;
    try {
        outputImage.open(tempStrForInputs, std::fstream::in | std::fstream::app);

        if (!outputImage) {
            std::cout << "File does not exist. Creating new file..";
            outputImage.open(tempStrForInputs, std::fstream::in | std::fstream::trunc);

        }
    }  catch (const std::ifstream::failure& e) {
        std::cout << "Exception opening/reading file\n"<<e.what();
        return 0;
    }

    std::cout << "Please wait \n";

    //passing the file type, comments and window's width and height to the output image
    std::string widthHeightTemp;
    for(int i=0;i<3;i++) {
        getline(inputImage, tempStrForInputs);
        outputImage << tempStrForInputs << "\n";
        if(tempStrForInputs[0] == '#') {
            i--;
        }
        else if(i==1 && tempStrForInputs[0] != '#') {
            widthHeightTemp = tempStrForInputs;
        }
    }
    //getting the width and height of the image from the input file, that is stored in withHeightTemp;
    std::stringstream wHTemp( widthHeightTemp ) ;
    wHTemp >> widthHeightTemp;
    int width = std::stoi( widthHeightTemp );
    wHTemp >> widthHeightTemp;
    int height = std::stoi( widthHeightTemp );

    //filtering the image

    std::vector< std::vector< int > > sortingData( height, std::vector<int> (width) );
    //getting all pixel values

    for(int i=0 ; i < height ; i++) {

        for(uint32_t j = 0 ; j < width ; j++) {
            int tempInt;
            inputImage >> tempInt;
            sortingData[i][j]=tempInt ;
        }

    }


    //applying the filter and writing to the output image
    // so many nested for loops :(
    for(int i=0 ; i < height ; i++ ) { //could most likely be improved

        for(int j=0 ; j < width ; j++) {
            std::vector< int > tempSorter;
            for(int i1 = i - (int)sortingWindowSize / 2 ; i1 <= i + (int)sortingWindowSize / 2; i1++) {
                for(int j1 = j - (int)sortingWindowSize / 2; j1 <= j + (int)sortingWindowSize / 2; j1++) {
                    int tempI , tempJ;
                    if( i1 < 0 ) {
                        tempI = 0;
                    }
                    else if( i1 >= height ) {
                        tempI = height - 1;
                    }
                    else {
                        tempI = i1;
                    }

//                    tempI=0+(i1>=height)*(height-1)+i1*(i1>=0&&i1<height);  this works too

                    if( j1 < 0 ) {
                        tempJ = 0;
                    }
                    else if( j1 >= width ) {
                        tempJ = width - 1;
                    }
                    else {
                        tempJ = j1;
                    }
//                  tempJ=0+(j1>=width)*(width-1)+j1*(j1>=0&&j1<width);    this works too

                    tempSorter.emplace_back( sortingData[tempI][tempJ] );

                }
            }

            if( sortType == "merge" ) {

                mergeSort<int>( tempSorter.begin() , tempSorter.end() );
            }
            else  {

                bubbleSort( tempSorter );
            }

            outputImage << tempSorter[ tempSorter.size()/2 ] << " ";

        }
        outputImage << "\n";

    }

    inputImage.close();
    outputImage.close();
    std::cout << "Finished ! Enter any key to exit \n";

    std::cin.ignore();
    std::cin.get();
    return 0;
}

template < class T >
void bubbleSort( std::vector<T> &toSort) {

    if( toSort.begin() + 1 == toSort.end()) {
        return;
    }
    bool isSorted;
    do {
        isSorted = true;
        for(auto it = toSort.begin() , next = it ; ; it++) {

            next++;
            if( next == toSort.end() ) {
                break;
            }
            if( *it > *next ) {
                T temp = *it;
                *it = *next;
                *next = temp;
                isSorted = false;
            }
        }
    }while( !isSorted );
}

template <typename T>
void mergeSort(typename std::vector<T>::iterator begin , typename std::vector<T>::iterator  end ) {
    if( end == begin+1) {
        return;
    }
    auto fHalfEndMarker = begin + (end - begin)/2;
    mergeSort<T> ( begin , fHalfEndMarker );
    mergeSort<T>(fHalfEndMarker , end );
    std::vector<T> temp( end - begin );
    auto firstHalf = begin;
    auto secondHalf = fHalfEndMarker;
    uint32_t index = 0;


    while( secondHalf != end && firstHalf != fHalfEndMarker) {
        if( *firstHalf < *secondHalf ) {
            temp[index++] = *firstHalf;
            firstHalf++;
        }
        else {
            temp[index++] = *secondHalf;
            secondHalf++;
        }

    }
    while ( firstHalf != fHalfEndMarker ) {
        temp[index++] = *firstHalf;
        firstHalf++;
    }
    while( secondHalf != end) {
        temp[index++] = *secondHalf;
        secondHalf++;
    }

    for(int i=0 ; i<index ; i++) {

        begin[i]=temp[i];
    }

}
