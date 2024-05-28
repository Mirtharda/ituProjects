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


Mesh sierpinskiTriangle(int n, Triangle tri)
{
    if (n == 1)
    {
        Mesh my_mesh;
        my_mesh.triangle_array.addFront(tri);
        return my_mesh;
    }
    else
    {
        float x1 = tri.point1->x, y1 = tri.point1->y, z1 = tri.point1->z;
        float x2 = tri.point2->x, y2 = tri.point2->y, z2 = tri.point2->z;
        float x3 = tri.point3->x, y3 = tri.point3->y, z3 = tri.point3->z;
        
        Mesh mesh1 = sierpinskiTriangle(n-1, createTriangle(createPoint(x1,y1,z1), createPoint((x1+x3)/2, (y1+y3)/2, (z1+z3)/2), createPoint((x1+x2)/2,(y1+y2)/2, (z1+z2)/2)));
        Mesh mesh2 = sierpinskiTriangle(n-1, createTriangle(createPoint((x2+x3)/2, (y2+y3)/2, (z2+z3)/2), createPoint(x2, y2, z2), createPoint((x2+x1)/2, (y2+y1)/2, (z2+z1)/2)));
        Mesh mesh3 = sierpinskiTriangle(n-1, createTriangle(createPoint((x3+x1)/2, (y3+y1)/2, (z3+z1)/2), createPoint((x3+x2)/2, (y3+y2)/2, (z3+z2)/2), createPoint(x3, y3, z3)));
        
        //Add elements of mesh2 and mesh3 to mesh1

        for(Node<Triangle>* ptr = mesh2.triangle_array.head; ptr != NULL; ptr = ptr->next)
            mesh1.triangle_array.addBack(ptr->data);

        for(Node<Triangle>* ptr = mesh3.triangle_array.head; ptr != NULL; ptr = ptr->next)
            mesh1.triangle_array.addBack(ptr->data);

        return mesh1;
    }
}

Mesh kochSnowflake(int n, Triangle tri)
{
    if (n == 1)
    {
        Mesh my_mesh;
        my_mesh.triangle_array.addFront(tri);
        return my_mesh;
    }
    else
    {
        //Points from the original triangle
        float x1 = tri.point1->x, y1 = tri.point1->y, z1 = tri.point1->z;
        float x2 = tri.point2->x, y2 = tri.point2->y, z2 = tri.point2->z;
        float x3 = tri.point3->x, y3 = tri.point3->y, z3 = tri.point3->z;

        //New points
        float x4 = x2+(2.0/3)*(x3-x2), y4 = y2+(2.0/3)*(y3-y2), z4 = z2+(2.0/3)*(z3-z2);
        float x5 = x2+(1.0/3)*(x3-x2), y5 = y2+(1.0/3)*(y3-y2), z5 = z2+(1.0/3)*(z3-z2);

        float x7 = x1+(2.0/3)*(x3-x1), y7 = y1+(2.0/3)*(y3-y1), z7 = z1+(2.0/3)*(z3-z1);
        float x8 = x1+(1.0/3)*(x3-x1), y8 = y1+(1.0/3)*(y3-y1), z8 = z1+(1.0/3)*(z3-z1);

        float x10 = x1+(2.0/3)*(x2-x1), y10 = y1+(2.0/3)*(y2-y1), z10 = z1+(2.0/3)*(z2-z1);
        float x11 = x1+(1.0/3)*(x2-x1), y11 = y1+(1.0/3)*(y2-y1), z11 = z1+(1.0/3)*(z2-z1);

        float x6 = x4+(x4-x7), y6 = y4+(y4-y7), z6 = z4+(z4-z7);        
        float x9 = x7-(x4-x7), y9 = y7-(y4-y7), z9 = z7-(z4-z7);        
        float x12 = x11-(x8-x11), y12 = y11-(y8-y11), z12 = z11-(z8-z11);

        Mesh mesh0 = kochSnowflake(1, tri);
        Mesh mesh1 = kochSnowflake(n-1, createTriangle(createPoint(x4, y4, z4), createPoint(x5,  y5,  z5), createPoint(x6,  y6,  z6)));
        Mesh mesh2 = kochSnowflake(n-1, createTriangle(createPoint(x7, y7, z7), createPoint(x8,  y8,  z8), createPoint(x9,  y9,  z9)));
        Mesh mesh3 = kochSnowflake(n-1, createTriangle(createPoint(x10, y10, z10), createPoint(x11,  y11,  z11), createPoint(x12,  y12,  z12)));
        Mesh mesh4 = kochSnowflake(n-1, createTriangle(createPoint(x1,  y1,  z1), createPoint(x8,  y8,  z8), createPoint(x11, y11, z11)));
        Mesh mesh5 = kochSnowflake(n-1, createTriangle(createPoint(x2,  y2,  z2), createPoint(x5,  y5,  z5), createPoint(x10, y10, z10)));
        Mesh mesh6 = kochSnowflake(n-1, createTriangle(createPoint(x3,  y3,  z3), createPoint(x7,  y7,  z7), createPoint(x4, y4, z4)));

        for(Node<Triangle>* ptr = mesh1.triangle_array.head; ptr != NULL; ptr = ptr->next)
            mesh0.triangle_array.addBack(ptr->data);
        for(Node<Triangle>* ptr = mesh2.triangle_array.head; ptr != NULL; ptr = ptr->next)
            mesh0.triangle_array.addBack(ptr->data);
        for(Node<Triangle>* ptr = mesh3.triangle_array.head; ptr != NULL; ptr = ptr->next)
            mesh0.triangle_array.addBack(ptr->data);
        for(Node<Triangle>* ptr = mesh4.triangle_array.head; ptr != NULL; ptr = ptr->next)
            mesh0.triangle_array.addBack(ptr->data);
        for(Node<Triangle>* ptr = mesh5.triangle_array.head; ptr != NULL; ptr = ptr->next)
            mesh0.triangle_array.addBack(ptr->data);
        for(Node<Triangle>* ptr = mesh6.triangle_array.head; ptr != NULL; ptr = ptr->next)
            mesh0.triangle_array.addBack(ptr->data);

        return mesh0;

    }


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
