/*
Created by Sun-lay Gagneux
*/
#include "TriangleArray.h"

#include "Triangle.h"


#include <algorithm>


using namespace FieldConverter;


TriangleArray::TriangleArray(size_t widthColumnVertex, size_t heightRowVertex) noexcept
    : m_numberOfColumn{widthColumnVertex - 1}, m_numberOfRow{heightRowVertex - 1}
{
    m_numberOfPolygone = 2 * m_numberOfColumn * m_numberOfRow;

    m_buffer = new Triangle[m_numberOfPolygone];

    fillFast(widthColumnVertex);
}

TriangleArray::TriangleArray(const TriangleArray& other) :
    m_buffer{new Triangle[other.m_numberOfPolygone]},
    m_numberOfPolygone{other.m_numberOfPolygone},
    m_numberOfColumn{other.m_numberOfColumn},
    m_numberOfRow{other.m_numberOfRow}
{
    std::copy(other.begin(), other.end(), m_buffer);
}

TriangleArray::TriangleArray(TriangleArray&& other) :
    m_buffer{other.m_buffer},
    m_numberOfPolygone{other.m_numberOfPolygone},
    m_numberOfColumn{other.m_numberOfColumn},
    m_numberOfRow{other.m_numberOfRow}
{
    other.m_buffer = nullptr;
}

TriangleArray::~TriangleArray() noexcept
{
    delete[] m_buffer;
}


Triangle TriangleArray::at(size_t index) const noexcept
{
    return (*this)[index];
}

Triangle& TriangleArray::at(size_t index) noexcept
{
    return (*this)[index];
}

TriangleArray::iterator TriangleArray::end() noexcept
{
    return (begin() + numberOfPolygone());
}

TriangleArray::const_iterator TriangleArray::end() const noexcept
{
    return (begin() + numberOfPolygone());
}

std::string TriangleArray::toString() const noexcept
{
    std::string intermediary("");

    std::for_each(begin(),
                  end(),
                  [&intermediary, this](const Triangle& triangle) {
        intermediary += triangle.toString();
    }
    );

    return intermediary;
}

void TriangleArray::swap(TriangleArray& other) noexcept
{
    using std::swap;

    swap(m_numberOfRow, other.m_numberOfRow);
    swap(m_numberOfColumn, other.m_numberOfColumn);
    swap(m_numberOfPolygone, other.m_numberOfPolygone);
    swap(m_buffer, other.m_buffer);
}

Triangle& TriangleArray::operator[](size_t index) noexcept
{
    return m_buffer[index];
}

Triangle TriangleArray::operator[](size_t index) const noexcept
{
    return m_buffer[index];
}

TriangleArray& TriangleArray::operator=(const TriangleArray& other)
{
    TriangleArray{other}.swap(*this);

    return *this;
}

TriangleArray& TriangleArray::operator=(TriangleArray&& other)
{
    swap(other);

    return *this;
}



void TriangleArray::fillByTile(const Tile& tile, Triangle& upperTriangle, Triangle& downerTriangle) noexcept
{
    upperTriangle.firstPointIndex() = tile.m_vertexDownLeft;
    upperTriangle.secondPointIndex() = tile.m_vertexUpLeft;
    upperTriangle.thirdPointIndex() = tile.m_vertexUpRight;

    downerTriangle.firstPointIndex() = tile.m_vertexDownLeft;
    downerTriangle.secondPointIndex() = tile.m_vertexUpRight;
    downerTriangle.thirdPointIndex() = tile.m_vertexDownRight;
}

void TriangleArray::fillFast(size_t widthColumnVertex) noexcept
{
    iterator current = begin();
    const_iterator endArray = end();

    unsigned int currentTile = 0;
    size_t jumpMapping = (widthColumnVertex - 2);

    static auto function = [&currentTile, &widthColumnVertex, &jumpMapping, this](Triangle* index) {
        Tile intermediary(currentTile, (currentTile + 1), (currentTile + widthColumnVertex), (currentTile + widthColumnVertex + 1));
        fillByTile(intermediary, *index, *(index + 1));
        currentTile += (((currentTile % widthColumnVertex) == jumpMapping) ? 2 : 1);
    };

    for(; current != endArray; current += 2)
    {
        function(current);
    }
}