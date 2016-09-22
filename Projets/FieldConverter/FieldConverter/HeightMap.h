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
            MIN_HEIGHT = 0,
            MAX_HEIGHT = 255
        };

    private:
        unsigned int m_Width;
        unsigned int m_Height;

        uint8_t* m_grayscalePixelArray;
        

    public:
        HeightMap(const std::string& pathFile);
        HeightMap(const HeightMap& copy);
        HeightMap(HeightMap&& destructiveMovedSample);
        ~HeightMap();


    public:
        uint8_t at(unsigned int index1D) const noexcept
        {
            return m_grayscalePixelArray[index1D];
        }

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


    private:
        void load(const std::string& pathFile);


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