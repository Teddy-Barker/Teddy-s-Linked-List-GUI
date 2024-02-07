#ifndef MYVECTOR_H
#define MYVECTOR_H

template <typename E>
class Vector
{
private:
    /*********************
    ** PRIVATE MEMBERS ***
    *********************/
    int sz;         //Size of the array being used
    int cap;        //Total capacity of the array
    E* data;        //Pointer to the beginning of the array

    /*********************
    ** PRIVATE METHODS ***
    *********************/
    void resize();
public:
    /*****************
    ** CONSTRUCTOR ***
    *****************/
    Vector();
    /*****************
    ** *DESTRUCTOR ***
    *****************/
    ~Vector();
    /***************
    *** MUTATORS ***
    ***************/
    void push_back(E value);
    void pop_back();
    void remove(int index);
    /***************
    ** ACCESSORS ***
    ***************/
    int size();
    E& operator[](int index);
};

/****************************************************************
* Vector
*   This class is a templated Vector class that manages a size,
*   capacity, and pointer. It is a simple vector with minimal
*   implementation and deals with garbage collection within the
*   class.
***************************************************************/

/*****************
** CONSTRUCTOR ***
*****************/
/**********************************************************
* Vector() : Class Vector
*_________________________________________________________
* Default Constructor: This constructor sets the size and
*   capacity of the vector to 1 and initializes a block of
*   memory for 1 element.
*_________________________________________________________
* PRE-CONDITIONS
*     none
*
* POST-CONDITIONS
*     Vector with size/cap 1 is initialized. The 1 value
*     contains a default constructor E();
***********************************************************/
template <typename E>
Vector<E>::Vector():sz(1),cap(1)
{
    data = new E[1];
}

/*****************
** *DESTRUCTOR ***
*****************/
/**********************************************************
* Vector() : Class Vector
*_________________________________________________________
* Destructor: This constructor manages deleting all memory
*   used by the vector.
*_________________________________________________________
* PRE-CONDITIONS
*     none
*
* POST-CONDITIONS
*     Vector is deleted, memory is completely freed
***********************************************************/
template <typename E>
Vector<E>::~Vector()
{
    delete[] data;
}

/***************
*** MUTATORS ***
***************/
/**********************************************************
* void push_back(E value) : Class Vector
*_________________________________________________________
* Mutator: This method pushes a new value to the back of the
*   vector
*_________________________________________________________
* PRE-CONDITIONS
*     E value - the desired value to be pushed to the back
*
* POST-CONDITIONS
*     Vector contains a new element at the back, meaning size
*     is increased by 1. If capacity does not allow for a
*     new element to be pushed back, resize() is called to
*     double the capacity.
***********************************************************/
template <typename E>
void Vector<E>::push_back(E value)
{
    if(sz>=cap)
        resize();
    data[sz] = value;
    sz += 1;
}

/**********************************************************
* void pop_back() : Class Vector
*_________________________________________________________
* Mutator: This method removes the last element of the vector
*_________________________________________________________
* PRE-CONDITIONS
*     none
*
* POST-CONDITIONS
*     Vector's final element is removed. Size reduced by one,
*     and if there were no elements to begin with, returns
***********************************************************/
template <typename E>
void Vector<E>::pop_back()
{
    if(sz == 0)
        return;
    data[sz-1] = E();
    sz -= 1;
}

/**********************************************************
* void resize() : Class Vector
*_________________________________________________________
* Mutator: This method doubles the capacity of the vector
*_________________________________________________________
* PRE-CONDITIONS
*     none
*
* POST-CONDITIONS
*     Vector's capacity is doubled, if cap is 0, it will give
*     a new size and cap of 1.
***********************************************************/
template <typename E>
void Vector<E>::resize()
{
    if(cap == 0)
    {
        data = new E[1];
        sz = 1;
        cap = 1;
        return;
    }
    E* temp = data;
    data = new E[cap*2];
    for(int i = 0; i < sz; i++)
        data[i] = temp[i];
    cap*=2;
    delete[] temp;
}

/**********************************************************
* void remove(int index) : Class Vector
*_________________________________________________________
* Mutator: This method removes the element positioned at
*   a given index
*_________________________________________________________
* PRE-CONDITIONS
*     int index - position of element to be removed
*
* POST-CONDITIONS
*     Vector removes 1 element and size is reduced by one.
*     Throws if index is out of bounds.
***********************************************************/
template <typename E>
void Vector<E>::remove(int index)
{
    if(index < 0 || index >= sz)
        throw;
    for(int i = index; i < sz-1; i++)
        data[i] = data[i+1];
    pop_back();
}

/***************
** ACCESSORS ***
***************/

/**********************************************************
* void size() : Class Vector
*_________________________________________________________
* Accessor: This method returns the size of the vector
*_________________________________________________________
* PRE-CONDITIONS
*     none
*
* POST-CONDITIONS
*     sz is returned
***********************************************************/
template <typename E>
int Vector<E>::size()
{
    return sz;
}

/**********************************************************
* E& operator[](int index) : Class Vector
*_________________________________________________________
* Accessor: This method overloads the bracket operator to
*   return the dereferenced index of data
*_________________________________________________________
* PRE-CONDITIONS
*     int index - index to be dereferenced
*
* POST-CONDITIONS
*     [] operator is overloaded to accept index and dereference
*     data pointer.
***********************************************************/
template <typename E>
E& Vector<E>::operator[](int index)
{
    return data[index];
}


#endif // MYVECTOR_H
