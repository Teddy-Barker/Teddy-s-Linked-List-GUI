#include <iostream>
#include <string>
#include "date.h"

using namespace std;

/**********************************************************
*
* Constructor Date(): Class Date
*_________________________________________________________
* This constructor recieves no arguments and sets the data
* as 1/ 1/ 2000
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*     This constructor initializes the date at 1/1/2000
***********************************************************/
Date::Date()
{
  //Setting date to 1/1/2000
  day = 1;
  month = 1;
  monthName = "January";
  year = 2000;
}

/**********************************************************
*
* Constructor Date(): Class Date
*_________________________________________________________
* This Constructor recieves no arguments and sets the data
* as m/d/y
*_________________________________________________________
* PRE-CONDITIONS
*   unsigned m - month
*	unsigned d - day
*   unsigned y - year
*
* POST-CONDITIONS
*     This Constructor initializes the date at m/d/y
***********************************************************/
Date::Date(unsigned m,  //IN - month numerical
           unsigned d,  //IN - day numerical
           unsigned y)  //IN - year numerical
{
  bool monthFlag, dayFlag;// flags to help processs invalid dates

  //PROCESSING - Initializing helping bools
  monthFlag = true;
  dayFlag = true;

  //PROCESSING - Constructing date values
  if(m > 12)
  {
    month = 12;
    monthFlag = false;
  }
  else if(m == 0)
  {
      month = 1;
      monthFlag = false;
  }
  else
  {
    month = m;
  }

  if(d > daysPerMonth(m, y))
  {
    day = daysPerMonth(m, y);
    dayFlag = false;

  }
  else if(d == 0)
  {
      day = 1;
      dayFlag = false;
  }
  else
  {
    day = d;
  }

  year = y; // setting year
  monthName = name(month);  // setting month name

  //OUTPUT - failure message
  if(monthFlag == false || dayFlag == false)
    cout << "Invalid date values: Date corrected to "
         << month
         << "/"
         << day
         << "/"
         << year
         << ".\n";
}

/**********************************************************
*
* Constructor Date(): Class Date
*_________________________________________________________
* This Constructor recieves no arguments and sets the data
* as mn/d/y with a string as month name
*_________________________________________________________
* PRE-CONDITIONS
*   string mn  - month name as string
*	unsigned d - day
*   unsigned y - year
*
* POST-CONDITIONS
*     This Constructor initializes the date at mn/d/y
***********************************************************/
Date::Date(const string &mn, //IN - month alphabetic
           unsigned d,       //IN - day numerical
           unsigned y)       //IN - year numerical
{
    bool monthFlag, dayFlag; // flags to help processs invalid dates
    int m; // int to store month value
    string temp; //temporary string to store month name

    //PROCESSING - Initializing helping variables
    monthFlag = true;
    dayFlag = true;
    temp = mn;

    //PROCESSING - keeping first letter caps, everything else lower
    for(unsigned i = 0; i < temp.size(); i++)
    {
        temp[i] = tolower(temp[i]);
    }
    temp[0] = toupper(temp[0]);

    m = number(temp); // Finding number value of month string

    //PROCESSING - Constructing date values
    if(m > 12)
    {
      month = 12;
      monthFlag = false;
    }
    else if(m == 0)
    {
        month = 1;
        day = 1;
        year = 2000;
        cout << "Invalid month name: the Date was set to 1/1/2000.\n";
    }
    else
    {
      month = m;
    }

    if(d > daysPerMonth(m, y) && m != 0)
    {
      day = daysPerMonth(m, y);
      dayFlag = false;

    }
    else if(d == 0 && m != 0)
    {
        day = 1;
        dayFlag = false;
    }
    else if(m != 0)
    {
      day = d;
    }

    if(m != 0)
      year = y; // setting year

    monthName = name(month); // setting month name

    //OUTPUT - failure message
    if(monthFlag == false || dayFlag == false)
      cout << "Invalid date values: Date corrected to "
           << month
           << "/"
           << day
           << "/"
           << year
           << ".\n";
}

/**********************************************************
*
* Method display: Class Date
*_________________________________________________________
* This method receives no arguments and prints the date in
*   the form "m/d/y".
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* day
* month
* monthName
* year
*
* POST-CONDITIONS
*     This function will output the date to the screen in
* numerical value.
***********************************************************/
string Date::display() const
{
  string str;
  str = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
  return str;
}

/**********************************************************
*
* Method printAlpha: Class Date
*_________________________________________________________
* This method receives no arguments and prints the date in
*   the form "monthName day, year".
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* day
* month
* monthName
* year
*
* POST-CONDITIONS
*     This function will output the date to the screen in
* the form where the month is printed as a string.
***********************************************************/
void Date::printAlpha() const
{
  //OUTPUT - printing the alphanumeric date
  cout << monthName
       << " "
       << day
       << ", "
       << year;
}

/**********************************************************
*
* Method isLeap: Class Date
*_________________________________________________________
* This method receives one unsigned int argument and
*   determines if it was a leap year or not.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* y - the year to be evaluated must be passed as an
*     argument
*
* POST-CONDITIONS
*     This function will return a bool representing wether
*     or not the year passed was a leap year.
***********************************************************/
bool Date::isLeap( unsigned y ) //In - year to be evaluated
                   const
{
  bool flag; // OUT - bool to be returned

  //PROCESSING - processing the leap status of the parameter y
  if(y % 4 == 0)
  {
    if(y % 100 == 0)
    {
      if(y % 400 == 0)
        flag = true;
      else
        flag = false;
    }
    else
      flag = true;
  }
  else
  {
    flag = false;
  }

  return flag; // Return flag as bool if y was leap
}

/**********************************************************
*
* Method daysPerMonth: Class Date
*_________________________________________________________
* This method receives no arguments and prints the date in
*   the form "m/d/y".
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* m - month that you want to find days in
* y -  year to determine leap status
*
* POST-CONDITIONS
*     This function will return an integer for the amount of
* days the passed month argument has based upon if it is
* a leap year or not.
***********************************************************/
unsigned Date::daysPerMonth( unsigned m,  //In - month to be evaluated
                             unsigned y ) //In - year to be evaluated
                             const
{
  unsigned days; // OUT - days to be returned

  //PROCESSING - determining each days per month case, default 31 days
  switch(m)
  {
    case 2:
    {
      if(isLeap(y))
        days = 29;
      else
        days = 28;
      break;
    }
    case 4: days = 30; break;
    case 6: days = 30; break;
    case 9: days = 30; break;
    case 11: days = 30; break;
    default: days = 31; break;
  }

  return days; // Return days as unsigned int
}

/**********************************************************
*
* Method name: Class Date
*_________________________________________________________
* This method receives one argument representing a month
* that you want to get the string for.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* m - month that you want to find the string for
*
* POST-CONDITIONS
*     This function returns the string value corresponding
* to the month value that was passed.
***********************************************************/
string Date::name( unsigned m // IN - month integer to be processed
                   ) const
{
  string mName; // OUT - month name to be returned

  //PROCESSSING - determining the appropriate string for the given month
    switch(m)
    {
        case 1: mName = "January"; break;
        case 2: mName = "February"; break;
        case 3: mName = "March"; break;
        case 4: mName = "April"; break;
        case 5: mName = "May"; break;
        case 6: mName = "June"; break;
        case 7: mName = "July"; break;
        case 8: mName = "August"; break;
        case 9: mName = "September"; break;
        case 10: mName = "October"; break;
        case 11: mName = "November"; break;
        case 12: mName = "December"; break;
    }

    return mName; // Return month name as string
}

/**********************************************************
*
* Method number: Class Date
*_________________________________________________________
* This method receives one argument representing a month
* string that you want to get the numerical value for.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* mn - month that you want to find the numerical value for
*
* POST-CONDITIONS
*     This function returns the numerical value corresponding
* to the month string that was passed. The mn parameter is
* passed by constant reference.
***********************************************************/
unsigned Date::number( const string &mn //IN - month name to be processed
                       ) const
{
  unsigned mNum; // OUT - month number

  //PROCESSING - determining the corresponding int based on the string
  if (mn == "January")
    mNum = 1;
  else if(mn == "February")
    mNum = 2;
  else if(mn == "March")
    mNum = 3;
  else if(mn == "April")
    mNum = 4;
  else if(mn == "May")
    mNum = 5;
  else if(mn == "June")
    mNum = 6;
  else if(mn == "July")
    mNum = 7;
  else if(mn == "August")
    mNum = 8;
  else if(mn == "September")
    mNum = 9;
  else if(mn == "October")
    mNum = 10;
  else if(mn == "November")
    mNum = 11;
  else if (mn == "December")
    mNum = 12;
  else
    mNum = 0;

  return mNum; // Return month as unsigned int
}

/**********************************************************
*
* Overloaded Operator bool operator<(const Date &date1,
* const Date &date2): Class Date
*_________________________________________________________
* This overloads the comparison operator to return a bool
* that represents the comparison of two Dates
*_________________________________________________________
* PRE-CONDITIONS
*   date1 - the first date object
*   date2 - the second date object
*
* POST-CONDITIONS
*     This operator returns a bool based on whether the first
*     is less than the second.
***********************************************************/
bool operator<(const Date &date1,   //IN - lhs for comparison
               const Date &date2)   //IN - rhs for comparison
{
    if(date1.year < date2.year)
        return true;
    else if(date1.year == date2.year
            && date1.month < date2.month)
        return true;
    else if(date1.year == date2.year
            && date1.month == date2.month
            && date1.day < date2.day)
        return true;
    else
        return false;
}

/**********************************************************
*
* Overloaded Operator bool operator>(const Date &date1,
* const Date &date2): Class Date
*_________________________________________________________
* This overloads the comparison operator to return a bool
* that represents the comparison of two Dates
*_________________________________________________________
* PRE-CONDITIONS
*   date1 - the first date object
*   date2 - the second date object
*
* POST-CONDITIONS
*     This operator returns a bool based on whether the first
*     is greater than the second.
***********************************************************/
bool operator>(const Date &date1,   //IN - lhs for comparison
               const Date &date2)   //IN - rhs for comparison
{
    if(date1.year > date2.year)
        return true;
    else if(date1.year == date2.year
            && date1.month > date2.month)
        return true;
    else if(date1.year == date2.year
            && date1.month == date2.month
            && date1.day > date2.day)
        return true;
    else
        return false;
}

/**********************************************************
*
* Overloaded Operator bool operator==(const Date &): Class Date
*_________________________________________________________
* This overloads the comparison operator to return a bool
* that represents the comparison of two Dates
*_________________________________________________________
* PRE-CONDITIONS
*   d - date being comapred
*
* POST-CONDITIONS
*     This operator returns a bool based on whether the dates
*     are equal
***********************************************************/
bool Date::operator==(const Date &d)    //IN - Date to be assigned
{
    return(day == d.day && month == d.month && year == d.year);
}
