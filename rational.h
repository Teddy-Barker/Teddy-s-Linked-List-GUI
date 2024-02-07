#ifndef _RATIONAL
#define _RATIONAL
#include <iostream>
using namespace std;

class Rational
{
  private:
    int numer; // IN: numerator
    int denom; // IN: denomenator

  public:
    /******************************
    **       CONSTRUCTORS        **
    *******************************/

    Rational();
    Rational(int n);
    Rational(int n, int d);

    /******************************
    **         MUTATORS          **
    *******************************/
    const Rational add(const Rational &x) const;
    const Rational subtract(const Rational &x) const;
    const Rational multiply(const Rational &x) const;
    const Rational divide(const Rational &x) const;

    /******************************
    **         ACCESSOR          **
    *******************************/
    string display() const;

    Rational operator++();
    Rational operator++(int);
    Rational operator--();
    Rational operator--(int);
    bool operator<(const Rational&);
    bool operator>(const Rational&);
    bool operator!=(const  Rational&);
    bool operator ==(const Rational&);
    friend ostream& operator<<(ostream& out, const Rational& rational);
    friend istream& operator>>(istream& ins, Rational& rational);
};

/********************************************************************************
 * Rational Class
 *   This class represents a fraction object. It manages 2
 *   attributes, numer and denom (Representing the numerator and
 *   denominator)
 ********************************************************************************/


/******************************
******** CONSTRUCTORS *********
*******************************/

/********************************************************************************
 * Rational(int n)
 *   Constructor; Initializes class attributes with default values
 *   Parameters : none
 *   Return     : none
 ********************************************************************************/

/********************************************************************************
 * Rational(int n)
 *   Constructor; Initializes class attributes
 *   Parameters : n (int)   // IN - the numerator
 *   Return     : none
 ********************************************************************************/

/********************************************************************************
 * Rational(int n, int d)
 *   Constructor; Initializes class attributes
 *   Parameters : n (int)   // IN - the numerator
 *              : d (int)   // IN - the denominator
 *   Return     : none
 ********************************************************************************/


/******************************
********** ACCESSOR ***********
*******************************/

/********************************************************************************
 * const Rational add(const Rational &x) const;
 *
 *   Accessor; This method will add the calling rational with another rational.
 *-------------------------------------------------------------------------------
 *  Parameter: &x (Rational)    // IN - a Rational object
 *-------------------------------------------------------------------------------
 *  Return: result (Rational)
 ********************************************************************************/

/********************************************************************************
 * const Rational subtract(const Rational &x) const;
 *
 *   Accessor; This method will subtract a rational argument from the calling
 *   rational.
 *-------------------------------------------------------------------------------
 *  Parameter: &x (Rational)    // IN - a Rational object
 *-------------------------------------------------------------------------------
 *  Return: result (Rational)
 ********************************************************************************/

/********************************************************************************
 * const Rational multiply(const Rational &x) const;
 *
 *   Accessor; This method will multiply the calling rational with another
 *   rational.
 *-------------------------------------------------------------------------------
 *  Parameter: &x (Rational)    // IN - a Rational object
 *-------------------------------------------------------------------------------
 *  Return: result (Rational)
 ********************************************************************************/

/********************************************************************************
 * const Rational divide(const Rational &x) const;
 *
 *   Accessor; This method will divide a rational argument from the calling
 *   rational.
 *-------------------------------------------------------------------------------
 *  Parameter: &x (Rational)    // IN - a Rational object
 *-------------------------------------------------------------------------------
 *  Return: result (Rational)
 ********************************************************************************/

/********************************************************************************
 * string display() const;
 *
 *   Accessor; This method will convert the Rational to a string and return it.
 *-------------------------------------------------------------------------------
 *  Parameter: none
 *-------------------------------------------------------------------------------
 *  Return: string containing rational
 ********************************************************************************/

#endif
