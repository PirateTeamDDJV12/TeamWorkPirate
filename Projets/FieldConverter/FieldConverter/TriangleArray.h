/*
Created by Sun-lay Gagneux
*/
#ifndef TRIANGLEARRAY_H
#define TRIANGLEARRAY_H

#include <string>

namespace FieldConverter
{
    class Triangle;

    class TriangleArray
    {
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
        TriangleArray(unsigned int widthColumnVertex, unsigned int heightRowVertex) noexcept;
        
        TriangleArray(const TriangleArray& other);
        TriangleArray(TriangleArray&& other);

        ~TriangleArray() noexcept;


    public:
        Triangle at(size_t index) const noexcept;
        Triangle& at(size_t index) noexcept;

        size_t numberOfPolygone() const noexcept
        {
            return m_numberOfPolygone;
        }

        size_t numberOfPolygoneInColumn() const noexcept
        {
            return m_numberOfColumn * 2;
        }

        size_t numberOfPolygoneInRow() const noexcept
        {
            return m_numberOfRow * 2;
        }

        size_t numberOfTilesInColumn() const noexcept
        {
            return m_numberOfColumn;
        }

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

        std::string toString() const noexcept;


    private:
        void fillFast(unsigned int widthColumnVertex, unsigned int heightRowVertex) noexcept;

        void fillByTile(const Tile& tile, Triangle& upperTriangle, Triangle& downerTriangle) noexcept;

    public:
        Triangle& operator[](size_t index) noexcept;
        Triangle operator[](size_t index) const noexcept;

        TriangleArray& operator=(const TriangleArray& other);
        TriangleArray& operator=(TriangleArray&& other);
    };
}

#endif //!TRIANGLEARRAY_H
