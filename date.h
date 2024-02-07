#ifndef DATE
#define DATE

#include <string>
using namespace std;

class Date
{
  public:
    /******************************
    ********* CONSTRUCTORS ********
    ******************************/
    Date();                                              // CONSTRUCTOR - default
    Date(unsigned m, unsigned d, unsigned y);            // CONSTRUCTOR - month as int
    Date(const string &mn, unsigned d, unsigned y);      // CONSTRUCTOR - month as string

    /******************************
    ********* ACCESSORS ***********
    ******************************/
    string display() const;
    void printAlpha() const;
    friend bool operator<(const Date &date1, const Date &date2);
    friend bool operator>(const Date &date1, const Date &date2);
    bool operator==(const Date &);

  private:
    /******************************
    ********** MUTATORS  **********
    ******************************/
    bool isLeap(unsigned y) const;
    unsigned daysPerMonth( unsigned m, unsigned y ) const;
    string name( unsigned m ) const;
    unsigned number( const string &mn ) const;

    /******************************
    ****** MEMBER VARIABLES *******
    ******************************/
    unsigned day;     //IN - day numerical value
    unsigned month;   //IN - month numerical value
    string monthName; //IN - month string value
    unsigned year;    //IN - year numerical value

};

/****************************************************************
* Date Class
*   This class represents a date object. It manages 4 attributes,
*   day, year and month (unsigned month and string monthName)
***************************************************************/

/******************************
******** CONSTRUCTORS  ********
******************************/

/****************************************************************
* Date ();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none
***************************************************************/

/****************************************************************
* Date(unsigned m, unsigned d, unsigned y);
*   Constructor; Initialize class attributes
*   Parameters: m, IN - month unsigned int
*               d, IN - day unsigned int
*               y  IN - year unsigned int
*   Return: none
***************************************************************/

/****************************************************************
* Date(const string &mn, unsigned d, unsigned y);
*   Constructor; Initialize class attributes
*   Parameters: mn, IN - month name as string
*               d,  IN - day unsigned int
*               y   IN - year unsigned int
*   Return: none
***************************************************************/

/******************************
********* ACCESSORS ***********
******************************/

/****************************************************************
* string display() const;
*   Accessor; This function will return the numerical date as a
*           string
*   Parameters: none
*   Return: none
***************************************************************/

/****************************************************************
* void printAlpha() const;
*   Accessor; This function will output the string of the date
*   Parameters: none
*   Return: none
***************************************************************/

/****************************************************************
* friend bool operator<(const Date &date1, const Date &date2);
*   Accessor; This function will return a boolean if the left hand
*   side is greater than the right hand side
*   Return: bool
***************************************************************/

/****************************************************************
* friend bool operator>(const Date &date1, const Date &date2);
*   Accessor; This function will return a boolean if the right hand
*   side is greater than the left hand side
*   Return: bool
***************************************************************/

/******************************
********** MUTATORS  **********
******************************/

/****************************************************************
* bool isLeap(unsigned y) const;
*   Mutator; This function will return a bool representing if
*            the year passed as the argument was a leap year.
*   Parameters: y IN - year to determine leap status
*   Return: flag (bool)
***************************************************************/

/****************************************************************
* unsigned daysPerMonth( unsigned m, unsigned y ) const;
*   Mutator; This function will return a unsigned int corresponding
*            to the number of days in the given month.
*   Parameters: y, IN - year to determine leap status
*               m, IN - month to determine day count
*   Return: days (unsigned)
***************************************************************/

/****************************************************************
* string name( unsigned m ) const;
*   Mutator; This function will return a string corresponding to
*            the appropriate month numerical value.
*   Parameters: m, IN - month to determine string value
*   Return: mName (string)
***************************************************************/

/****************************************************************
* unsigned number( const string &mn ) const;
*   Mutator; This function will return a unsigned int corresponding
*            to the appropriate month name.
*   Parameters: mn, IN - month to determine numerical value
*   Return: mNum (unsigned int)
***************************************************************/


#endif
