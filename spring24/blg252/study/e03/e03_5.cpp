#include <iostream>

#include <iostream>
#include <cmath>     // To use the std::sqrt() function

using std::cout;
using std::endl;

// Point class with lower limits
class Point{							
public:
    friend void display(Point&);
    friend class GraphicTools;

	double distanceFromZero();			
	// Getters:
	int getX() { return m_x; }         
	int getY() { return m_y; }         
	int getMIN_x() { return MIN_x; }   
	int getMIN_y() { return MIN_y; }   
	// Setters:
	void setX(int);
	void setY(int);
private:
	const int MIN_x { };				// Minimum value for x is zero
	const int MIN_y { };				// Minimum value for y is zero
	
	int m_x{ MIN_x }, m_y{ MIN_y };
};

// ***** Bodies of Member Functions *****

 // Calculates and returns the distance of a point from (0,0)
double Point::distanceFromZero() {
	return std::sqrt(m_x * m_x + m_y * m_y);   // distance from (0,0)
	// The sqrt() function returns the square root of a number. This function is defined in the cmath header file.
}

// Setters
void Point::setX(int new_x){
    if (new_x >= MIN_x) m_x = new_x;	// Accepts only valid values 
}
void Point::setY(int new_y){
    if (new_y >= MIN_y) m_y = new_y;	// Accepts only valid values 
}

void display(Point &point) {
    std::cout << "x= " << point.m_x << " y= " << point.m_y << endl;
}

class GraphicTools {
    public:
        void moveToZero (Point& point) {
            point.m_x=0;
            point.m_y=0;
        }
};

int main() {
    Point point1;
    point1.setX(10);
    point1.setY(20);
    display(point1);

    GraphicTools tool;
    tool.moveToZero(point1);
    display(point1);

    return 0;
}