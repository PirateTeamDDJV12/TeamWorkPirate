#pragma once
#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H
#include "HeightMap.h"
#include "Vertex.h"
#include <cstdint>

//#include <string>
//#include <memory.h>
namespace FieldConverter
{
    class VertexArray
    {
    private:
        HeightMap  m_heightMap;
        int m_scale;
        int m_nbVertices;
        int* m_vertices[3];
    public:
        VertexArray(HeightMap heightmap, int scale) :m_scale{ scale }, m_heightMap{ heightmap }, m_nbVertices{heightmap.size()/3}
        {
            for (int i = 0; i < 2; i++)
            {
                m_vertices[i] = new int[m_nbVertices];
            }
        }

        auto getArray();


    private:
        void scale();
        void offset();
    };
}

#endif //VERTEXARRAY_H