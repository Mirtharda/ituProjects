// e02_3_with_cout.cpp
// Overloading of function names

#include <print>			// Prior to C++23 header file for std::print and std::println
using namespace std;                 // Since C++23

struct ComplexT{            // Structure for complex numbers
    float re,im;
};

void print (float value){   // print function for real numbers
   std::println("print function for real numbers");
   std::println("value= {}", value);
}
void print (ComplexT c){    // print function for complex numbers
   std::println("print function for complex numbers");
   std::println("real= {} im= {}", c.re, c.im);
}
void print (float value, char c){    // print function for real numbers and chars
   std::println("print function for real numbers and chars");
   std::println("value= {} c= {}", value, c);
}
//--------- Main Function ----------
int main()
{
	ComplexT z;			// A complex number is defined
	z.re=0.5f;			// Fields of the complex number are filled with float values
	z.im=1.2f;			 
	print(z);			         // print for complex number
	print(4.2f);			 // print for real number (float)
	print(2.5,'A');	     // print for real number and char
	return 0;
}