#include "VertexArray.h"
using namespace FieldConverter;

void VertexArray::scale()
{
    for (int i = 0; i < m_nbVertices; i++)
    {
        m_vertices[i][3] = m_vertices[i][3] * m_scale;
    }
          
    
}
void VertexArray::offset()
{
    //Rechercher le minimum sur z.
    float min = m_vertices[0][3];
    int indice_min = 0;
    for (int i = 1;i < m_nbVertices;i++)
    {
         if (m_vertices[i][3] < min)
            {
                min = m_vertices[i][3];
                indice_min = i;
            }
    }
    for (int i = 0;i < m_nbVertices;i++)
    {
        m_vertices[i][3] = m_vertices[i][3] - min;
    }

    auto getArray()
    {
        
        offset(m_nbVertices);
        scale(m_nbVertices);
        return m_nbVertices;
    }
}