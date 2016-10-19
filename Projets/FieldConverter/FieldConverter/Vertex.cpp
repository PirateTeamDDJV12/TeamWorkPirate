/*
Created by Sun-lay gagneux
*/
#include "Vertex.h"


using namespace FieldConverter;


void Vertex::writeVectIntoStdString(std::stringstream& container, const Vect3f& valueToWrite) const noexcept
{
    container << valueToWrite.x() << ' ';
    container << valueToWrite.y() << ' ';
    container << valueToWrite.z();
}

std::string Vertex::toString() const noexcept
{
    std::stringstream intermediaryStr;

    writeVectIntoStdString(intermediaryStr, position());
    intermediaryStr << ' ';

    writeVectIntoStdString(intermediaryStr, normalVector());
    intermediaryStr << '\n';

    return intermediaryStr.str();
}
