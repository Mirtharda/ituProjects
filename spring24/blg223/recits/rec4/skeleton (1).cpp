#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "doublelinklist.h"

using namespace std;



struct Point{
    float x,y,z;
};

struct Triangle{
    Point *point1, *point2, *point3;
};

struct Mesh{
    DoublyList<Triangle> triangle_array;
};


Point* createPoint(float x, float y, float z)
{
    Point* newpoint = new Point;
    newpoint->x = x;
    newpoint->y = y;
    newpoint->z = z;
    return newpoint;
}

Triangle createTriangle(Point* p1, Point* p2, Point* p3)
{
    Triangle newtriangle;
    newtriangle.point1 = p1;
    newtriangle.point2 = p2;
    newtriangle.point3 = p3;
    return newtriangle;
}


void save_stl(char* filename, Mesh my_mesh)
{
    ofstream outfile(filename);

    outfile << "solid Mesh" << endl;

    for(int i = 0; i < my_mesh.triangle_array.elemcount; i++)
    {
        float x1= my_mesh.triangle_array.get(i).point1->x, x2= my_mesh.triangle_array.get(i).point2->x, x3= my_mesh.triangle_array.get(i).point3->x;
        float y1= my_mesh.triangle_array.get(i).point1->y, y2= my_mesh.triangle_array.get(i).point2->y, y3= my_mesh.triangle_array.get(i).point3->y;
        float z1= my_mesh.triangle_array.get(i).point1->z, z2= my_mesh.triangle_array.get(i).point2->z, z3= my_mesh.triangle_array.get(i).point3->z;

        outfile << "facet" << endl;
        outfile << "outer loop" << endl;
        outfile << "vertex " << x1 << " " << y1 << " " << z1 << endl;
        outfile << "vertex " << x2 << " " << y2 << " " << z2 << endl;
        outfile << "vertex " << x3 << " " << y3 << " " << z3 << endl;
        outfile << "endloop" << endl;
        outfile << "endfacet" << endl;

    }
    outfile << "endsolid Mesh" << endl;
}


int main()
{

    Triangle init = createTriangle(createPoint(0,0,0),createPoint(2.5,4.33,0),createPoint(-2.5,4.33,0));

    while(1)
    {
        int option;
        cout << "------------------------------------" << endl;
        cout << "1- Sierpinski's Triangle" << endl;
        cout << "2- Koch's Snowflake" << endl;
        cout << "3- Quit" << endl;
        cout << "------------------------------------" << endl;
        cout << "Please enter an action: ";
        cin >> option;

        if (option == 1)
        {
            int iteration;
            cout << "Enter Iteration count: " << endl;
            cin >> iteration;
            Mesh result = sierpinskiTriangle(iteration, init);

            save_stl("tri_result.stl", result);
        }
        else if (option == 2)
        {
            int iteration;
            cout << "Enter Iteration count: " << endl;
            cin >> iteration;

            Mesh result = kochSnowflake(iteration, init);

            save_stl("koch_result.stl", result);
        }
        else if (option == 3)
        {
            break;
        }
    }

        

    return 0;
}
