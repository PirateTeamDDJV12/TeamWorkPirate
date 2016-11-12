#include "stdafx.h"
#include "CppUnitTest.h"

#include "../FieldConverter/Vertex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace FieldConverter;

namespace FieldConverterTest
{
    TEST_CLASS(VertexTests)
    {
    public:

        TEST_METHOD(vertexGetPositionTest)
        {
            Vertex v(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f);
            Assert::IsTrue(Vect3f(1.0f, 2.0f, 3.0f) == v.position());
        }

        TEST_METHOD(vertexGetNormalVectorTest)
        {
            Vertex v(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f);
            Assert::IsTrue(Vect3f(4.0f, 5.0f, 6.0f) == v.normalVector());
        }

        TEST_METHOD(vertexSetPositionTest)
        {
            Vertex v(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            v.position() = Vect3f(1.0f, 2.0f, 3.0f);
            Assert::IsTrue(Vect3f(1.0f, 2.0f, 3.0f) == v.position());
        }

        TEST_METHOD(vertexSetNormalVectorTest)
        {
            Vertex v(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            v.normalVector() = Vect3f(4.0f, 5.0f, 6.0f);
            Assert::IsTrue(Vect3f(4.0f, 5.0f, 6.0f) == v.normalVector());
        }

        TEST_METHOD(vertexToStringTest)
        {
            Vertex v(1.0f, 2.2f, 3.0f, 4.44f, 5.0f, 6.666f);
            std::string g = v.toString();
            Assert::AreEqual(std::string("1 2.2 3 4.44 5 6.666\n"), v.toString());
        }

        TEST_METHOD(vertexEqualOperatorTest)
        {
            Vertex v1(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            Vertex v2(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            Vertex v3(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            Vertex v4(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            Vertex v5(0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
            Vertex v6(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
            Vertex v7(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
            Vertex v8(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
            Assert::IsTrue(v1 == v2);
            Assert::IsFalse(v1 == v3 || v1 == v4 || v1 == v5 || v1 == v6 || v1 == v7 || v1 == v8);
        }

        TEST_METHOD(vertexNotEqualOperatorTest)
        {
            Vertex v1(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            Vertex v2(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            Vertex v3(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            Vertex v4(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            Vertex v5(0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
            Vertex v6(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
            Vertex v7(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
            Vertex v8(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
            Assert::IsFalse(v1 != v2);
            Assert::IsTrue(v1 != v3 && v1 != v4 && v1 != v5 && v1 != v6 && v1 != v7 && v1 != v8);
        }
    };

}