#include "VertexArray.h"
#include <vector>
using namespace FieldConverter;

void VertexArray::scale()
{
    for (int i = 0; i < m_nbVertices; i++)
    {   //if (i%3==2)
        m_vertices[i] = m_vertices[i] * m_scale;
    }
          


}
void VertexArray::offset()
{
    //Looking for Vertex with smallest Z
    float min = m_vertices[2];
    int indice_min = 0;
    for (int i = 1;i < m_nbVertices/3;i++)
    {
        if (m_vertices[i] < min )//&& i%3==2)
        {
            min = m_vertices[i];
            indice_min = i;
        }
    }
    for (int i = 0;i < m_nbVertices;i++)
    {
      //  if (i % 3 == 2)
        {
            m_vertices[i] = m_vertices[i] - min;
        }
    }
}
    std::vector<float> VertexArray::getArray()
    {
        
        offset();
        scale();
        return m_vertices;

    }
