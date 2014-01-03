#include "../include/bitmap.hpp"
#include <fstream>
#include <utility>


image::Bitmap::Bitmap(const std::string & fileName) {
    std::ifstream file(fileName, std::ios::binary | std::ios::in);    
    if(file) {
       
        image::BitmapHeader header;
        // read header
        file.read( reinterpret_cast<char *>(&header), sizeof(header));
        width = header.width;
        height = header.height;
        size = width * height;
        pixelArray.reserve(size);
        file.seekg(header.pixelArrayOffset, std::ios_base::beg);
        // intended to support 24 and 8 bit bitmaps only
        std::size_t bytesPerPixel = header.bitsPerPixel / 8;
        int length = header.width * bytesPerPixel;
        std::size_t padding = (4 - (length & 3) ) & 3;
        std::size_t tempSize = (header.height*(header.width + padding) ) * bytesPerPixel;
        std::unique_ptr<char> temp(new char[tempSize]);
        file.read(temp.get(), tempSize);

        std::size_t offset = 0;
        
        for(int i = height - 1; i >=0; i--) {
            
            for(std::size_t j=0; j < width; j++){
                   if(bytesPerPixel == 3) {
                       pixelArray[i*header.width + j].b = temp.get()[offset++];
                       pixelArray[i*header.width + j].g = temp.get()[offset++];
                       pixelArray[i*header.width + j].r = temp.get()[offset++];
                   }else {
                        //8 bit
                        pixelArray[i*header.width + j].b = temp.get()[offset];
                        pixelArray[i*header.width + j].g = temp.get()[offset];
                        pixelArray[i*header.width + j].r = temp.get()[offset++];
                   }
                }
                offset += padding;
        }
        
        
    }else {
        width = height = size = 0;
    }
}   

image::Bitmap::Bitmap(Bitmap &&toMove) : width(toMove.width), 
    height(toMove.height), size(toMove.size), pixelArray(std::move(toMove.pixelArray)){

}


image::Bitmap::Bitmap(const Bitmap &toCopy) : width(toCopy.width),
    height(toCopy.height), size(toCopy.size),  pixelArray(toCopy.pixelArray) {

}

image::Bitmap& image::Bitmap::operator=(Bitmap &&toMove)
{

    pixelArray = std::move(toMove.pixelArray);
    width = toMove.width;
    height = toMove.height;
    size = toMove.size;
    return *this;
}

image::Bitmap& image::Bitmap::operator=(const Bitmap &toCopy) {
    Bitmap temp(toCopy);
    swap(*this, temp);
    return *this;
}

void image::swap(Bitmap &first, Bitmap &second) {
    std::swap(first.pixelArray, second.pixelArray);
    std::swap(first.width, second.width);
    std::swap(first.height, second.height);
    std::swap(first.size, second.size);

}

