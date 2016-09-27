/*
Created by Sun-lay gagneux
*/
#include "Vertex.h"

#include "HeightMap.h"
#include "VertexArray.h"
/*
#include "Triangle.h"
#include "TriangleArray.h"
*/
#include "UnitaryTestTriangleArray.h"
#include "Config.hpp"
#include <iostream>
#include <algorithm>
#include <map>




using namespace FieldConverter;
using namespace std;


void run(const Vect3f& vect1, const Vect3f& vect2)
{
    cout << "vect1(" << vect1.x() << " " << vect1.y() << " " << vect1.z() << ")" << endl;
    cout << "vect2(" << vect2.x() << " " << vect2.y() << " " << vect2.z() << ")" << endl;

    float result1 = vect1.scalarProduct(vect2);
    float result2 = vect2.scalarProduct(vect1);

    if (result1 != result2)
    {
        throw 1;
    }

    cout << "scalar product : " << result1 << endl;
    cout << "scalar product : " << result2 << endl;

    Vect3f vect3 = Vect3f::crossProduct(vect1, vect2);

    if ((Vect3f::scalarProduct(vect3, vect1) != 0.f) || (Vect3f::scalarProduct(vect3, vect2) != 0.f))
    {
        throw 2;
    }

    vect3 = vect1 + vect2;
    cout << "Add : vect3(" << vect3.x() << " " << vect3.y() << " " << vect3.z() << ")" << endl;

    vect3 = vect1 - vect2;
    cout << "Subtract : vect3(" << vect3.x() << " " << vect3.y() << " " << vect3.z() << ")" << endl;

    vect3 = vect3 * 10.f;
    cout << "Resize x10 : vect3(" << vect3.x() << " " << vect3.y() << " " << vect3.z() << ")" << endl;

    vect3 = vect3 / 5.f;
    cout << "Reducing /5 : vect3(" << vect3.x() << " " << vect3.y() << " " << vect3.z() << ")" << endl;
}
using FieldConverter::Config;

int main()
{
    HeightMap heightmapFile("Ressources/TestHeightMap.raw");
    VertexArray vArray = VertexArray(heightmapFile, 0.3f);
    std::vector<Vertex> vList = vArray.getArray();
    TriangleArray mapArray (257, 257);

    heightmapFile.writeIntoOutputFile("testOutput.txt", heightmapFile.transformToVertexMap(), mapArray);

    /*  LireFichierHeightmap();
    ConstruireTerrain(float echelleXY, float echelleZ);
    CalculerNormales();
    ConstruireIndex();
    EnregistrerTout();
    */

    try 
    {
        std::cout << Config::getInstance().getPath() << std::endl;
        std::cout << Config::getInstance().getWidth() << std::endl;
        std::cout << Config::getInstance().getHeight() << std::endl;
        std::cout << Config::getInstance().getScale() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    system("pause");

	return 0;
}