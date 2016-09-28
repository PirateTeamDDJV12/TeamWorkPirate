#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include <map>

namespace FieldConverter
{
    class TriangleArray;
    class Vertex;
    class HeightMap;

    class VertexArray
    {
    private:
        std::map<unsigned int, Vertex> m_vertexMap;
        const HeightMap&  m_heightMap;
        float m_scale;
        unsigned int m_nbVertices;

    public:
        VertexArray(const HeightMap& heightmap, float scale);

        ~VertexArray()
        {
            m_vertexMap.clear();
        }

        /*Return the map of Vertex with their index*/
        std::map<unsigned, Vertex> getVertexMap() const noexcept;

        void computeNormal(const TriangleArray& mapping) noexcept;

    private:
        /*
        Transform the actual Heightmap in a map with an index and a Vertex
        We use this function to create all the Vertex of the Heightmap and their index
        */
        std::map<unsigned int, Vertex> transformToVertexMap() const;

        /*Rescale z data*/
        void scaleVertexMap();

        /*Put smallest z to 0*/
        void offsetVertexMap();
    };
}
#endif //VERTEXARRAY_H