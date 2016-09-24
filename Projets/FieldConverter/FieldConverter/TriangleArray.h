/*
Created by Sun-lay Gagneux
*/
#ifndef TRIANGLEARRAY_H
#define TRIANGLEARRAY_H

#include <string>

namespace FieldConverter
{
    class Triangle;

    namespace UnitaryTest
    {
        class TriangleArrayUnitTest;
    }


    /*
    Triangle array that stores all triangles mapped by indexes to form a plane.
    */
    class TriangleArray
    {
    private:
        friend class UnitaryTest::TriangleArrayUnitTest;


    public:
        using iterator = Triangle*;
        using const_iterator = const Triangle*;


    private:
        struct Tile
        {
            unsigned int m_vertexDownLeft;
            unsigned int m_vertexDownRight;
            unsigned int m_vertexUpLeft;
            unsigned int m_vertexUpRight;

            Tile(unsigned int vertDownLeft, unsigned int vertDownRight, unsigned int vertUpLeft, unsigned int vertUpRight) noexcept :
                m_vertexDownLeft{ vertDownLeft },
                m_vertexDownRight{ vertDownRight },
                m_vertexUpLeft{ vertUpLeft },
                m_vertexUpRight{ vertUpRight }
            {}
        };


    private:
        Triangle* m_buffer;
        size_t m_numberOfPolygone;

        size_t m_numberOfColumn;
        size_t m_numberOfRow;


    public:
        /*
        * widthColumnVertex : Number of vertex in the map width 
        * heightRowVertex : Number of vertex in the map height
        */
        TriangleArray(size_t widthColumnVertex, size_t heightRowVertex) noexcept;
        
        TriangleArray(const TriangleArray& other);
        TriangleArray(TriangleArray&& other);

        ~TriangleArray() noexcept;


    private:
        TriangleArray(Triangle* buffer, size_t numberOfPolygone, size_t numberOfColumn, size_t numberOfRow) noexcept :
            m_numberOfPolygone{ numberOfPolygone },
            m_numberOfColumn{ numberOfColumn },
            m_numberOfRow{ numberOfRow },
            m_buffer{ buffer }
        {}


    public:
        /*
        Get the triangle at the specified index
        */
        Triangle at(size_t index) const noexcept;
        Triangle& at(size_t index) noexcept;

        /*
        Return the total number of polygone (triangle) inside the map
        */
        size_t numberOfPolygone() const noexcept
        {
            return m_numberOfPolygone;
        }

        /*
        Return the number of polygone (triangle) in one row (Nb column * 2)
        */
        size_t numberOfPolygoneInColumn() const noexcept
        {
            return m_numberOfColumn * 2;
        }

        /*
        Return the number of polygone (triangle) in one column (Nb row * 2)
        */
        size_t numberOfPolygoneInRow() const noexcept
        {
            return m_numberOfRow * 2;
        }

        /*
        Return the number of tiles in 1 row
        */
        size_t numberOfTilesInColumn() const noexcept
        {
            return m_numberOfColumn;
        }

        /*
        Return the number of tiles in 1 column
        */
        size_t numberOfTilesInRow() const noexcept
        {
            return m_numberOfRow;
        }

        iterator begin() noexcept
        {
            return m_buffer;
        }

        const_iterator begin() const noexcept
        {
            return m_buffer;
        }

        iterator end() noexcept;
        const_iterator end() const noexcept;

        void swap(TriangleArray& other) noexcept;

        /*
        Return a string containing each triangle in a column
        */
        std::string toString() const noexcept;


    private:
        void fillFast(size_t widthColumnVertex) noexcept;

        void fillByTile(const Tile& tile, Triangle& upperTriangle, Triangle& downerTriangle) noexcept;


    public:
        Triangle& operator[](size_t index) noexcept;
        Triangle operator[](size_t index) const noexcept;

        TriangleArray& operator=(const TriangleArray& other);
        TriangleArray& operator=(TriangleArray&& other);
    };
}

#endif //!TRIANGLEARRAY_H
