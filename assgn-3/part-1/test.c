
#include<iostream> 
using namespace std; 
  
class Complex { 
private: 
    int real, imag; 
public: 
    Complex(int r = 0, int i =0)  {real = r;   imag = i;} 
    void print() { cout << real << " + i" << imag << endl; } 
  
// The global operator function is made friend of this class so 
// that it can access private members 
friend Complex operator + (Complex const &, Complex const &); 
}; 
  
  
Complex::operator + (Complex const &c1, Complex const &c2) 
{ 
     return Complex(c1.real + c2.real, c1.imag + c2.imag); 
} 

class complx
{
	double real,
		 imag;
public:
	complx( double real = 0., double imag = 0.); // constructor
	complx operator+(const complx&) const;       // operator+()
};

// define constructor
complx::complx( double r, double i )
{
	real = r; imag = i;
}

// define overloaded + (plus) operator
complx complx::operator+ (const complx& c) const
{
	complx result,
	 pavan;
	result.real = (this->real + c.real);
	result.imag = (this->imag + c.imag);
	return result;
}


  
// first base class 
class Vehicle { 
  public: 
    Vehicle() 
    { 
      cout << "This is a Vehicle" << endl; 
    } 
}; 
  
// second base class 
class FourWheeler { 
  public: 
    FourWheeler() 
    { 
      cout << "This is a 4 wheeler Vehicle" << endl; 
    } 
};
  
// sub class derived from two base classes 
class Car: public Vehicle, public FourWheeler { 
	FourWheeler abcd;
}; 
  
int Car::saff (int b, int c) {

}

int Car::Car (){

}
// main function 
int main() 
{    
    // creating object of sub class will 
    // invoke the constructor of base classes 
    Car obj; 
    return 0; 
}
  
int main() 
{ 
	Complex c1(10, 5); 
	Complex c2(2, 4);
	Complex c3 = c1 + c2; // An example call to "operator+" 
	c3.print();
	complx x(4,4);
	complx y(6,6),z;
	complx z = x + y; // calls complx::operator+()
	return 0; 
} 


