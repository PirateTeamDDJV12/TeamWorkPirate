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

    if(result1 != result2)
    {
        throw 1;
    }

    cout << "scalar product : " << result1 << endl;
    cout << "scalar product : " << result2 << endl;

    Vect3f vect3 = Vect3f::crossProduct(vect1, vect2);

    if((Vect3f::scalarProduct(vect3, vect1) != 0.f) || (Vect3f::scalarProduct(vect3, vect2) != 0.f))
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


int main()
{
    /*
    Vect3f vect1;
    Vect3f vect2(10, 5, 5);


    run(vect1, vect2);


    vect1.x(-15);
    vect1.y(5);
    vect1.z(-15);

    run(vect1, vect2);


    Vertex vertexSample;
    */
    /*
    HeightMap heightmapFile("Ressources/TestHeightMap.raw");

   /* for (int i = 0; i < heightmapFile.size(); i++)
    HeightMap heightmapFile("Ressources/TestHeightMap.raw");
    map<unsigned int, Vertex> myVertexMap = heightmapFile.transformToVertexMap();
    
    for(int i = 0; i < heightmapFile.size(); i++)
    {
        cout << i << " : " << myVertexMap[i].toString();
        cout << endl;
    }

    cout << endl;*/

    /* convertir en VertexArray*/
    VertexArray vArray = VertexArray(heightmapFile, 0.3f);
    std::vector<Vertex> vList = vArray.getArray();
   /* for (int i = 0;i < heightmapFile.size();i++)
    {
        //if (i % 3 == 2)
        {
            cout << vList[i].position().x();
            cout << " ";
            cout << vList[i].position().y();
            cout << " ";
            cout << vList[i].position().z();
            cout << endl;
        }
    }*/

    for (int i = 0; i < heightmapFile.size(); i++)
    {
        if (vList[i].position().z() < 0.f)
        {
            cout << vList[i].position().x();
            cout << " ";
            cout << vList[i].position().y();
            cout << " ";
            cout << vList[i].position().z();
            cout << endl;
        }
    }


    /*  LireFichierHeightmap();
      ConstruireTerrain(float echelleXY, float echelleZ);
      CalculerNormales();
      ConstruireIndex();
      EnregistrerTout();
      */
    Triangle triangle(10, 5, 2);

    cout << triangle.toString();

    /*TriangleArray mapArray (5, 5);

    //cout << mapArray.numberOfPolygone() << " " << mapArray.numberOfPolygoneInColumn() << " " << mapArray.numberOfPolygoneInRow() << " " << mapArray.numberOfTilesInColumn() << " " << mapArray.numberOfTilesInRow() << endl;

    cout << mapArray.toString();*/

    UnitaryTest::TriangleArrayUnitTest::run();

    cout << UnitaryTest::TriangleArrayUnitTest::getResult();

  /*  LireFichierHeightmap();
    ConstruireTerrain(float echelleXY, float echelleZ);
    CalculerNormales();
    ConstruireIndex();
    EnregistrerTout();
    */

    system("pause");

    return 0;
}