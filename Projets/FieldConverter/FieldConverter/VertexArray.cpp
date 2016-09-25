#include "VertexArray.h"
#include "HeightMap.h"
#include "Vect3f.h"
#include <stdlib.h>
using namespace FieldConverter;



VertexArray::VertexArray(const HeightMap& heightmap, float scale) : m_scale{ scale }, m_heightMap{ heightmap }, m_nbVertices{ heightmap.size() }
{
    for (int i = 0; i < m_nbVertices; i++)
    {   //on récupère la position des points
        Vect3f pos = Vect3f(i%HeightMap::DEFAULT_HEIGHTMAP_IMAGE_WIDTH,
            div(i, HeightMap::DEFAULT_HEIGHTMAP_IMAGE_HEIGHT).quot, 
            heightmap.at(i));
        // On calcule la normale de chaque point (pas fait, pour l'instant 0,0,1)
        
        m_vertices.push_back(Vertex(pos.x(),pos.y(),pos.z(),1,1,0));
    }
    VertexArray::offset();
    VertexArray::scale();
}

void VertexArray::scale()
{
    for (int i = 0; i < m_nbVertices; i++)
    {   
        m_vertices[i].position().z(m_vertices[i].position().z() * m_scale);
    }
}

void VertexArray::offset()
{
    float min = m_vertices[0].position().z();

    for (int i = 1; i < m_nbVertices; i++)
    {
        if (m_vertices[i].position().z() < min)
        {
            min = m_vertices[i].position().z();
        }
    }

    for (int i = 0; i < m_nbVertices; i++)
    {
        m_vertices[i].position().z(m_vertices[i].position().z() - min);
    }
}

std::vector<Vertex> VertexArray::getArray() const noexcept
{
    return m_vertices;
}

void VertexArray::computeNormal(const TriangleArray& mapping) noexcept
{
    //TODO
}
