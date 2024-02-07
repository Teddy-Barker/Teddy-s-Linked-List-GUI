#include "complex.h"

/**********************************************************
*
* Constructor Complex(): Class Complex
*_________________________________________________________
* This constructor initializes the comlpex object to 0 + 0i
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*     This constructor initializes the complex number object
* to 0 + 0i
***********************************************************/
Complex::Complex():real(0),imaginary(0){}

/**********************************************************
*
* Constructor Complex(string &s): Class Complex
*_________________________________________________________
* This constructor initializes the comlpex object by parsing
* a string
*_________________________________________________________
* PRE-CONDITIONS
*   s - string to be parsed
*
* POST-CONDITIONS
*     This constructor initializes the complex number object
* to the parameter value
***********************************************************/
Complex::Complex(string &s)     //IN - string to be parsed
{
    int pos; //Position of plus or minus
    pos = -1;
    //PROCESSING - iterating to find pos
    for(unsigned i = 0; i < s.size(); i++)
    {
        if(s[i] == '+' || s[i] == '-')
            pos = i;
    }
    if(pos > 0) //has + or -
    {
        real = stod(s.substr(0, pos));
        imaginary = stod(s.substr(pos));
    }
    else if (s == "i")
    {
        real = 0;
        imaginary = 1;
    } // just i
    else if (s == "-i")
    {
        real = 0;
        imaginary = -1;
    }
    else
    {
        if(s[s.size() - 1] == 'i')
            imaginary = stod(s.substr(0,s.size()));
        else
            real = stod(s.substr(0,s.size()));
    }
}

/**********************************************************
*
* Constructor Complex(double real_part): Class Complex
*_________________________________________________________
* This constructor initializes the comlpex object to
* real_part + 0i, where real_part is a double
*_________________________________________________________
* PRE-CONDITIONS
*   real_part - the value of the non-imaginary part
*
* POST-CONDITIONS
*     This constructor initializes the complex number object
* to real_part + 0i, where real_part is non imaginary
***********************************************************/
Complex::Complex(double real_part):real(real_part),imaginary(0){}

/**********************************************************
*
* Constructor Complex(double real_part, double imaginary_part):
*    Class Complex
*_________________________________________________________
* This constructor initializes the comlpex object to
* real_part + 0i, where real_part is a double
*_________________________________________________________
* PRE-CONDITIONS
*   real_part - the value of the non-imaginary part
*   imaginary_part - the value of the i coefficient
*
* POST-CONDITIONS
*     This constructor initializes the complex number object
* to real_part + imaginary_part*i, where real_part is non
* imaginary and imaginary_part is the coefficient of i
***********************************************************/
Complex::Complex(double real_part, double imaginary_part):real(real_part),imaginary(imaginary_part){}

/**********************************************************
*
* Copy Constructor Complex(const Complex&c): Class Complex
*_________________________________________________________
* This constructor initializes the comlpex object to
* the attributes of another complex number
*_________________________________________________________
* PRE-CONDITIONS
*   c - copied complex number
*
* POST-CONDITIONS
*     This constructor initializes the complex number object
* to another object
***********************************************************/
Complex::Complex(const Complex&c)   //IN - source of copy
{
    real = c.real;
    imaginary = c.imaginary;
}

/**********************************************************
*
* Destructor ~Complex();
*_________________________________________________________
* This destructor frees memory of a complex object
*_________________________________________________________
* PRE-CONDITIONS
*   none
* POST-CONDITIONS
*     complex is freed
***********************************************************/
Complex::~Complex(){}

/**********************************************************
*
* Overloaded Operator bool operator==(const Complex &com1,
* const Complex &com2): Class Complex
*_________________________________________________________
* This overloads the comparison operator to return a bool
* that represents if two Complex number ojbects are equal
*_________________________________________________________
* PRE-CONDITIONS
*   com1 - the first complex number object
*   com2 - the second complex number object
*
* POST-CONDITIONS
*     This operator returns a bool based on whether the two
* complex number objects are equal.
***********************************************************/
bool operator==(const Complex &com1,    //IN - lhs for comparison
                const Complex &com2)    //IN - rhs for comparison
{
  return (com1.real==com2.real && com1.imaginary==com2.imaginary);
}

/**********************************************************
*
* Overloaded Operator bool operator<(const Complex &com1,
* const Complex &com2): Class Complex
*_________________________________________________________
* This overloads the comparison operator to return a bool
* that represents if two Complex number ojbects are equal
*_________________________________________________________
* PRE-CONDITIONS
*   com1 - the first complex number object
*   com2 - the second complex number object
*
* POST-CONDITIONS
*     This operator returns a bool based on whether the first
*     is less than the second.
***********************************************************/
bool operator<(const Complex &com1,     //IN - lhs for comparison
               const Complex &com2)     //IN - rhs for comparison
{
    //PROCESSING - checking real value, then imaginary value
    //             for comparison
    if(com1.real<com2.real)
        return true;
    else if(com1.real == com2.real && com1.imaginary < com2.imaginary)
        return true;
    else
        return false;
}

/**********************************************************
*
* Overloaded Operator bool operator>(const Complex &com1,
* const Complex &com2): Class Complex
*_________________________________________________________
* This overloads the comparison operator to return a bool
* that represents if two Complex number ojbects are equal
*_________________________________________________________
* PRE-CONDITIONS
*   com1 - the first complex number object
*   com2 - the second complex number object
*
* POST-CONDITIONS
*     This operator returns a bool based on whether the first
*     is greater than the second.
***********************************************************/
bool operator>(const Complex &com1,     //IN - lhs for comparison
               const Complex &com2)     //IN - rhs for comparison
{
    //PROCESSING - checking real value, then imaginary value
    //             for comparison
    if(com1.real>com2.real)
        return true;
    else if(com1.real == com2.real && com1.imaginary > com2.imaginary)
        return true;
    else
        return false;
}

/**********************************************************
*
* Overloaded Operator const Complex operator+(const Complex
* &com2)const : Class Complex
*_________________________________________________________
* This overloads the addition operator to accept addition
* of two complex number objects returning a new objcect of
* type Complex that has sum values of the two arguments.
*_________________________________________________________
* PRE-CONDITIONS
*   com2 - the second complex number object to be added
*
* POST-CONDITIONS
*     This operator returns an object of type Complex with
* the resulting sum of the two arguments.
***********************************************************/
const Complex Complex::operator+(const Complex &com2) const     //IN - rhs of addition
{
  return Complex(real + com2.real, imaginary + com2.imaginary);
}

/**********************************************************
*
* Overloaded Operator const Complex operator-(const Complex
* &com2)const : Class Complex
*_________________________________________________________
s(const Complex
* &com2)const : Class Complex
*_________________________________________________________
* This overloads the subtraction operator to accept subtra-
* ction of two complex number objects returning a new
* objcect of type Complex that has sum values of the two
* arguments.
*_________________________________________________________
* PRE-CONDITIONS
*   com2 - the second complex number object to be subtracted
*
* POST-CONDITIONS
*     This operator returns an object of type Complex with
* the resulting difference between the two arguments.
***********************************************************/
const Complex Complex::operator-(const Complex &com2) const //IN - rhs of subtraction
{
  return Complex(real - com2.real, imaginary - com2.imaginary);
}

/**********************************************************
*
* Overloaded Operator const Complex operator*(const Complex
* &com2)const : Class Complex
*_________________________________________________________
* This overloads the multiplication operator to accept
* multiplication of two complex number objects returning
* a new objcect of type Complex that has the product value
* of the two arguments.
*_________________________________________________________
* PRE-CONDITIONS
*   com2 - the second complex number object to be added
*
* POST-CONDITIONS
*     This operator returns an object of type Complex with
* the resulting product of the two arguments.
***********************************************************/
const Complex Complex::operator*(const Complex&com2) const  //IN - rhs of multiplication
{
  return Complex(real*com2.real - imaginary*com2.imaginary, real*com2.imaginary + imaginary*com2.real);
}

/**********************************************************
*
* Overloaded Operator ostream & operator << (ostream &cout,
*                   const Complex &c) : Class Complex
*_________________________________________________________
* This overloads the insertion operator to output a complex
* number object properly in the form a + bi
*_________________________________________________________
* PRE-CONDITIONS
*   c - the complex number object to be output to the screen
*
* POST-CONDITIONS
*     This operator outputs to the screen a + bi based upon
* the complex number object being inserted.
***********************************************************/
ostream & operator << (ostream &cout,       //IN - ostream for extraction
                       const Complex &c)    //IN - Complex number to be displayed
{
  cout << c.real;
  if(c.imaginary >= 0)
    cout << "+";
  cout << c.imaginary << "i";
  return cout;
}

/**********************************************************
*
* Overloaded Operator ostream & operator << (ostream &cout,
*                 const Complex &c) : Class Complex
*_________________________________________________________
* This overloads the extraction operator to input a complex
* number object properly from the form a + bi
*_________________________________________________________
* PRE-CONDITIONS
*   c - the complex number object to be input from the screen
*
* POST-CONDITIONS
*     This operator inputs from the screen a complex number
* object of the orientation: a + bi
***********************************************************/
istream & operator >> (istream &cin,  //IN - istream for insertion
                       Complex &c)    //IN - Complex number to be inputed
{

  string tempStr;
  getline(cin,tempStr);
  int pos;
  pos = -1;
  for(unsigned i = 0; i < tempStr.size(); i++)
  {
    if(tempStr[i] == '+' || tempStr[i] == '-')
      pos = i;
  }
  if(pos > 0) //has + or -
  {
    c.real = stod(tempStr.substr(0, pos));
    c.imaginary = stod(tempStr.substr(pos));
  }
  else if (tempStr == "i")
  {
    c.real = 0;
    c.imaginary = 1;
  } // just i
  else if (tempStr == "-i")
  {
    c.real = 0;
    c.imaginary = -1;
  }
  else
  {
    if(tempStr[tempStr.size() - 1] == 'i')
      c.imaginary = stod(tempStr.substr(0,tempStr.size()));
    else
      c.real = stod(tempStr.substr(0,tempStr.size()));
  }


  return cin;
}

/**********************************************************
*
* string display() const Class Complex
*_________________________________________________________
* This returns the complex number in the form of a c++ string
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*     Returns string with the contents of the Complex number
***********************************************************/
string Complex::display() const
{
    string str;
    str = to_string(real);
    if(imaginary >= 0)
        str += "+";
    str += to_string(imaginary) + "i";
    return str;
}

/**********************************************************
*
* Overloaded assignment operator Complex operator=(const Complex&c)
*    Class Complex
*_________________________________________________________
* This operator initializes the comlpex object to
* the attributes of another complex number
*_________________________________________________________
* PRE-CONDITIONS
*   c - copied complex number
*
* POST-CONDITIONS
*     This constructor initializes the complex number object
* to another object
***********************************************************/
Complex Complex::operator=(const Complex&c) //IN - complex number for the source
{
    real = c.real;
    imaginary = c.imaginary;
    return *this;
}
