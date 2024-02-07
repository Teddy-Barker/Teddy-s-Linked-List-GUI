#include <iostream>
#include "rational.h"

/********************************************************************************
 * CONSTRUCTOR Rational: Class Rational
 *
  -------------------------------------------------------------------------------
 * This constructor initializes a Rational object with the default values for n,
 * the numerator, and d, the denominator. Default values of n = 0 and d = 1.
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    The following does not need previously defined values.
 *
 * POST-CONDITIONS
 *    Initializes a Rational object with default values for n, the numerator, and
 *    d, the denominator. Default value of n = 0 and d = 1.
 ********************************************************************************/
Rational::Rational()
{
  numer = 0;
  denom = 1;
}

/********************************************************************************
 * CONSTRUCTOR Rational: Class Rational
 *
  -------------------------------------------------------------------------------
 * This constructor initializes a Rational object with n, the numerator, which is
 * provided by the user; d, the denominator is set to the default value, 1.
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    The following needs previously defined values:
 *        n : the numerator
 *
 * POST-CONDITIONS
 *    Initializes a Rational object with user input for n, the numerator, and
 *    the default value for d, the denominator. Default value of d = 1
 ********************************************************************************/
Rational::Rational (int n) // IN: the numerator of a fraction
{
  numer = n;
  denom = 1;
}

/********************************************************************************
 * CONSTRUCTOR Rational: Class Rational
 *
  -------------------------------------------------------------------------------
 * This constructor initializes a Rational object with n, the numerator, and d,
 * the denominator, provided by the user.
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    The following needs previously defined values:
 *        n : the numerator
 *        d : the denominator
 *
 * POST-CONDITIONS
 *    Initializes a Rational object with values inputted by the user for n, the
 *    numerator, and d, the denominator.
 ********************************************************************************/
Rational::Rational (int n,  // IN: the numerator of a fraction
                    int d)  // IN: the denominator of a fraction
{
  if (d == 0)
  {
    std::cout << "Zero Division Error. Denominator cannot equal to 0.";
    exit(1);
  }
  numer = n;
  denom = d;
}

/********************************************************************************
 * METHOD add: Class Rational
 *
  -------------------------------------------------------------------------------
 * This method adds two Rational objects together, and returns the sum,
 * between both of them, as a Rational object.
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    The following needs previously defined values:
 *        - &x : a Rational object used for addition with the object calling
 *               the "add" member function
 *
 * POST-CONDITIONS
 *    Returns a Rational object which is the sum between the calling Rational
 *    and the Rational being passed into the function.
 ********************************************************************************/
const Rational Rational::add(const Rational &x) // IN: Rational object that will
                                                //     add to calling object
const
{
  Rational result;
  result.numer = x.numer * denom + numer * x.denom;
  result.denom = x.denom * denom;

  return result;
}

/********************************************************************************
 * METHOD subtract: Class Rational
 *
  -------------------------------------------------------------------------------
 * This methodsubtracts two Rational objects, and returns the
 * difference, between both of them, as a Rational object.
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    The following needs previously defined values:
 *        - &x : a Rational object used for subtraction with the object calling
 *               the "subtract" method
 *
 * POST-CONDITIONS
 *    Returns a Rational object which is the difference between the calling
 *    Rational and the Rational being passed into the method.
 ********************************************************************************/
const Rational Rational::subtract(const Rational &x) // IN: Rational object that
                                                     //     will subtract from
                                                     //     calling object
const
{
  Rational result;
  result.numer = numer * x.denom - x.numer * denom;
  result.denom = x.denom * denom;
  return result;
}

/********************************************************************************
 * METHOD multiply: Class Rational
 *
  -------------------------------------------------------------------------------
 * This method multiplies two Rational objects, and returns the product,
 * between both of them, as a Rational object.
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    The following needs previously defined values:
 *        - &x : a Rational object used for multiplication with the object
 *               calling the "multiply" method
 *
 * POST-CONDITIONS
 *    Returns a Rational object which is the product between the calling
 *    Rational and the Rational being passed into the method.
 ********************************************************************************/
const Rational Rational::multiply(const Rational &x) // IN: Rational object that
                                                     //     will be multiplied
                                                     //     with calling object
const
{
  Rational result;
  result.numer = numer * x.numer;
  result.denom = denom * x.denom;
  return result;
}

/********************************************************************************
 * METHOD divide: Class Rational
 *
  -------------------------------------------------------------------------------
 * This method divides two Rational objects, and returns the quotient,
 * between both of them, as a Rational object.
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    The following needs previously defined values:
 *        - &x : a Rational object used for division with the object calling the
 *               "divide" method
 *
 * POST-CONDITIONS
 *    Returns a Rational object which is the quotient between the calling
 *    Rational and the Rational being passed into the method.
 ********************************************************************************/
const Rational Rational::divide(const Rational &x) // IN: Rational object that
                                                   //     will divide the calling
                                                   //     object
const
{
  Rational result;
  result.numer = numer * x.denom;
  result.denom = denom * x.numer;
  return result;
}

/********************************************************************************
 * METHOD display: Class Rational
 *
  -------------------------------------------------------------------------------
 * This method displays the Rational object, calling the method, onto the
 * console, in fractional form.
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    The following does not need previously defined values.

 * POST-CONDITIONS
 *    This method returns a string for the display of the Rational
 ********************************************************************************/
string Rational::display() const
{
  string str;
  str = to_string(numer) + "/" + to_string(denom);
  return str;
}

/********************************************************************************
 * Overloaded preincrement operator: Class Rational
 *
  -------------------------------------------------------------------------------
 * This method overloads the preincrement operator to work on a Rational number
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    none
 *
 * POST-CONDITIONS
 *    Returns a Rational object which is incremented by 1/1
 ********************************************************************************/
Rational Rational::operator++()
{
  this->numer = this->numer + this->denom;
  return *this;
}

/********************************************************************************
 * Overloaded postincrement operator: Class Rational
 *
  -------------------------------------------------------------------------------
 * This method overloads the postincrement operator to work on a Rational number
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    none
 *
 * POST-CONDITIONS
 *    Returns a Rational object which is incremented by 1/1
 ********************************************************************************/
Rational Rational::operator++(int i)    //Dummy variable
{
  Rational temp = *this;
  this->numer = this->numer + this->denom;
  return temp;
}

/********************************************************************************
 * Overloaded predecrement operator: Class Rational
 *
  -------------------------------------------------------------------------------
 * This method overloads the predecrement operator to work on a Rational number
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    none
 *
 * POST-CONDITIONS
 *    Returns a Rational object which is decremented by 1/1
 ********************************************************************************/
Rational Rational::operator--()
{
  this->numer = this->numer - this->denom;
  return *this;
}

/********************************************************************************
 * Overloaded postdecrement operator: Class Rational
 *
  -------------------------------------------------------------------------------
 * This method overloads the postdecrement operator to work on a Rational number
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    none
 *
 * POST-CONDITIONS
 *    Returns a Rational object which is decremented by 1/1
 ********************************************************************************/
Rational Rational::operator--(int i)    //Dummy variable
{
  Rational temp = *this;
  this->numer = this->numer - this->denom;
  return temp;
}

/********************************************************************************
 * Overloaded less than operator: Class Rational
 *
  -------------------------------------------------------------------------------
 * This method overloads the less than operator to work on a Rational number
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    both sides must have initializes rationals
 *
 * POST-CONDITIONS
 *    Returns a bool for if the lhs is less than the rhs
 ********************************************************************************/
bool Rational::operator<(const Rational &rational)  //IN - rhs of comparison
{
    return (this->numer * rational.denom) < (rational.numer * this->denom);
}

/********************************************************************************
 * Overloaded greater than operator: Class Rational
 *
  -------------------------------------------------------------------------------
 * This method overloads the greater than operator to work on a Rational number
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    both sides must have initializes rationals
 *
 * POST-CONDITIONS
 *    Returns a bool for if the lhs is greater than the rhs
 ********************************************************************************/
bool Rational::operator>(const Rational &rational)  //IN - rhs of comparison
{
    return (this->numer * rational.denom) > (rational.numer * this->denom);
}

/********************************************************************************
 * Overloaded non equal operator: Class Rational
 *
  -------------------------------------------------------------------------------
 * This method overloads the not equals operator to work on a Rational number
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    both sides must have initializes rationals
 *
 * POST-CONDITIONS
 *    Returns a bool for if the lhs is not equal to the rhs
 ********************************************************************************/
bool Rational::operator!=(const  Rational &rational)    //IN - rhs of comparison
{
    return (this->numer * rational.denom) != (rational.numer * this->denom);
}

/********************************************************************************
 * Overloaded equal operator: Class Rational
 *
  -------------------------------------------------------------------------------
 * This method overloads the equals operator to work on a Rational number
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    both sides must have initializes rationals
 *
 * POST-CONDITIONS
 *    Returns a bool for if the lhs is equal to the rhs
 ********************************************************************************/
bool Rational::operator==(const  Rational &rational)    //IN - rhs of comparison
{
    return (this->numer * rational.denom) == (rational.numer * this->denom);
}

/********************************************************************************
 * Overloaded extraction operator: Class Rational
 *
  -------------------------------------------------------------------------------
 * This method overloads the extraction operator to work on a Rational number
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    lhs- ostream
 *    rhs- rational
 *
 * POST-CONDITIONS
 *    Returns a ostream for the output of the rational
 ********************************************************************************/
ostream& operator<<(ostream& out, const Rational& rational)
{
  out << rational.numer << '/' << rational.denom;
  return out;
}

/********************************************************************************
 * Overloaded insertion operator: Class Rational
 *
  -------------------------------------------------------------------------------
 * This method overloads the insertion operator to work on a Rational number
  -------------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    lhs- istream
 *    rhs- rational
 *
 * POST-CONDITIONS
 *    Returns a istream for the input of the rational
 ********************************************************************************/
istream& operator>>(istream& ins, Rational& rational)
{
  ins >> rational.numer;
  ins.get();
  ins >> rational.denom;
  return ins;
}
