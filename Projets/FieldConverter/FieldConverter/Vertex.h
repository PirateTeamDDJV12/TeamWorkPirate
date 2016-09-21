#ifndef VERTEX_H
#define VERTEX_H


#include <string>
#include <sstream>


namespace FieldConverter
{
    struct Vect3f
    {
    private:
        float m_X;
        float m_Y;
        float m_Z;

    public:
        Vect3f() noexcept :
            m_X{},
            m_Y{},
            m_Z{}
        {}

        Vect3f(float x, float y) noexcept :
            m_X{x},
            m_Y{y},
            m_Z{}
        {}

        Vect3f(float x, float y, float z) noexcept :
            m_X{x},
            m_Y{y},
            m_Z{z}
        {}

    public:
        float x() const noexcept
        {
            return m_X;
        }

        float y() const noexcept
        {
            return m_Y;
        }

        float z() const noexcept
        {
            return m_Z;
        }

        void x(float newValue) noexcept
        {
            m_X = newValue;
        }

        void y(float newValue) noexcept
        {
            m_Y = newValue;
        }

        void z(float newValue) noexcept
        {
            m_Z = newValue;
        }

        
    public:
        bool operator==(const Vect3f& other) const noexcept
        {
            return ((x() == other.x()) && (y() == other.y()) && (z() == other.z()));
        }

        bool operator!=(const Vect3f& other) const noexcept
        {
            return !(*this == other);
        }
    };


    class Vertex
    {
    private:
        const char SPACE_SEPARATOR = ' ';
        const char LINE_JUMP_SEPARATOR = '\n';


    private:
        Vect3f m_position;
        Vect3f m_normal;


    public:
        Vertex() noexcept : 
            m_position{},
            m_normal{}
        {}

        Vertex(float xPos, float yPos, float zPos, float xNormal, float yNormal, float zNormal) noexcept :
            m_position{xPos, yPos, zPos},
            m_normal{xNormal, yNormal, zNormal}
        {}


    public:
        Vect3f& position() noexcept
        {
            return m_position;
        }

        Vect3f& normalVector() noexcept
        {
            return m_normal;
        }

        Vect3f position() const noexcept
        {
            return m_position;
        }

        Vect3f normalVector() const noexcept
        {
            return m_normal;
        }

        /*
        * Method that returns a std::string that looks like : posX posY posZ normalX normalY normalZ\n
        */
        std::string toString() const noexcept;


    private:
        void writeVectIntoStdString(std::stringstream& container, const Vect3f& valueToWrite) const noexcept;


    public:
        bool operator==(const Vertex& other) const noexcept
        {
            return (position() == other.position() && normalVector() == other.normalVector());
        }

        bool operator!=(const Vertex& other) const noexcept
        {
            return !(*this == other);
        }
    };
}


#endif //!VERTEX_H