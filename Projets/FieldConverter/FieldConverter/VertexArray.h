#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H
#include "HeightMap.h"
#include "Vertex.h"
#include <vector>

namespace FieldConverter
{
    class VertexArray
    {
    private:
        HeightMap  m_heightMap;
        float m_scale;
        unsigned int m_nbVertices;
        std::vector<Vertex> m_vertices;
    public:
        VertexArray(HeightMap heightmap, float scale);

        ~VertexArray()
        {
            m_vertices.clear();
        }

        /*Return list or Vertices*/
        std::vector<Vertex> getArray() const noexcept;


    private:
        /*Rescale z data*/
        void scale();


        /*Put smallest z to 0*/
        void offset();
    };
}
#endif //VERTEXARRAY_H