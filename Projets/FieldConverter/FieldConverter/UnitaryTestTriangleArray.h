#ifndef UNITARYTEST_TRIANGLE_ARRAY_H
#define UNITARYTEST_TRIANGLE_ARRAY_H


#include "TriangleArray.h"

#include <string>


namespace FieldConverter
{
    namespace UnitaryTest
    {
        class TriangleArrayUnitTest
        {
        public:
            class ProblemMappingArray{};
            class ProblemPolygoneNumber{};
            class ProblemPolygoneInWidth{};
            class ProblemPolygoneInHeight{};
            class ProblemTilesInHeight{};
            class ProblemTilesInWidth{};


        private:
            static TriangleArrayUnitTest m_testerInstance;
            static bool m_throw;


        private:
            TriangleArray m_array;
            std::string m_result;


        private:
            TriangleArrayUnitTest(size_t numberOfVertexInColumn) noexcept;

            TriangleArrayUnitTest(const TriangleArrayUnitTest&) = delete;

        public:
            static void run();

            static const std::string& getResult() noexcept
            {
                return m_testerInstance.m_result;
            }

            static bool mustThrowAtProblem(bool mustThrow) noexcept
            {
                m_throw = mustThrow;
            }

        private:
            TriangleArray& arrayAnswer() noexcept
            {
                return m_array;
            }

            std::string& result() noexcept
            {
                return m_result;
            }

            TriangleArray arrayAnswer() const noexcept
            {
                return m_array;
            }

            std::string result() const noexcept
            {
                return m_result;
            }

            static void runCheckArray(const TriangleArray& triangleSample, std::string& resultTesting);
            static void runCheckPolygoneNumber(const TriangleArray& triangleSample, std::string& resultTesting);
            static void runCheckPolygoneInWidth(const TriangleArray& triangleSample, std::string& resultTesting);
            static void runCheckPolygoneInHeight(const TriangleArray& triangleSample, std::string& resultTesting);
            static void runCheckTilesInHeight(const TriangleArray& triangleSample, std::string& resultTesting);
            static void runCheckTilesInWidth(const TriangleArray& triangleSample, std::string& resultTesting);

            void fillTriangleBuffer(Triangle& toFill, unsigned int indexP1, unsigned int indexP2, unsigned int indexP3) const;

            Triangle* getAnswerTriangle44() const;
            Triangle* getAnswerTriangle55() const;


        private:
            TriangleArrayUnitTest& operator=(const TriangleArrayUnitTest&) = delete;
            TriangleArrayUnitTest& operator=(TriangleArrayUnitTest&& otherDead);
        };
    }
}


#endif //!UNITARYTEST_TRIANGLE_ARRAY_H