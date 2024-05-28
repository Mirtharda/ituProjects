#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

struct Point 
{
    float x, y, z;
    Point* couple_point;
};

float calculate_couple_distance(Point p)
{
    return sqrt(pow(p.x - p.couple_point->x, 2) +
        pow(p.y - p.couple_point->y, 2) + pow(p.z - p.couple_point->z, 2));
}

void add20(int param)
{
    param += 20;
}
void add30(int &param)
{
    param += 30;
}
void swap(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}

int main() 
{
    cout << "--------Message 1---------\n";
    Point point1, point2;
    point1.x = 1.3;
    point1.y = 3.4;
    point1.z = 3.3;
    point1.couple_point = &point2;
    cout << "Point1.couple_point points to " << point1.couple_point << endl;

    point2.x = 5;
    point2.y = 5;
    point2.z = 5;
    point2.couple_point = &point1;
    cout << "Point2.couple_point points to " << point2.couple_point << endl;

    cout << "--------Message 2---------\n";
    cout << "Distance p1 " << calculate_couple_distance(point1) << endl;
    cout << "Distance p2 " << calculate_couple_distance(point2) << endl;


    cout << "--------Message 3---------\n";
    int num = 10;
    add20(num);
    cout << num << endl;
    add30(num);
    cout << num << endl;

    cout << "--------Message 4---------\n";
    int x = 5, y = 11;
    swap(x, y);
    cout << "x, y = " << x << ", " << y << endl;


    return 0;
}