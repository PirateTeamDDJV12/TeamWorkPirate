/*
Created by Sun-lay Gagneux
*/
#include "HeightMap.h"

#include "TriangleArray.h"
#include "Triangle.h"
#include "BinaryFast.h"

#include <algorithm>
//#include <numeric>
#include <iterator>
#include <fstream>

using namespace FieldConverter;


HeightMap::HeightMap(const std::string& pathFile) :
    m_width{DEFAULT_HEIGHTMAP_IMAGE_WIDTH},
    m_height{DEFAULT_HEIGHTMAP_IMAGE_HEIGHT}
{
    m_totalSize = m_width * m_height;

    m_grayscalePixelArray = new uint8_t[m_totalSize];

    load(pathFile);
}

HeightMap::HeightMap(const HeightMap& copy):
    m_width{ DEFAULT_HEIGHTMAP_IMAGE_WIDTH },
    m_height{ DEFAULT_HEIGHTMAP_IMAGE_HEIGHT },
    m_grayscalePixelArray{ new uint8_t[DEFAULT_HEIGHTMAP_IMAGE_WIDTH * DEFAULT_HEIGHTMAP_IMAGE_HEIGHT] }
{
    m_totalSize = m_width * m_height;

    std::copy(copy.begin(), copy.end(), m_grayscalePixelArray);
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
    (HeightMap{other}).swap(*this);

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

    ifstream reader(pathFile, ios::binary);

    if(reader.bad() || reader.eof())
    {
        throw ErrorLoadingHeightMap{};
    }

    //size_t iter = 0;

    /*std::for_each(
        begin(),
        end(),
        [&](unsigned int) {
            reader. >> m_grayscalePixelArray[iter];
            iter++;
        }
    );*/

    reader.read(reinterpret_cast<char*>(m_grayscalePixelArray), size());
}

void HeightMap::swap(HeightMap& autre) noexcept
{
    using std::swap;

    swap(m_width, autre.m_width);
    swap(m_height, autre.m_height);
    swap(m_totalSize, autre.m_totalSize);
    swap(m_grayscalePixelArray, autre.m_grayscalePixelArray);
}

void HeightMap::writeIntoOutputFile(const std::string& fileName, const std::map<unsigned int, Vertex>& vertexMap, const TriangleArray& triangleArray) const noexcept
{
    // Execution time : 40s ... But, TP06... Ouch !  :p
    //std::string toWrite(std::accumulate(
    //                        vertexMap.begin(),
    //                        vertexMap.end(),
    //                        std::string(""),
    //                        [](const std::string& accumulated, const std::pair<unsigned int, Vertex>& indexedVertex) {
    //                            return (accumulated + std::to_string(indexedVertex.first) + " " + indexedVertex.second.toString());
    //                        }
    //                    )
    //);
    
    
    //Execution time : 15s ...  
    std::string toWrite("");
    std::for_each(vertexMap.begin(),
                  vertexMap.end(),
                  [&toWrite](const std::pair<unsigned int, Vertex>& indexedVertex) {
                      toWrite += std::to_string(indexedVertex.first) + " " + indexedVertex.second.toString();
                  }
    );

    toWrite += ("\n" + triangleArray.toString());

    std::ofstream{ fileName }.write(toWrite.c_str(), toWrite.size());
}

void HeightMap::writeBinaryIntoOutputFile(const std::string& fileName, const std::map<unsigned int, Vertex>& vertexMap, const TriangleArray& triangleArray) const noexcept
{
    std::ofstream outputFile{ fileName, std::ios::binary };

    size_t totSize = 4 + vertexMap.size() * (sizeof(Vertex) + 4) + triangleArray.numberOfPolygone() * sizeof(Triangle);

    char* toWrite = new char[totSize];

    BinaryFast binIntermediary{ static_cast<uint32_t>(vertexMap.size()) };
    size_t iter = 0;
    
    binIntermediary.put<BinaryFast::Save>(toWrite, iter);
    iter += 4;

    std::for_each(vertexMap.begin(),
                  vertexMap.end(),
                  [&toWrite, &iter, &binIntermediary](std::pair<unsigned int, Vertex> vert) {
                        binIntermediary(vert.first, toWrite, iter);
                        binIntermediary(vert.second.position().x(), toWrite, iter);
                        binIntermediary(vert.second.position().y(), toWrite, iter);
                        binIntermediary(vert.second.position().z(), toWrite, iter);
                        binIntermediary(vert.second.normalVector().x(), toWrite, iter);
                        binIntermediary(vert.second.normalVector().y(), toWrite, iter);
                        binIntermediary(vert.second.normalVector().z(), toWrite, iter);
                  }
    );

    std::for_each(triangleArray.begin(),
                  triangleArray.end(),
                  [&toWrite, &iter, &binIntermediary](Triangle triangle) {
                        binIntermediary(triangle.firstPointIndex(), toWrite, iter);
                        binIntermediary(triangle.secondPointIndex(), toWrite, iter);
                        binIntermediary(triangle.thirdPointIndex(), toWrite, iter);
                  }
    );

    std::copy(toWrite, toWrite + totSize, std::ostreambuf_iterator<char>{std::ofstream{ fileName, std::ios::binary }});
}
