#pragma once
#include <string>
#include <memory>
#include <cstdint>
#include <vector>

namespace image
{
constexpr std::size_t BMP_HEADER_SIZE = 14;
constexpr std::size_t DIB_HEADER_SIZE = 40; 

struct BitmapHeader {
    // BMP header total size 14 bytes
    unsigned short signature;
    unsigned int fileSize;
    unsigned short reservedOne;
    unsigned short reservedTwo;
    unsigned int pixelArrayOffset;
    // DIB header
    unsigned int dibHeaderSize;
    unsigned int width;
    unsigned int height;
    unsigned short nColorPlanes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int rawDataSize;
    unsigned int horizontalRes; // pixels / meter
    unsigned int verticalRes; // pixels / meter
    unsigned int numColors;
    unsigned int importantColors;
} __attribute__((__packed__)); // no padding 


struct Pixel {
    unsigned char r,g,b;
};

struct Bitmap {

    friend void swap(Bitmap &first, Bitmap &second);
    std::size_t width, height, size;
private:        
    std::vector<Pixel> pixelArray;
public:    
    Bitmap(std::size_t width, std::size_t height) : width(width), height(height), 
            size( width * height), pixelArray(size) {}
    // loads bitmap from file
    Bitmap(const std::string &fileName);
    Bitmap(const Bitmap&);
    Bitmap(Bitmap &&);
    Bitmap& operator=(const Bitmap&);
    Bitmap& operator=(Bitmap&&);
    Pixel& operator[](std::size_t index){ return pixelArray[index];}


};

void swap(Bitmap &first, Bitmap &second);

} // END_NAMESPACE_IMAGE

