#include "stdafx.h"
#include "CppUnitTest.h"

#include "../FieldConverter/Triangle.h"

#include <vector>
#include <algorithm>

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
            Triangle t(1, 1, 1);

            std::vector<Triangle> v =
            {
                Triangle(0, 1, 1),
                Triangle(1, 0, 1),
                Triangle(1, 1, 0),
                Triangle(1, 0, 0),
                Triangle(0, 1, 0),
                Triangle(0, 0, 1),
                Triangle(0, 0, 0)
            };

            Assert::IsTrue(t == t);
            Assert::IsFalse(std::any_of(v.cbegin(), v.cend(), [&t](Triangle ti) { return ti == t; }));
        }

        TEST_METHOD(triangleNotEqualOperatorTest)
        {
            Triangle t(1, 1, 1);

            std::vector<Triangle> v = 
            {   
                Triangle(0, 1, 1), 
                Triangle(1, 0, 1), 
                Triangle(1, 1, 0), 
                Triangle(1, 0, 0), 
                Triangle(0, 1, 0), 
                Triangle(0, 0, 1), 
                Triangle(0, 0, 0) 
            };

            Assert::IsFalse(t != t);
            Assert::IsTrue(std::all_of(v.cbegin(), v.cend(), [&t](Triangle ti) { return ti != t; }));
        }
    };

}