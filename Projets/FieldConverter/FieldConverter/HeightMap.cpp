/*
Created by Sun-lay Gagneux
*/
#include "HeightMap.h"

#include <fstream>

using namespace FieldConverter;


HeightMap::HeightMap(const std::string& pathFile) : 
    m_width{DEFAULT_WIDTH},
    m_height{DEFAULT_HEIGHT}
{
    m_totalSize = m_width * m_height;

    m_grayscalePixelArray = new uint8_t[m_totalSize];
    std::fill(begin(), end(), MIN_HEIGHT);
    
    load(pathFile);
}

HeightMap::HeightMap(const HeightMap& copy)
{
    std::copy(begin(), end(), begin());
}

HeightMap::HeightMap(HeightMap&& destructiveMovedSample) noexcept:
    m_height{destructiveMovedSample.height()},
    m_width{destructiveMovedSample.width()},
    m_totalSize{destructiveMovedSample.size()},
    m_grayscalePixelArray{destructiveMovedSample.m_grayscalePixelArray}
{
    destructiveMovedSample.m_grayscalePixelArray = nullptr;
}

HeightMap& HeightMap::operator=(const HeightMap& other)
{
    (HeightMap{ other }).swap(*this);

    return *this;
}

HeightMap& HeightMap::operator=(HeightMap&& destructiveMovedSample)
{
    swap(destructiveMovedSample);

    return *this;
}

void HeightMap::load(const std::string& pathFile)
{
    using std::ifstream;
    using std::istreambuf_iterator;
    using std::ios;
    using std::copy;
    
    ifstream reader(pathFile);

    copy(istreambuf_iterator<char>{ifstream{ "in.txt", ios::binary }}, 
         istreambuf_iterator<char>{}, 
         [this](int iter) {
            return (m_grayscalePixelArray + iter);
         }
    );
}

void HeightMap::swap(HeightMap& autre) noexcept// permutter les état de this avec ceux de autre
{
    using std::swap;

    swap(m_width, autre.m_width);
    swap(m_height, autre.m_height);
    swap(m_totalSize, autre.m_totalSize);
    swap(m_grayscalePixelArray, autre.m_grayscalePixelArray);
}