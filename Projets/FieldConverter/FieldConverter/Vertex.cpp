/*
Created by Sun-lay gagneux
*/
#include "Vertex.h"


using namespace FieldConverter;


void Vertex::writeVectIntoStdString(std::stringstream& container, const Vect3f& valueToWrite) const noexcept
{
    container << this->position().x() << SPACE_SEPARATOR;
    container << this->position().y() << SPACE_SEPARATOR;
    container << this->position().z();
}

std::string Vertex::toString() const noexcept
{
    std::stringstream intermediaryStr;

    writeVectIntoStdString(intermediaryStr, position());
    intermediaryStr << SPACE_SEPARATOR;

    writeVectIntoStdString(intermediaryStr, normalVector());
    intermediaryStr << LINE_JUMP_SEPARATOR;

    return intermediaryStr.str();
}
