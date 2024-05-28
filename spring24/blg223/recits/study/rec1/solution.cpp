#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct Point{
    float x,y,z;
};

struct Triangle{
    Point *point1, *point2, *point3;
};

struct Mesh{
    Triangle* triangle_array;
    int triangle_count = 0;
    void x_filter(float);
    void y_filter(float);
    void z_filter(float);
};

void Mesh::x_filter(float x_limit)
{
    Triangle* filtered_triangles = new Triangle[this->triangle_count];
    int new_triangle_count = 0;

    for(int i=0; i < this->triangle_count; i++)
    {
        if(this->triangle_array[i].point1->x > x_limit || this->triangle_array[i].point2->x > x_limit || this->triangle_array[i].point3->x > x_limit )
        {
            filtered_triangles[new_triangle_count] = this->triangle_array[i];
            new_triangle_count++;
        }
    }

    delete[] this->triangle_array;

    this->triangle_array = filtered_triangles;
    this->triangle_count = new_triangle_count;

}

void Mesh::y_filter(float y_limit)
{
    Triangle* filtered_triangles = new Triangle[this->triangle_count];
    int new_triangle_count = 0;

    for(int i=0; i < this->triangle_count; i++)
    {
        if(this->triangle_array[i].point1->y > y_limit || this->triangle_array[i].point2->y > y_limit || this->triangle_array[i].point3->y > y_limit )
        {
            filtered_triangles[new_triangle_count] = this->triangle_array[i];
            new_triangle_count++;
        }
    }

    delete[] this->triangle_array;

    this->triangle_array = filtered_triangles;
    this->triangle_count = new_triangle_count;

}

void Mesh::z_filter(float z_limit)
{
    Triangle* filtered_triangles = new Triangle[this->triangle_count];
    int new_triangle_count = 0;

    for(int i=0; i < this->triangle_count; i++)
    {
        if(this->triangle_array[i].point1->z > z_limit || this->triangle_array[i].point2->z > z_limit || this->triangle_array[i].point3->z > z_limit )
        {
            filtered_triangles[new_triangle_count] = this->triangle_array[i];
            new_triangle_count++;
        }
    }

    delete[] this->triangle_array;

    this->triangle_array = filtered_triangles;
    this->triangle_count = new_triangle_count;

}


void save_stl(char* filename, Mesh my_mesh)
{
    ofstream outfile(filename);

    outfile << "solid Mesh" << endl;

    for(int i = 0; i < my_mesh.triangle_count; i++)
    {
        float x1= my_mesh.triangle_array[i].point1->x, x2= my_mesh.triangle_array[i].point2->x, x3= my_mesh.triangle_array[i].point3->x;
        float y1= my_mesh.triangle_array[i].point1->y, y2= my_mesh.triangle_array[i].point2->y, y3= my_mesh.triangle_array[i].point3->y;
        float z1= my_mesh.triangle_array[i].point1->z, z2= my_mesh.triangle_array[i].point2->z, z3= my_mesh.triangle_array[i].point3->z;

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
    int MAX_POINT_COUNT = 70000;

    Point* all_points = new Point[MAX_POINT_COUNT];

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

    cout << all_points[point_id-1].x << endl;
    cout << all_points[point_id-1].y << endl;
    cout << all_points[point_id-1].z << endl;

    int total_triangle_count = point_id /3;

    Triangle* all_triangles = new Triangle[total_triangle_count];

    for(int i=0; i<total_triangle_count; i++)
    {
        all_triangles[i].point1 = &all_points[i*3];
        all_triangles[i].point2 = &all_points[i*3+1];
        all_triangles[i].point3 = &all_points[i*3+2];
    }


    cout << all_triangles[5].point1->x << endl;
    cout << all_triangles[5].point2->x << endl;
    cout << all_triangles[5].point3->x << endl;

    Mesh my_mesh;
    my_mesh.triangle_array = all_triangles;
    my_mesh.triangle_count = total_triangle_count;

    my_mesh.x_filter(0.0);

    save_stl("new_mesh.stl", my_mesh);

    return 0;
}