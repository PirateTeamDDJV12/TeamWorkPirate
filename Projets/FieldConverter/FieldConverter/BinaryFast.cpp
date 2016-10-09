#include "BinaryFast.h"


using namespace FieldConverter;


bool BinaryFast::operator==(const Binary32& other) const noexcept
{
    return m_byte32.m_firstByte == other.m_firstByte &&
        m_byte32.m_secondByte == other.m_secondByte &&
        m_byte32.m_thirdByte == other.m_thirdByte &&
        m_byte32.m_fourthByte == other.m_fourthByte;
}

void BinaryFast::operator()(char* output) const noexcept
{
    *output = m_byte32.m_firstByte;
    *(output + 1) = m_byte32.m_secondByte;
    *(output + 2) = m_byte32.m_thirdByte;
    *(output + 3) = m_byte32.m_fourthByte;
}