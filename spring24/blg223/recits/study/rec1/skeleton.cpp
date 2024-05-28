#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct Point
{
    float x, y, z;
};

struct Triangle
{
    Point point1, point2, point3;
};

struct Mesh 
{
    Triangle* triangle_array;
    int triangle_count = 0;
};


void save_stl(char* filename)
{
    ofstream outfile(filename);

    outfile << "solid Mesh" << endl;

    int triangle_count = 5;

    for(int i = 0; i < triangle_count; i++)
    {
        float x1= 0.0, x2= 0.0, x3=0.0;
        float y1= 0.0, y2= -5.0, y3=5.0;
        float z1= 10.0 + i*10, z2= 0.0 + i*10, z3=0.0 + i*10;

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
    Point* all_points = new Point{70000};

    ifstream infile("rec1_mesh.stl");

    int point_id = 0;

    string line;
    while (true) {
        getline(infile, line);

        if (infile.eof()) {
            break;
        }
       if (strncmp(line.c_str(), "vertex", 6) == 0)
        {
            //cout << line <<  endl;

            int space_positions[4];
            int pos_counter = 0;

            for (int i=0; i<strlen(line.c_str()); i++)
            {
                if (line[i] == ' ')
                {
                    space_positions[pos_counter] = i;
                    pos_counter++;
                }
            }
            float x = stof(line.substr(space_positions[0], space_positions[1]));
            float y = stof(line.substr(space_positions[1], space_positions[2]));
            float z = stof(line.substr(space_positions[2], strlen(line.c_str())));

            all_points[point_id].x = x;
            all_points[point_id].y = y;
            all_points[point_id].z = z;
            point_id++;

            //cout << x << " " << y << " " << z << endl;
        }

    }
    cout << "Last point is \n";
    cout << all_points[point_id].x << endl;
    cout << all_points[point_id].y << endl;
    cout << all_points[point_id].z << endl;
    
    save_stl("result.stl");


    return 0;
}