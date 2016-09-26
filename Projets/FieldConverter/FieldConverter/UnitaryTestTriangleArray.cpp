#include "UnitaryTestTriangleArray.h"

#include "Triangle.h"

#include <algorithm>


using namespace FieldConverter;
using namespace UnitaryTest;


TriangleArrayUnitTest TriangleArrayUnitTest::m_testerInstance(3);
bool TriangleArrayUnitTest::m_throw = false;


TriangleArrayUnitTest::TriangleArrayUnitTest(size_t numberOfVertexInColumn) noexcept :
    m_result{ "\n**********\nTesting Triangle Array Now : \n" },
    m_array{ (numberOfVertexInColumn == 4) ? getAnswerTriangle44() : getAnswerTriangle55(),
        (numberOfVertexInColumn - 1) * (numberOfVertexInColumn - 1) * 2,
        (numberOfVertexInColumn - 1),
        (numberOfVertexInColumn - 1)
    }
{}

Triangle* TriangleArrayUnitTest::getAnswerTriangle44() const
{
    Triangle* triangleBuffer = new Triangle[18];

    fillTriangleBuffer(triangleBuffer[0],   0,  4,  5   );
    fillTriangleBuffer(triangleBuffer[1],   0,  5,  1   );
    fillTriangleBuffer(triangleBuffer[2],   1,  5,  6   );
    fillTriangleBuffer(triangleBuffer[3],   1,  6,  2   );
    fillTriangleBuffer(triangleBuffer[4],   2,  6,  7   );
    fillTriangleBuffer(triangleBuffer[5],   2,  7,  3   );
    fillTriangleBuffer(triangleBuffer[6],   4,  8,  9   );
    fillTriangleBuffer(triangleBuffer[7],   4,  9,  5   );
    fillTriangleBuffer(triangleBuffer[8],   5,  9,  10  );
    fillTriangleBuffer(triangleBuffer[9],   5,  10, 6   );
    fillTriangleBuffer(triangleBuffer[10],  6,  10, 11  );
    fillTriangleBuffer(triangleBuffer[11],  6,  11, 7   );
    fillTriangleBuffer(triangleBuffer[12],  8,  12, 13  );
    fillTriangleBuffer(triangleBuffer[13],  8,  13, 9   );
    fillTriangleBuffer(triangleBuffer[14],  9,  13, 14  );
    fillTriangleBuffer(triangleBuffer[15],  9,  14, 10  );
    fillTriangleBuffer(triangleBuffer[16],  10, 14, 15  );
    fillTriangleBuffer(triangleBuffer[17],  10, 15, 11  );

    return triangleBuffer;
}

Triangle* TriangleArrayUnitTest::getAnswerTriangle55() const
{
    Triangle* triangleBuffer = new Triangle[32];

    fillTriangleBuffer(triangleBuffer[0],   0,   5,   6    );
    fillTriangleBuffer(triangleBuffer[1],   0,   6,   1    );
    fillTriangleBuffer(triangleBuffer[2],   1,   6,   7    );
    fillTriangleBuffer(triangleBuffer[3],   1,   7,   2    );
    fillTriangleBuffer(triangleBuffer[4],   2,   7,   8    );
    fillTriangleBuffer(triangleBuffer[5],   2,   8,   3    );
    fillTriangleBuffer(triangleBuffer[6],   3,   8,   9    );
    fillTriangleBuffer(triangleBuffer[7],   3,   9,   4    );
    fillTriangleBuffer(triangleBuffer[8],   5,   10,  11   );
    fillTriangleBuffer(triangleBuffer[9],   5,   11,  6    );
    fillTriangleBuffer(triangleBuffer[10],  6,   11,  12   );
    fillTriangleBuffer(triangleBuffer[11],  6,   12,  7    );
    fillTriangleBuffer(triangleBuffer[12],  7,   12,  13   );
    fillTriangleBuffer(triangleBuffer[13],  7,   13,  8    );
    fillTriangleBuffer(triangleBuffer[14],  8,   13,  14   );
    fillTriangleBuffer(triangleBuffer[15],  8,   14,  9    );
    fillTriangleBuffer(triangleBuffer[16],  10,  15,  16   );
    fillTriangleBuffer(triangleBuffer[17],  10,  16,  11   );
    fillTriangleBuffer(triangleBuffer[18],  11,  16,  17   );
    fillTriangleBuffer(triangleBuffer[19],  11,  17,  12   );
    fillTriangleBuffer(triangleBuffer[20],  12,  17,  18   );
    fillTriangleBuffer(triangleBuffer[21],  12,  18,  13   );
    fillTriangleBuffer(triangleBuffer[22],  13,  18,  19   );
    fillTriangleBuffer(triangleBuffer[23],  13,  19,  14   );
    fillTriangleBuffer(triangleBuffer[24],  15,  20,  21   );
    fillTriangleBuffer(triangleBuffer[25],  15,  21,  16   );
    fillTriangleBuffer(triangleBuffer[26],  16,  21,  22   );
    fillTriangleBuffer(triangleBuffer[27],  16,  22,  17   );
    fillTriangleBuffer(triangleBuffer[28],  17,  22,  23   );
    fillTriangleBuffer(triangleBuffer[29],  17,  23,  18   );
    fillTriangleBuffer(triangleBuffer[30],  18,  23,  24   );
    fillTriangleBuffer(triangleBuffer[31],  18,  24,  19   );

    return triangleBuffer;
}

void TriangleArrayUnitTest::fillTriangleBuffer(Triangle& toFill, unsigned int indexP1, unsigned int indexP2, unsigned int indexP3) const
{
    toFill.firstPointIndex() = indexP1;
    toFill.secondPointIndex() = indexP2;
    toFill.thirdPointIndex() = indexP3;
}

void TriangleArrayUnitTest::run()
{
    TriangleArrayUnitTest::m_testerInstance = TriangleArrayUnitTest(4);

    m_testerInstance.result() += "\nArray 4 Vertex x 4 Vertex : \n";

    TriangleArray sample(4, 4);

    m_testerInstance.runCheckPolygoneNumber(sample, m_testerInstance.result());
    m_testerInstance.runCheckPolygoneInWidth(sample, m_testerInstance.result());
    m_testerInstance.runCheckPolygoneInHeight(sample, m_testerInstance.result());
    m_testerInstance.runCheckTilesInHeight(sample, m_testerInstance.result());
    m_testerInstance.runCheckTilesInWidth(sample, m_testerInstance.result());
    m_testerInstance.runCheckArray(sample, m_testerInstance.result());


    m_testerInstance.result() += "\n\nArray 5 Vertex x 5 Vertex : \n";

    TriangleArrayUnitTest::m_testerInstance = TriangleArrayUnitTest(5);

    sample = TriangleArray(5, 5);

    m_testerInstance.runCheckPolygoneNumber(sample, m_testerInstance.result());
    m_testerInstance.runCheckPolygoneInWidth(sample, m_testerInstance.result());
    m_testerInstance.runCheckPolygoneInHeight(sample, m_testerInstance.result());
    m_testerInstance.runCheckTilesInHeight(sample, m_testerInstance.result());
    m_testerInstance.runCheckTilesInWidth(sample, m_testerInstance.result());
    m_testerInstance.runCheckArray(sample, m_testerInstance.result());


    m_testerInstance.result() += "*********** END Triangle array unit test *************\n\n";
}

void TriangleArrayUnitTest::runCheckArray(const TriangleArray& triangleSample, std::string& resultTesting)
{
    resultTesting += "Test value mapping = [RUN] \n\t\t\t";
    bool mustThrow = false;

    for (size_t index = 0; index < triangleSample.numberOfPolygone(); index++)
    {
        if (triangleSample[index] != m_testerInstance.m_array[index])
        {
            resultTesting += ("[FAILED] = Problem at Triangle nb " 
                              + std::to_string(index)
                              + " Indexes are : ("
                              + std::to_string(triangleSample[index].firstPointIndex())
                              +", "
                              + std::to_string(triangleSample[index].secondPointIndex())
                              + ", "
                              + std::to_string(triangleSample[index].thirdPointIndex())
                              + ") instead of : ("
                              + std::to_string(TriangleArrayUnitTest::m_testerInstance.arrayAnswer()[index].firstPointIndex())
                              + ", "
                              + std::to_string(TriangleArrayUnitTest::m_testerInstance.arrayAnswer()[index].secondPointIndex())
                              + ", "
                              + std::to_string(TriangleArrayUnitTest::m_testerInstance.arrayAnswer()[index].thirdPointIndex())
                              + ")\n\t\t\t");

            mustThrow = true;
        }
    }

    if (mustThrow)
    {
        if (m_throw)
        {
            throw ProblemMappingArray{};
        }
    }
    else
    {
        resultTesting += "[SUCCESS]\n";
    }
}

void TriangleArrayUnitTest::runCheckPolygoneNumber(const TriangleArray& triangleSample, std::string& resultTesting)
{
    resultTesting += "Test number of polygones = [RUN] \n\t\t\t";

    if (triangleSample.numberOfPolygone() == TriangleArrayUnitTest::m_testerInstance.arrayAnswer().numberOfPolygone())
    {
        resultTesting += "[SUCCESS]\n";
    }
    else
    {
        resultTesting += "[FAILED] : Number of polygone is : "
            + std::to_string(triangleSample.numberOfPolygone())
            + " instead of : "
            + std::to_string(TriangleArrayUnitTest::m_testerInstance.arrayAnswer().numberOfPolygone())
            + "\n";

        if (m_throw)
        {
            throw ProblemPolygoneNumber{};
        }
    }
}

void TriangleArrayUnitTest::runCheckPolygoneInWidth(const TriangleArray& triangleSample, std::string& resultTesting)
{
    resultTesting += "Test number of polygones in column = [RUN] \n\t\t\t";

    if (triangleSample.numberOfPolygoneInColumn() == TriangleArrayUnitTest::m_testerInstance.arrayAnswer().numberOfPolygoneInColumn())
    {
        resultTesting += "[SUCCESS]\n";
    }
    else
    {
        resultTesting += "[FAILED] : Number of polygone in column is : "
            + std::to_string(triangleSample.numberOfPolygoneInColumn())
            + " instead of : "
            + std::to_string(TriangleArrayUnitTest::m_testerInstance.arrayAnswer().numberOfPolygoneInColumn())
            + "\n";

        if (m_throw)
        {
            throw ProblemPolygoneInWidth{};
        }
    }
}

void TriangleArrayUnitTest::runCheckPolygoneInHeight(const TriangleArray& triangleSample, std::string& resultTesting)
{
    resultTesting += "Test number of polygones in row = [RUN] \n\t\t\t";

    if (triangleSample.numberOfPolygoneInRow() == TriangleArrayUnitTest::m_testerInstance.arrayAnswer().numberOfPolygoneInRow())
    {
        resultTesting += "[SUCCESS]\n";
    }
    else
    {
        resultTesting += "[FAILED] : Number of polygone in row is : "
            + std::to_string(triangleSample.numberOfPolygoneInRow())
            + " instead of : "
            + std::to_string(TriangleArrayUnitTest::m_testerInstance.arrayAnswer().numberOfPolygoneInRow())
            + "\n";

        if (m_throw)
        {
            throw ProblemPolygoneInHeight{};
        }
    }
}

void TriangleArrayUnitTest::runCheckTilesInHeight(const TriangleArray& triangleSample, std::string& resultTesting)
{
    resultTesting += "Test number of tiles in row = [RUN] \n\t\t\t";

    if (triangleSample.numberOfTilesInRow() == TriangleArrayUnitTest::m_testerInstance.arrayAnswer().numberOfTilesInRow())
    {
        resultTesting += "[SUCCESS]\n";
    }
    else
    {
        resultTesting += "[FAILED] : Number of tiles in row is : "
            + std::to_string(triangleSample.numberOfTilesInRow())
            + " instead of : "
            + std::to_string(TriangleArrayUnitTest::m_testerInstance.arrayAnswer().numberOfTilesInRow())
            + "\n";

        if (m_throw)
        {
            throw ProblemTilesInHeight{};
        }
    }
}

void TriangleArrayUnitTest::runCheckTilesInWidth(const TriangleArray& triangleSample, std::string& resultTesting)
{
    resultTesting += "Test number of tiles in column = [RUN] \n\t\t\t";

    if (triangleSample.numberOfTilesInColumn() == TriangleArrayUnitTest::m_testerInstance.arrayAnswer().numberOfTilesInColumn())
    {
        resultTesting += "[SUCCESS]\n";
    }
    else
    {
        resultTesting += "[FAILED] : Number of tiles in column is : "
            + std::to_string(triangleSample.numberOfTilesInColumn())
            + " instead of : "
            + std::to_string(TriangleArrayUnitTest::m_testerInstance.arrayAnswer().numberOfTilesInColumn())
            + "\n";

        if (m_throw)
        {
            throw ProblemTilesInWidth{};
        }
    }
}

TriangleArrayUnitTest& TriangleArrayUnitTest::operator=(TriangleArrayUnitTest&& otherDead)
{
    using std::swap;

    swap(m_array, otherDead.m_array);

    return *this;
}