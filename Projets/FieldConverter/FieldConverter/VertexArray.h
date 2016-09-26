#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "Vertex.h"
#include <vector>

namespace FieldConverter
{
    class TriangleArray;
    class HeightMap;

    class VertexArray
    {
    private:
        const HeightMap&  m_heightMap;
        float m_scale;
        unsigned int m_nbVertices;
        std::vector<Vertex> m_vertices;

    public:
        VertexArray(const HeightMap& heightmap, float scale);

        ~VertexArray()
        {
            m_vertices.clear();
        }

        /*Return list or Vertices*/
        std::vector<Vertex> getArray() const noexcept;


        void computeNormal(const TriangleArray& mapping) noexcept;

    private:
        /*Rescale z data*/
        void scale();


        /*Put smallest z to 0*/
        void offset();
    };
}
#endif //VERTEXARRAY_H