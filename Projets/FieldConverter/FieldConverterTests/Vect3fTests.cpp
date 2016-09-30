#include "stdafx.h"
#include "CppUnitTest.h"

#include "../FieldConverter/Vect3f.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace FieldConverter;

namespace FieldConverterTest
{
    TEST_CLASS(Vect3fTests)
    {
    public:

        TEST_METHOD(vect3fGetXTest)
        {
            Vect3f v3f(1.0f, 2.0f, 3.0f);
            Assert::AreEqual(1.0f, v3f.x());
        }

        TEST_METHOD(vect3fGetYTest)
        {
            Vect3f v3f(1.0f, 2.0f, 3.0f);
            Assert::AreEqual(2.0f, v3f.y());
        }

        TEST_METHOD(vect3fGetZTest)
        {
            Vect3f v3f(1.0f, 2.0f, 3.0f);
            Assert::AreEqual(3.0f, v3f.z());
        }

        TEST_METHOD(vect3fSetXTest)
        {
            Vect3f v3f(1.0f, 2.0f, 3.0f);
            v3f.x(0.0f);
            Assert::AreEqual(0.0f, v3f.x());
        }

        TEST_METHOD(vect3fSetYTest)
        {
            Vect3f v3f(1.0f, 2.0f, 3.0f);
            v3f.y(0.0f);
            Assert::AreEqual(0.0f, v3f.y());
        }

        TEST_METHOD(vect3fSetZTest)
        {
            Vect3f v3f(1.0f, 2.0f, 3.0f);
            v3f.z(0.0f);
            Assert::AreEqual(0.0f, v3f.z());
        }

        TEST_METHOD(vect3fScalarProductTest1)
        {
            Vect3f v3f(1.0f, 1.0f, 1.0f);
            Assert::AreEqual(3.0f, v3f.scalarProduct(v3f));
        }

        TEST_METHOD(vect3fCrossProductTest1)
        {
            Assert::IsTrue(Vect3f(-10.0f, -5.0f, -15.0f) == Vect3f(1.0f, 7.0f, -3.0f).crossProduct(Vect3f(2.0f, -1.0f, -1.0f)));
        }

        TEST_METHOD(vect3fLength2Test1)
        {
            Vect3f v3f(1.5f, 1.5f, 1.5f);
            Assert::AreEqual(6.75f, v3f.length2());
        }

        TEST_METHOD(vect3fLengthTest1)
        {
            Vect3f v3f(1.0f, 2.0f, 2.0f);
            Assert::AreEqual(3.00f, v3f.length());
        }

        TEST_METHOD(vect3fIsOriginTest)
        {
            Vect3f v3f1(0.0f, 0.0f, 0.0f);
            Vect3f v3f2(0.1f, 0.0f, 0.0f);
            Vect3f v3f3(0.0f, 0.1f, 0.0f);
            Vect3f v3f4(0.0f, 0.0f, 0.1f);
            Assert::IsTrue(v3f1.isOrigin());
            Assert::IsFalse(v3f2.isOrigin() || v3f3.isOrigin() || v3f4.isOrigin());
        }

        TEST_METHOD(vect3fScalarProductTest2)
        {
            Vect3f v3f1(1.0f, 1.0f, 1.0f);
            Vect3f v3f2(1.0f, 1.0f, 1.0f);
            Vect3f v3f3(1.0f, 1.0f, 1.0f);
            Assert::AreEqual(3.0f, v3f1.scalarProduct(v3f2, v3f3));
        }

        TEST_METHOD(vect3fCrossProductTest2)
        {
            Assert::IsTrue(Vect3f(0, 0, 0) == Vect3f(1.5f, 1.5f, 1.5f).crossProduct(Vect3f(1.5f, 1.5f, 1.5f), Vect3f(1.5f, 1.5f, 1.5f)));
        }

        TEST_METHOD(vect3fLength2Test2)
        {
            Vect3f v3f1(1.0f, 1.0f, 1.0f);
            Vect3f v3f2(1.5f, 1.5f, 1.5f);
            Assert::AreEqual(6.75f, v3f1.length2(v3f2));
        }

        TEST_METHOD(vect3fLengthTest2)
        {
            Vect3f v3f1(1.0f, 1.0f, 1.0f);
            Vect3f v3f2(1.0f, 2.0f, 2.0f);
            Assert::AreEqual(3.00f, v3f1.length(v3f2));
        }

        TEST_METHOD(vect3fEqualOperatorTest)
        {
            Vect3f v3f1(1.0f, 1.0f, 1.0f);
            Vect3f v3f2(1.0f, 1.0f, 1.0f);
            Vect3f v3f3(0.0f, 1.0f, 1.0f);
            Vect3f v3f4(1.0f, 0.0f, 1.0f);
            Vect3f v3f5(1.0f, 1.0f, 0.0f);
            Assert::IsTrue(v3f1 == v3f2);
            Assert::IsFalse(v3f1 == v3f3 || v3f1 == v3f4 || v3f1 == v3f5);
        }

        TEST_METHOD(vect3fNotEqualOperatorTest)
        {
            Vect3f v3f1(1.0f, 1.0f, 1.0f);
            Vect3f v3f2(1.0f, 1.0f, 1.0f);
            Vect3f v3f3(0.0f, 1.0f, 1.0f);
            Vect3f v3f4(1.0f, 0.0f, 1.0f);
            Vect3f v3f5(1.0f, 1.0f, 0.0f);
            Assert::IsFalse(v3f1 != v3f2);
            Assert::IsTrue(v3f1 != v3f3 && v3f1 != v3f4 && v3f1 != v3f5);
        }

        TEST_METHOD(vect3fAdditionOperatorTest1)
        {
            Vect3f v3f1(0.0f, 0.0f, 0.0f);
            Vect3f v3f2(1.0f, 1.0f, 1.0f);
            v3f1 += v3f2;
            Assert::IsTrue(v3f1 == v3f2);
        }

        TEST_METHOD(vect3fSubtractionOperatorTest1)
        {
            Vect3f v3f1(2.0f, 2.0f, 2.0f);
            Vect3f v3f2(1.0f, 1.0f, 1.0f);
            v3f1 -= v3f2;
            Assert::IsTrue(v3f1 == v3f2);
        }

        TEST_METHOD(vect3fMultiplicationOperatorTest1)
        {
            Vect3f v3f1(2.0f, 2.0f, 2.0f);
            Vect3f v3f2(2.0f, 2.0f, 2.0f);
            v3f1 *= v3f2;
            Assert::IsTrue(v3f1 == Vect3f(4.0f, 4.0f, 4.0f));
        }

        TEST_METHOD(vect3fMultiplicationOperatorTest2)
        {
            Vect3f v3f1(2.0f, 2.0f, 2.0f);
            v3f1 *= 2;
            Assert::IsTrue(v3f1 == Vect3f(4.0f, 4.0f, 4.0f));
        }

        TEST_METHOD(vect3fDivisionOperatorTest1)
        {
            Vect3f v3f1(2.0f, 2.0f, 2.0f);
            v3f1 /= 2;
            Assert::IsTrue(v3f1 == Vect3f(1.0f, 1.0f, 1.0f));
        }

        TEST_METHOD(vect3fAdditionOperatorTest2)
        {
            Vect3f v3f1(1.0f, 1.0f, 1.0f);
            Vect3f v3f2 = v3f1 + v3f1;
            Assert::IsTrue(v3f2 == Vect3f(2.0f, 2.0f, 2.0f));
        }

        TEST_METHOD(vect3fSubtractionOperatorTest2)
        {
            Vect3f v3f1(1.0f, 1.0f, 1.0f);
            Vect3f v3f2 = v3f1 - v3f1;
            Assert::IsTrue(v3f2 == Vect3f(0.0f, 0.0f, 0.0f));
        }

        TEST_METHOD(vect3fMultiplicationOperatorTest3)
        {
            Vect3f v3f1(2.0f, 2.0f, 2.0f);
            Vect3f v3f2 = v3f1 * 2;
            Assert::IsTrue(v3f2 == Vect3f(4.0f, 4.0f, 4.0f));
        }

        TEST_METHOD(vect3fDivisionOperatorTest2)
        {
            Vect3f v3f1(2.0f, 2.0f, 2.0f);
            Vect3f v3f2 = v3f1 / 2;
            Assert::IsTrue(v3f2 == Vect3f(1.0f, 1.0f, 1.0f));
        }

        TEST_METHOD(vect3fMultiplicationOperatorTest4)
        {
            Assert::IsTrue(Vect3f(0, 0, 0) == Vect3f(1.5f, 1.5f, 1.5f) * Vect3f(1.5f, 1.5f, 1.5f));
        }
    };

}