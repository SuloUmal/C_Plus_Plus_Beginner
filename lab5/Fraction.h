// TODO: header file guard
#ifndef HELPER_H
#define HELPER_H
// TODO: create namespace
namespace sict{
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
int num, den;
		// TODO: declare private member functions
int max() const;
int min() const;
void reduce();
int gcd() const;

	public:
		// TODO: declare public member functions
bool isEmpty() const;
void display() const;
Fraction();
Fraction(int numerator, int denominator);
		// TODO: declare the + operator overload
Fraction operator+(const Fraction& rhs) const; 
bool operator==(const Fraction& rhs) const; 
bool operator!=(const Fraction& rhs) const; 
Fraction operator+=(const Fraction& rhs) ; 
Fraction operator*(const Fraction& rhs) const; 
	};
}
#endif