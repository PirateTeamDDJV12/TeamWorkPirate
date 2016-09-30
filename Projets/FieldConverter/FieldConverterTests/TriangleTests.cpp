#include "stdafx.h"
#include "CppUnitTest.h"

#include "../FieldConverter/Triangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace FieldConverter;

namespace FieldConverterTest
{
    TEST_CLASS(TriangleTests)
    {
    public:

        TEST_METHOD(triangleFirstPointIndexTest)
        {
            Triangle t(1, 2, 3);
            Assert::AreEqual((unsigned int)1, t.firstPointIndex());
        }

        TEST_METHOD(triangleSecondPointIndexTest)
        {
            Triangle t(1, 2, 3);
            Assert::AreEqual((unsigned int)2, t.secondPointIndex());
        }

        TEST_METHOD(triangleThirdPointIndexTest)
        {
            Triangle t(1, 2, 3);
            Assert::AreEqual((unsigned int)3, t.thirdPointIndex());
        }

        TEST_METHOD(triangleToStringTest)
        {
            Triangle t(1, 2, 3);
            Assert::AreEqual(std::string("1 2 3 \n"), t.toString());
        }

        TEST_METHOD(triangleEqualOperatorTest)
        {
            Triangle t1(1, 1, 1);
            Triangle t2(1, 1, 1);
            Triangle t3(0, 1, 1);
            Triangle t4(1, 0, 1);
            Triangle t5(1, 1, 0);
            Triangle t6(1, 0, 0);
            Triangle t7(0, 1, 0);
            Triangle t8(0, 0, 1);
            Triangle t9(0, 0, 0);

            Assert::IsTrue(t1 == t2);
            Assert::IsFalse(t1 == t3 || t1 == t4 || t1 == t5 || t1 == t6 || t1 == t7 || t1 == t8 || t1 == t9);
        }

        TEST_METHOD(triangleNotEqualOperatorTest)
        {
            Triangle t1(1, 1, 1);
            Triangle t2(1, 1, 1);
            Triangle t3(0, 1, 1);
            Triangle t4(1, 0, 1);
            Triangle t5(1, 1, 0);
            Triangle t6(1, 0, 0);
            Triangle t7(0, 1, 0);
            Triangle t8(0, 0, 1);
            Triangle t9(0, 0, 0);

            Assert::IsFalse(t1 != t2);
            Assert::IsTrue(t1 != t3 && t1 != t4 && t1 != t5 && t1 != t6 && t1 != t7 && t1 != t8 && t1 != t9);
        }
    };

}