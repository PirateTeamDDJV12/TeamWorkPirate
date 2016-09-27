#include "VertexArray.h"
#include "HeightMap.h"
#include "Vect3f.h"
#include <stdlib.h>
using namespace FieldConverter;


VertexArray::VertexArray(const HeightMap& heightmap, float scale)
    :
    m_heightMap{heightmap},
    m_scale{scale},
    m_nbVertices{heightmap.size()}
{
    // Transform the heightmap into a map with index and Vertex
    m_vertexMap = transformToVertexMap();

    // Change all the vertex to remove an useless offset
    offsetVertexMap();

    // Scale all the vertex's zPos to not have 0 to 255 height
    scaleVertexMap();
}

std::map<unsigned, Vertex> VertexArray::transformToVertexMap() const
{
    std::map<unsigned int, Vertex> myVertexMap;
    float row = 0;
    for(int i = 0; i < m_heightMap.size(); i++)
    {
        if(i != 0 && i % m_heightMap.width() == 0)
        {
            row++;
        }
        float col = i - (m_heightMap.width() * row);
        float zPos = static_cast<float>(m_heightMap.at(i));

        myVertexMap.insert(std::pair<unsigned int, Vertex>(i, Vertex(row, col, zPos, 0.0f, 0.0f, 0.0f)));
    }
    return myVertexMap;
}

void VertexArray::scaleVertexMap()
{
    for(int i = 0; i < m_nbVertices; i++)
    {
        m_vertexMap[i].position().z(m_vertexMap[i].position().z() * m_scale);
    }
}

void VertexArray::offsetVertexMap()
{
    /*Looking for smallest z*/
    float min = m_vertexMap[0].position().z();

    for(int i = 1; i < m_nbVertices; i++)
    {
        if(m_vertexMap[i].position().z() < min)
        {
            min = m_vertexMap[i].position().z();
        }
    }
    /*substract min to each z*/
    for(int i = 0; i < m_nbVertices; i++)
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
    //TODO
}
