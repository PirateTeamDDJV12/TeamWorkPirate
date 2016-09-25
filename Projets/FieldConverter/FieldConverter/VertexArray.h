#pragma once
#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H
#include "HeightMap.h"
#include "Vertex.h"
#include <cstdint>
#include <vector>
//#include <string>
//#include <memory.h>
namespace FieldConverter
{
    class VertexArray
    {
    private:
        HeightMap  m_heightMap;
        float m_scale;
        int m_nbVertices;
        std::vector<float> m_vertices;
    public:

        VertexArray(HeightMap heightmap, float scale) :m_scale{ scale }, m_heightMap{ heightmap }, m_nbVertices{static_cast<int>(heightmap.size())}
        {
                       for (int i = 0; i < m_nbVertices; i++)
            {
                m_vertices.push_back(heightmap.at(i));
            }
        }

        ~VertexArray()
        {
            m_vertices.clear();
        }

        /*Return list or Vertices after scaling*/
        std::vector<float> getArray();


    private:
        /*Rescale z data*/
        void scale();

        /*Put smallest z to 0*/
        void offset();
    };
}

#endif //VERTEXARRAY_H