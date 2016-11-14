#include "VertexArray.h"
#include "HeightMap.h"
#include "Vect3f.h"
#include "Triangle.h"
#include "TriangleArray.h"

#include <stdlib.h>
#include "Config.hpp"
using namespace FieldConverter;


VertexArray::VertexArray(const HeightMap& heightmap, float scale, unsigned int textureRepeat)
    :
    m_heightMap{heightmap},
    m_scale{scale},
    m_nbVertices{heightmap.size()}
{
    // Transform the heightmap into a map with index and Vertex
    m_vertexMap = transformToVertexMap(textureRepeat);

    // Change all the vertex to remove an useless offset
    offsetVertexMap();

    // Scale all the vertex's zPos to not have 0 to 255 height and apply offset if in config
    scaleVertexMap();
}

std::map<unsigned, Vertex> VertexArray::transformToVertexMap(unsigned int textureRepeat) const
{
    std::map<unsigned int, Vertex> myVertexMap;
    float row = 0;
    for(unsigned int i = 0; i < m_heightMap.size(); i++)
    {
        if(i != 0 && i % m_heightMap.width() == 0)
        {
            row++;
        }
        float col = i - (m_heightMap.width() * row);
        float zPos = static_cast<float>(m_heightMap.at(i));

        if(textureRepeat == 0)
        {
            myVertexMap.insert(std::pair<unsigned int, Vertex>(i, Vertex(
                col, row, zPos,
                0.0f, 0.0f, 0.0f,
                col / static_cast<float>(m_heightMap.width()), row / static_cast<float>(m_heightMap.height()))));
        }
        else
        {
            myVertexMap.insert(std::pair<unsigned int, Vertex>(i, Vertex(
                col, row, zPos,
                0.0f, 0.0f, 0.0f,
                col / static_cast<float>(textureRepeat), row / static_cast<float>(textureRepeat))));
        }
    }

    return myVertexMap;
}

void VertexArray::scaleVertexMap()
{
    float offset = Config::getInstance()->getOffset();
    for(unsigned int i = 0; i < m_nbVertices; i++)
    {
        m_vertexMap[i].position().z(m_vertexMap[i].position().z() * m_scale);
        m_vertexMap[i].position().z(m_vertexMap[i].position().z() - offset);
    }
}

void VertexArray::offsetVertexMap()
{
    /*Looking for smallest z*/
    float min = m_vertexMap[0].position().z();

    for(unsigned int i = 1; i < m_nbVertices; i++)
    {
        if(m_vertexMap[i].position().z() < min)
        {
            min = m_vertexMap[i].position().z();
        }
    }
    /*substract min to each z*/
    for(unsigned int i = 0; i < m_nbVertices; i++)
    {
        m_vertexMap[i].position().z(m_vertexMap[i].position().z() - min);
    }
}

std::map<unsigned, Vertex> VertexArray::getVertexMap() const noexcept
{
    return m_vertexMap;
}

void VertexArray::computeNormal(const TriangleArray& mapping) noexcept
{
    for(int i = 0; i < mapping.numberOfPolygone(); i++)
    {
        Vect3f normale = this->computeNormalTriangle(mapping.at(i));


        // Add triangle normal to each vertex

        m_vertexMap[mapping.at(i).firstPointIndex()].normalVector() += normale;
        m_vertexMap[mapping.at(i).secondPointIndex()].normalVector() += normale;
        m_vertexMap[mapping.at(i).thirdPointIndex()].normalVector() += normale;
    }

    for(unsigned int iter = 0; iter < m_nbVertices; iter++)
    {
        m_vertexMap[iter].normalVector() /= m_vertexMap[iter].normalVector().length();
    }
}

Vect3f VertexArray::computeNormalTriangle(const Triangle& triangle) noexcept
{
    Vect3f vect1 = m_vertexMap[triangle.secondPointIndex()].position() - m_vertexMap[triangle.firstPointIndex()].position();
    Vect3f vect2 = m_vertexMap[triangle.thirdPointIndex()].position() - m_vertexMap[triangle.firstPointIndex()].position();

    return vect1.crossProduct(vect2);
}
