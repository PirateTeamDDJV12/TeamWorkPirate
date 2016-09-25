#include "VertexArray.h"
#include "HeightMap.h"
#include "Vertex.h"
#include "Vect3f.h"
#include <vector>
#include <stdlib.h>
using namespace FieldConverter;



VertexArray::VertexArray(HeightMap heightmap, float scale) : m_scale{ scale }, m_heightMap{ heightmap }, m_nbVertices{ heightmap.size() }
{
    for (int i = 0; i < m_nbVertices; i++)
    {
        Vect3f pos = new Vect3f(i%HeightMap::DEFAULT_HEIGHTMAP_IMAGE_WIDTH,div(i,HeightMap::DEFAULT_HEIGHTMAP_IMAGE_HEIGHT).quot+1,heightmap.at(i));

        m_vertices.push_back(new Vertex);
    }
    VertexArray::offset();
    VertexArray::scale();
}
    void VertexArray::scale()
{
    for (int i = 0; i < m_nbVertices; i++)
    {   
        m_vertices[i] = m_vertices[i] * m_scale;
    }
}

void VertexArray::offset()
{
    for (int i = 0;i < m_nbVertices;i++)
     {   
         m_vertices[i][3] = m_vertices[i][3] - HeightMap::MIN_Z_HEIGHT;
     }
}

    std::vector<float[3]> VertexArray::getArray() const noexcept
{
    return m_vertices;
}
