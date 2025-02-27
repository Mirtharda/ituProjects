// e02_6.cpp
// Opertor overloading

// #include <print>			// Prior to C++23 header file for std::println
import std;                 // Since C++23

struct ComplexT{    //structure for Complex numbers
   float re,im;
};

/* Overloading the operator + for complex numbers */
ComplexT operator+ (const ComplexT &v1, const ComplexT &v2)
{
   ComplexT result;				// A local complex number
   result.re=v1.re+v2.re;
   result.im=v1.im+v2.im;
   return result;
}

void print (const ComplexT &c){    // print function for complex numbers
   std::println("real= {} im= {}", c.re, c.im);
}

//-------- main function -------------
int main()
{
	ComplexT c1,c2,c3;	
	c1.re=0.5;
	c1.im=-1;

	c2.re=1.5;
	c2.im=0.5;

	c3=c1+c2;					// Calling the operator+ function
	print(c3);
	return 0;
}