#include "stdafx.h"
#include "CppUnitTest.h"

#include "../FieldConverter/Triangle.h"
#include "../FieldConverter/TriangleArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace FieldConverter;

namespace FieldConverterTest
{
    TEST_CLASS(TriangleArrayTests)
    {
    public:

        TEST_METHOD(triangleArrayAtTest)
        {
            TriangleArray ta(2, 2);
            Assert::IsTrue(Triangle(0, 2, 3) == ta.at(0));
            Assert::IsTrue(Triangle(0, 3, 1) == ta.at(1));
        }

        TEST_METHOD(triangleArrayNumberOfPolygoneTest)
        {
            TriangleArray ta1(2, 2);
            TriangleArray ta2(257, 257);
            Assert::IsTrue(2 == ta1.numberOfPolygone());
            Assert::IsTrue(131072 == ta2.numberOfPolygone());
        }

        TEST_METHOD(triangleArrayNumberOfPolygoneInColumnTest)
        {
            TriangleArray ta1(2, 2);
            TriangleArray ta2(257, 257);
            Assert::IsTrue(2 == ta1.numberOfPolygoneInColumn());
            Assert::IsTrue(512 == ta2.numberOfPolygoneInColumn());
        }

        TEST_METHOD(triangleArrayNumberOfPolygoneInRowTest)
        {
            TriangleArray ta1(2, 2);
            TriangleArray ta2(257, 257);
            Assert::IsTrue(2 == ta1.numberOfPolygoneInRow());
            Assert::IsTrue(512 == ta2.numberOfPolygoneInRow());
        }

        TEST_METHOD(triangleArrayNumberOfTilesInColumnTest)
        {
            TriangleArray ta1(2, 2);
            TriangleArray ta2(257, 257);
            Assert::IsTrue(1 == ta1.numberOfTilesInColumn());
            Assert::IsTrue(256 == ta2.numberOfTilesInColumn());
        }

        TEST_METHOD(triangleArrayNumberOfTilesInRowTest)
        {
            TriangleArray ta1(2, 2);
            TriangleArray ta2(257, 257);
            Assert::IsTrue(1 == ta1.numberOfTilesInRow());
            Assert::IsTrue(256 == ta2.numberOfTilesInRow());
        }

        TEST_METHOD(triangleArrayBeginIteratorTest)
        {
            TriangleArray ta(257, 257);
            Assert::IsTrue(ta[0] == *ta.begin());
        }

        TEST_METHOD(triangleArrayIndexOperatorTest)
        {
            TriangleArray ta(2, 2);
            Assert::IsTrue(ta[0] == Triangle(0, 2, 3));
            Assert::IsTrue(ta[1] == Triangle(0, 3, 1));
        }

    };

}