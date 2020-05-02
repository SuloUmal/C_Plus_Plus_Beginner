// TODO: insert header files
#include "Fraction.h"
#include <iostream>
// TODO: continue the namespace
using namespace std;
namespace sict{
	// TODO: implement the default constructor
Fraction::Fraction(){
  num = 0;
  den = 0;
}
	// TODO: implement the two-argument constructor
Fraction::Fraction(int numerator, int denominator){
if (numerator >= 0 && denominator > 0){
  num = numerator;
  den = denominator;
} else{
  *this = Fraction();} reduce();
}
	// TODO: implement the max query
int Fraction::max() const{
  if (num > den){
return num;
  } else {return den; }
}
    // TODO: implement the min query
int Fraction::min() const{
  if (num < den){
return num;
  } else {return den; }
}
	// gcd returns the greatest common divisor of num and denom
  //
int Fraction::gcd() const {
    int mn = min();  // min of numerator and denominator
    int mx = max();  // max of numerator and denominator
    int g_c_d = 1;
    bool found = false;

    for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
        if (mx % x == 0 && mn % x == 0) {
            found = true;
            g_c_d = x;
        }
    }
    return g_c_d;
}

    // TODO: implement the reduce modifier
void Fraction::reduce(){
  int div;
  div = gcd();
  num /= div;
  den /= div;
}
    // TODO: implement the display query
void Fraction::display() const{
  if (!isEmpty()){ 
  if (num % den != 0 ){
  cout << num << "/" << den ;}
  else {cout << num ;}} else {cout <<"no fraction stored";}
}
    // TODO: implement the isEmpty query
bool Fraction::isEmpty() const{
  if (num == 0 && den == 0){ return true;} else {return false;};
}
    // TODO: implement the + operator
Fraction Fraction::operator+(const Fraction& rhs) const{
Fraction ans (-1, -1);
if (!isEmpty() && !rhs.isEmpty()){
ans.num = (num * rhs.den)+(den * rhs.num);
ans.den = den * rhs.den;
ans.reduce ();
  }else { ans.den = 0; ans.num = 0;};return ans;}

Fraction Fraction::operator*(const Fraction& rhs) const{
Fraction ans (-1, -1);
if (!isEmpty() && !rhs.isEmpty()){
ans.num = num * rhs.num;
ans.den = den * rhs.den;
ans.reduce ();
  }else { ans.den = 0; ans.num = 0;};return ans;
}

bool Fraction::operator!=(const Fraction& rhs) const{
bool ans;
if (!isEmpty() && !rhs.isEmpty()){
if (rhs.den != den && rhs.num != num){
 ans = true;
} else { ans = false; }; }
return ans;
}

Fraction Fraction::operator+=(const Fraction& rhs) {
	if (isEmpty() || rhs.isEmpty()) {
			this->num = -1;
			this->den = -1;
		}
		else {
			*this = *this + rhs;
		}    return *this;
}

bool Fraction::operator==(const Fraction& rhs) const{
bool ans;

if (!isEmpty() && !rhs.isEmpty()){
if (rhs.den == den && rhs.num == num){
 ans = true;
} else { ans = false; }; }
return ans;
}}