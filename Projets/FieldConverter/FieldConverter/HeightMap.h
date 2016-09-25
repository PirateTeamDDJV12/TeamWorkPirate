/*
Created by Sun-lay Gagneux
*/
#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H


#include <cstdint>
#include <string>
#include <memory.h>


namespace FieldConverter
{
    class HeightMap
    {
    public:
        class ErrorLoadingHeightMap{};


    public:
        enum
        {
            MIN_Z_HEIGHT = 0,
            MAX_Z_HEIGHT = 255,
            DEFAULT_HEIGHTMAP_IMAGE_WIDTH = 257,
            DEFAULT_HEIGHTMAP_IMAGE_HEIGHT = 257,
        };


    private:
        unsigned int m_width;
        unsigned int m_height;
        unsigned int m_totalSize;

        uint8_t* m_grayscalePixelArray;
        

    public:
        /*
        prefered constructor. The string in the parameter serves to specify the path
        to the loading image. Must be relative to the .exe and be careful, I'll throw
        if the file wasn't loaded correctly or some problems occur along the way.
        */
        HeightMap(const std::string& pathFile);
        HeightMap(const HeightMap& copy);
        HeightMap(HeightMap&& destructiveMovedSample) noexcept;

        ~HeightMap()
        {
            delete[] m_grayscalePixelArray;
        }


    public:
        /*
        get the pixel value (between 0 and 255) at index1d (consider the array
        image as a 1D array with each row concatened next to each other)
        */
        uint8_t at(unsigned int index1D) const noexcept
        {
            return m_grayscalePixelArray[index1D];
        }

        /*
        get the pixel value (between 0 and 255) at the indexes specified by columnIndex
        and rowIndex (pixel index in the image as a matrix 2D)
        */
        uint8_t at(unsigned int columnIndex, unsigned int rowIndex) const noexcept
        {
            return m_grayscalePixelArray[columnIndex * rowIndex];
        }

        uint8_t& at(unsigned int index1D) noexcept
        {
            return (*this)[index1D];
        }

        uint8_t& at(unsigned int columnIndex, unsigned int rowIndex) noexcept
        {
            return (*this)(columnIndex, rowIndex);
        }

        /*
        get the total size of the image (the number of pixel inside)
        */
        unsigned int size() const noexcept
        {
            return m_totalSize;
        }

        /*
        get the width of the image (the height corresponds at the max column value of the
        picture) relatives to the upper left border of the image
        */
        unsigned int width() const noexcept
        {
            return m_width;
        }

        /*
        get the height of the image (the height corresponds at the max row value of the 
        picture) relatives to the upper left border of the image
        */
        unsigned int height() const noexcept
        {
            return m_height;
        }



    private:
        void load(const std::string& pathFile);

        void swap(HeightMap& autre) noexcept;

        uint8_t* begin() const noexcept
        {
            return m_grayscalePixelArray;
        }

        uint8_t* end() const noexcept
        {
            return m_grayscalePixelArray + m_totalSize;
        }

    public:
        HeightMap& operator=(const HeightMap& other);
        HeightMap& operator=(HeightMap&& destructiveMovedSample);

        uint8_t operator[](unsigned int index1D) const noexcept
        {
            return m_grayscalePixelArray[index1D];
        }

        uint8_t operator()(unsigned int columnIndex, unsigned int rowIndex) const noexcept
        {
            return m_grayscalePixelArray[columnIndex * rowIndex];
        }

        uint8_t& operator[](unsigned int index1D) noexcept
        {
            return m_grayscalePixelArray[index1D];
        }

        uint8_t& operator()(unsigned int columnIndex, unsigned int rowIndex) noexcept
        {
            return m_grayscalePixelArray[columnIndex * rowIndex];
        }

    };
}

#endif //!HEIGHTMAP_H