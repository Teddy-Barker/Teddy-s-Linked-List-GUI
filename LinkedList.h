#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

/***************************************************
* Node : struct
*   This struct is a node with data of type E, and
*   pointer to the next node.
****************************************************/
template<typename E>
struct Node{
    E data;
    Node *next;
    Node( E data ) : data(data), next(0) {}
};

/***************************************************
* listEmpty : Class
*   This class is an exception class for an empty list
*   inherited from stdx::exception. Overrides what()
****************************************************/
class listEmpty : public std::exception
{
    const char * what () const throw ()
    {
        return "List is Empty";
    }
};



/***************************************************
* Linked List : Class
*   This class is a list of linked nodes that is temp-
*   lated to store any data type. It manages a head
*   and tail pointer.
****************************************************/
template<typename E>
class LinkedList
{
  private:
    /****************************
    * PRIVATE MEMBER VARIABLES **
    ****************************/
    Node<E>* head;     // CALC - first item in list
    Node<E>* tail;     // CALC - last item in list
    /*****************************
    ** PRIVATE MEMBER FUNCTIONS **
    *****************************/
    int countNodes(Node<E> *ptr) const;
    E findSum(Node<E> *ptr) const;
  public:
/***************
* CONSTRUCTOR **
***************/
/****************************************************************
    LinkedList
      Creates a list of 0 items. Sets head and tail to null
****************************************************************/
    LinkedList();
/****************************************************************
    LinkedList(const LinkedList& source)
      Copy Constructor
****************************************************************/
    LinkedList(const LinkedList<E>& source);

/***************
** DESTRUCTOR **
***************/
/****************************************************************
    ~LinkedList
      Destroys linked list by deleting any memory and setting
      head and tail to null
****************************************************************/
    ~LinkedList();

/*****************
** NESTED CLASS **
*****************/
/****************************************************************
    Iterator : Class
      This class manages one attribute of the current node and
      Has the ability to iterate through the list for ease of use.
****************************************************************/
    class Iterator
    {
        private:
        /****************************
        * PRIVATE MEMBER VARIABLES **
        ****************************/
            Node<E> * current;
        public:
        /*****************
        ** CONSTRUCTORS **
        *****************/
            Iterator();  //Default Constructor
            Iterator( Node<E> *ptr); //One parameter constructor

        /***************
        *** ACCESSORS **
        ***************/
            E operator*();     //Overloaded Dereference operator
            bool operator==(const Iterator& right) const;    //Overloaded Equal operator
            bool operator!=(const Iterator& right) const;    //Overloaded NotEqual operator

        /***************
        *** MUTATORS ***
        ***************/
            Iterator operator++();   //Overloaded Preincrement operator
    };

/***************
*** ACCESSORS **
***************/
/****************************************************************
    operator=
        Overloads the assignment operator to copy a list.
****************************************************************/
    LinkedList & operator=( const LinkedList<E>& source );
/****************************************************************
    display
        Prints the values of each 'Node<E>' in between 'head'
        and 'tail'
****************************************************************/
    void display() const;

/****************************************************************
    isEmpty
         This method takes no arguments and removes all duplicate
    values after the original value.
****************************************************************/
    bool isEmpty( );
/****************************************************************
    begin
         This method takes no arguments and returns an iterator
    at the beginning
****************************************************************/
    Iterator begin();
/****************************************************************
    end
         This method takes no arguments and returns and iterator
    pointing to null
****************************************************************/
    Iterator end();
/****************************************************************
    front
         This method takes no arguments and returns the first node's
    data
****************************************************************/
    const E& front() const throw();
/****************************************************************
    back
         This method takes no arguments and returns the last
     node's data
****************************************************************/
    const E& back() const throw();
/****************************************************************
    length
         This method takes no arguments and returns an int for
    the size of teh list.
****************************************************************/
    int length() const;
/****************************************************************
    sum
         This method takes no arguments and returns the sum of
    all nodes.
****************************************************************/
    E sum() const;

/***************
*** MUTATORS ***
***************/
/****************************************************************
    clear
        This completely clears the list and sets head and tail to
    nullptr.
****************************************************************/
    void clear();
/****************************************************************
    push_front
        value - value of the new node inserted at beginning of
        list
    This adds a node at the begginig of list. Head points to
    the new node. If the new node is the first node, then tail
    will also point to new node.
****************************************************************/
    void push_front(const E& value);

/****************************************************************
    pop_front
      This removes the node at the front of the list. Head will
      point to the next node in the list. If the list is empty,
      then nothing is changed.
****************************************************************/
    void pop_front();
/****************************************************************
    push_back
        value - value of the new node inserted at end of
        list
    This adds a node at the end of list. Tail and Previously last
    node point to the new node.
****************************************************************/
    void push_back(const E& value);

/****************************************************************
    select_sort
         This method takes no arguments and sorts the list
    using the selection sort algorithm
****************************************************************/
    void select_sort();

/****************************************************************
    insert_sorted
         This method takes one argument for the data to be inserted
    and adds the value sorted into the list. Does not sort the list.
    List is assumed to be sorted already.
****************************************************************/
    void insert_sorted(const E& value);

/****************************************************************
    insert_at
         This method takes one argument for the data to be inserted
    and adds the value sorted into the list. Does not sort the list.
    List is assumed to be sorted already.
****************************************************************/
    void insert_at(const E& value, const unsigned& index);

/****************************************************************
    remove_duplicates
         This method takes no arguments and removes all duplicate
    values after the original value.
****************************************************************/
    void remove_duplicates( );
};

/******************
 ** CONSTRUCTORS **
 ******************/

/**********************************************************
* LinkedList | LinkedList CLass
* default constructor with head and tail pointing to null
* Preconditions:
*   none
* Postconditions:
*   head and tail are initialized to null
**********************************************************/
template<typename E>
LinkedList<E>::LinkedList()
{
  head = nullptr;
  tail = nullptr;
}

/**********************************************************
* LinkedList | LinkedList CLass
* Copy constructor;
* Preconditions:
*   source - linked list to be copied
* Postconditions:
*   All of source's nodes are copied into a completely new list.
**********************************************************/
template<typename E>
LinkedList<E>::LinkedList(const LinkedList<E>& source)
{
    head = nullptr;
    tail = nullptr;
    if(source.head == nullptr)
        return;
    if (source.head == source.tail)
         push_front(source.front());
    else
    {
        Node<E>* current;
        current = source.head;
        while(current != nullptr)
        {
            push_back(current->data);
            current = current->next;
        }
    }
}

/**********************************************************
* Iterator | Iterator Class
* default constructor with current set to null
* Preconditions:
*   none
* Postconditions:
*   current set to null
**********************************************************/
template<typename E>
LinkedList<E>::Iterator::Iterator():current(nullptr){}

/**********************************************************
* Iterator( Node<E> * ptr) | Iterator Class
* one parameter constructor with current set to a value
* Preconditions:
*   ptr - where to initialize iterator
* Postconditions:
*   current set to ptr
**********************************************************/
template<typename E>
LinkedList<E>::Iterator::Iterator( Node<E> *ptr):current(ptr){}

/***************
** DESTRUCTOR **
***************/
/****************************************************************
*   ~LinkedList( ) | LinkedList Class
*   Destructor; Deallocates memory for whole list
*   Preconditions*
*     The object has dynamic memory allocated
*   Postconditions
*     All memory in the object is deallocated
***************************************************************/
template<typename E>
LinkedList<E>::~LinkedList()
{
  Node<E>* nextNode; //Pointer to track next node
  nextNode = head; //Next set at beginning
  //PROCESSING - freeing memory from each node
  while(head != nullptr)
  {
    nextNode = head->next; //move next up one
    delete head; //deallocate memory
    head = nextNode; //move head to next
  }
  //PROCESSING - reseting member pointers to null
  head = nullptr;
  tail = nullptr;
}

/*****************
** ACCESSORS *****
*****************/

/**********************************************************
* operator = | LinkedList CLass
* Overloaded assignment operator.
* Preconditions:
*   none
* Postconditions:
*   Assignment operator is overlaoded to copy a list into another
*
**********************************************************/
template<typename E>
LinkedList<E>& LinkedList<E>::operator=( const LinkedList<E>& source )
{
    if(this != &source)
    {
        Node<E>* nextNode; //Pointer to track next node
        nextNode = head; //Next set at beginning
        //PROCESSING - freeing memory from each node
        while(head != nullptr)
        {
          nextNode = head->next; //move next up one
          delete head; //deallocate memory
          head = nextNode; //move head to next
        }
        //PROCESSING - reseting member pointers to null
        head = nullptr;
        tail = nullptr;
        if(source.head == nullptr)
            return * this;
        if (source.head == source.tail)
             push_front(source.front());
        else
        {
            Node<E>* current;
            current = source.head;
            while(current != nullptr)
            {
                push_back(current->data);
                current = current->next;
            }
        }
    }
    return *this;
}

/****************************************************************
* void display() const | LinkedList Class
*
*   Accessor; This method takes no arguments and will print every
*             node in the list
* --------------------------------------------------------------
*   Preconditions:
*     list is initialized
* --------------------------------------------------------------
*   Postcondtion
*     The list is printed
***************************************************************/
template<typename E>
void LinkedList<E>::display() const
{
  Node<E>* current; //current node to track list

  current = head; //initialize current to beginning of list

  //OUTPUT - printing each node
  while(current != nullptr)
  {
    cout << current->data;
    if(current->next != nullptr)
      cout << ' ';
    current = current->next; //Move current up
  }
}
/****************************************************************
* bool isEmpty | LinkedList Class
*
*   Accessor; This method takes no arguments returns a boolean for
*   if the list is empty.
* --------------------------------------------------------------
*   Preconditions:
*     none
* --------------------------------------------------------------
*   Postcondtion
*      Returns true if the list has no nodes.
***************************************************************/
template <typename E>
bool LinkedList<E>::isEmpty( )
{
    if(head == nullptr)
        return true;
    return false;
}
/****************************************************************
* Iterator begin | LinkedList Class
*
*   Accessor; This method takes no arguments returns an iterator
*   at the head node.
* --------------------------------------------------------------
*   Preconditions:
*     none
* --------------------------------------------------------------
*   Postcondtion
*      Returns an iterator at the beginning of the list.
***************************************************************/
template <typename E>
typename LinkedList<E>::Iterator LinkedList<E>::begin()
{
    return Iterator(head);
}
/****************************************************************
* Iterator end | LinkedList Class
*
*   Accessor; This method takes no arguments returns an iterator
*   at null.
* --------------------------------------------------------------
*   Preconditions:
*     none
* --------------------------------------------------------------
*   Postcondtion
*      Returns an iterator at the end of the list.
***************************************************************/
template <typename E>
typename LinkedList<E>::Iterator LinkedList<E>::end()
{
    return Iterator(nullptr);
}

/****************************************************************
* E front | LinkedList Class
*
*   Accessor; This method takes no arguments and returns the first
*   data
* --------------------------------------------------------------
*   Preconditions:
*     none
* --------------------------------------------------------------
*   Postcondtion
*      Returns a value E from the front.
***************************************************************/
template <typename E>
const E& LinkedList<E>::front() const throw()
{
    if(head == nullptr)
        listEmpty();
    return head->data;
}

/****************************************************************
* E back | LinkedList Class
*
*   Accessor; This method takes no arguments and returns the last
*   data
* --------------------------------------------------------------
*   Preconditions:
*     none
* --------------------------------------------------------------
*   Postcondtion
*      Returns a value E from the back.
***************************************************************/
template <typename E>
const E& LinkedList<E>::back() const throw()
{
    if(head == nullptr)
        listEmpty();
    return tail->data;
}

/****************************************************************
* int length | LinkedList Class
*
*   Accessor; This method takes no arguments and returns the number
*   of nodes
* --------------------------------------------------------------
*   Preconditions:
*     none
* --------------------------------------------------------------
*   Postcondtion
*      Returns an int for the length
***************************************************************/
template <typename E>
int LinkedList<E>::length() const
{
    return countNodes(head);
}

/****************************************************************
* E sum | LinkedList Class
*
*   Accessor; This method takes no arguments and returns the sum
*   of all the data
* --------------------------------------------------------------
*   Preconditions:
*     none
* --------------------------------------------------------------
*   Postcondtion
*      Returns a value E for the sum of all nodes.
***************************************************************/
template <typename E>
E LinkedList<E>::sum() const
{
    return findSum(head);
}

/**********************************************************
* E operator* | Iterator Class
* Overloaded Operator; Overloading dereference operator.
* Preconditions:
*   none
* Postconditions:
*   Returns current->data
**********************************************************/
template<typename E>
E LinkedList<E>::Iterator::operator*()
{
    return current->data;
}

/**********************************************************
* bool operator== | Iterator Class
* Overloaded Operator; Overloading Equals operator.
* Preconditions:
*   none
* Postconditions:
*   Returns bool
**********************************************************/
template<typename E>
bool LinkedList<E>::Iterator::operator==(const Iterator& right) const
{
    if(current == right.current)
        return true;
    return false;
}

/**********************************************************
* bool operator!= | Iterator Class
* Overloaded Operator; Overloading notEquals operator.
* Preconditions:
*   none
* Postconditions:
*   Returns bool
**********************************************************/
template<typename E>
bool LinkedList<E>::Iterator::operator!=(const Iterator& right) const
{
    if(current != right.current)
        return true;
    return false;
}

/*****************
*** MUTATORS *****
*****************/

/****************************************************************
* void clear( ) const | LinkedList Class
*
*   Mutator; This method takes no arguments and delets every node.
* --------------------------------------------------------------
*   Preconditions:
* --------------------------------------------------------------
*   Postcondtion
*      The list has no nodes anymore, head and tail set to null
***************************************************************/
template <typename E>
void LinkedList<E>::clear()
{
    if(head == nullptr) return; //Returning if no nodes
    Node<E>* nextNode; //Pointer to track next node
    nextNode = head; //Next set at beginning
    //PROCESSING - freeing memory from each node
    while(head != nullptr)
    {
      nextNode = head->next; //move next up one
      delete head; //deallocate memory
      head = nextNode; //move head to next
    }
    //PROCESSING - reseting member pointers to null
    head = nullptr;
    tail = nullptr;
}

/****************************************************************
* void push_front(int value) const | LinkedList Class
*
*   Mutator; This method takes one argument for the value to be
*            pushed and inserts it in the begining of the list.
* --------------------------------------------------------------
*   Preconditions:
*     list is initialized
*     value - data to be added to list
* --------------------------------------------------------------
*   Postcondtion
*      The list has a new first node, head and tail are properly
*      updated.
***************************************************************/
template<typename E>
void LinkedList<E>::push_front(const E& value) //IN - Data to be added to list
{
  Node<E>* newNode;
  newNode = new Node<E>(value);
  newNode->next = head;
  head = newNode;

  if(tail == nullptr)
    tail = head;

}

/****************************************************************
* void pop_front() | LinkedList Class
*
*   Mutator; This method takes one argument for the value to be
*            pushed and inserts it in the begining of the list.
* --------------------------------------------------------------
*   Preconditions:
*     list is initialized
* --------------------------------------------------------------
*   Postcondtion
*      The list has the first node removed, head and tail are properly
*      updated.
***************************************************************/
template<typename E>
void LinkedList<E>::pop_front()
{
    Node<E>* nextNode;      // CALC - node 'current' points to
    if(head == nullptr)
        throw listEmpty();
    if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        // Current is set to first node in list
        nextNode = head->next;

        // Current is removed
        delete head;

        // Head points to next node after current
        head = nextNode;
    }
}

/****************************************************************
* void push_back() | LinkedList Class
*
*   Mutator; This method takes one argument for the value to be
*            pushed and inserts it in the end of the list.
* --------------------------------------------------------------
*   Preconditions:
*     list is initialized
* --------------------------------------------------------------
*   Postcondtion
*      The list has a new last node. Tail now points to the new
*      node.
***************************************************************/
template<typename E>
void LinkedList<E>::push_back(const E& value) //IN - data to be added to list
{
    Node<E>* newNode;
    newNode = new Node<E>(value);

    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

/****************************************************************
* void select_sort() | LinkedList Class
*
*   Mutator; This method takes no arguments and sorts the list
*            usign the selection sort algorithm
* --------------------------------------------------------------
*   Preconditions:
*     list must be initialized
* --------------------------------------------------------------
*   Postcondtion
*      The list is fully sorted.
***************************************************************/
template<typename E>
void LinkedList<E>::select_sort()
{
    Node<E>* current; //CALC - current node being compared
    Node<E>* min; //CALC - most recent minimum node
    E temp; //CALC - temp variable for swap

    min = head; //Beginning with minimum at begining of list

    //PROCESSING - selection sort
    while(min->next != nullptr)
    {
        current = min; //Beginning with current at most recent min
        while(current != nullptr)
        {
            if (min->data > current->data)
            {
                //PROCESSING - swapping if min is greater than current
                temp = min->data;
                min->data = current->data;
                current->data = temp;
            }
            current = current->next; //Incrementing current counter
        }
        min = min->next; //Incrementing min counter
    }
}

/****************************************************************
* void insert_sorted() | LinkedList Class
*
*   Mutator; This method takes one argument for the value of data
*           to be added and inserts it into the list in a sorted
*           position
* --------------------------------------------------------------
*   Preconditions:
*     list must be sorted
* --------------------------------------------------------------
*   Postcondtion
*      The new value is added to the list in a sorted place.
***************************************************************/
template<typename E>
void LinkedList<E>::insert_sorted(const E& value) //IN - data to be added to list
{
    //PROCESSING - no element case
    if(isEmpty())
        push_front(value);
    //PROCESSING - one element case
    else if(head == tail)
    {
        if(head->data > value)
            push_front(value);
        else
            push_back(value);
    }
    else
    {
        Node<E>* prev; //CALC - current node being compared

        prev = head; //current set to beginning of list

        //PROCESSING - value is smallest
        if(prev->data > value)
        {
            push_front(value);
            return;
        }
        //PROCESSING - finding appropriate spot in list for new value
        while(prev!=tail && prev->next->data < value)
            prev = prev->next;

        //PROCESSING - pushing value back if it is greatest value in list
        if(prev == tail)
            push_back(value);
        else
        {
            Node<E>*post; //CALC - node after node to be inserted
            Node<E>* newNode; //CLAC - new node to be inserted
            newNode = new Node(value);
            post = prev->next;
            prev->next = newNode;
            newNode->next = post;
        }
    }
}

/****************************************************************
* void insert_at() | LinkedList Class
*
*   Mutator; This method takes one argument for the value of data
*           to be added and inserts it into the list at the index
*           provided
* --------------------------------------------------------------
*   Preconditions:
*     index - unsigned int must be between 0 and size - 1;
* --------------------------------------------------------------
*   Postcondtion
*      The new value is added to the list at index, if index is out
*      of bounds, the value will be pushed to back
***************************************************************/
template<typename E>
void LinkedList<E>::insert_at(const E& value, const unsigned& index) //IN - data to be added to list
{
    //PROCESSING - no element case
    if(isEmpty())
        push_front(value);


    Node<E>* prev; //CALC - current node being compared
    prev = head; //current set to beginning of list

    //PROCESSING - index at 0
    if(index == 0)
    {
        push_front(value);
        return;
    }
    //PROCESSING - finding appropriate spot in list for new value
    for(unsigned i = 1; i <index; i++)
    {
        if(prev!=tail)
            prev=prev->next;
    }

    //PROCESSING - pushing value back if necessary
    if(prev == tail)
        push_back(value);
    else
    {
        Node<E>*post; //CALC - node after node to be inserted
        Node<E>* newNode; //CLAC - new node to be inserted
        newNode = new Node(value);
        post = prev->next;
        prev->next = newNode;
        newNode->next = post;
    }

}

/****************************************************************
* void remove_duplicates() | LinkedList Class
*
*   Mutator; This method takes no arguments and removes all dupl-
*            icates that are found in the list.
* --------------------------------------------------------------
*   Preconditions:
*     list must be initialized
* --------------------------------------------------------------
*   Postcondtion
*      All duplicate values occuring after orignial value are
*      deleted. List may reduce in size.
***************************************************************/
template<typename E>
void LinkedList<E>::remove_duplicates()
{
    Node<E>* current; //CALC - current node
    Node<E>* start; //CALC - node being compared
    Node<E>* duplicate; //CALC - duplicate node to be deleted

    start = head; //Beginning with comparing the node at begining of list

    while(start != nullptr && start->next != nullptr)
    {
        current = start; //Beginning with current at start
        while(current->next != nullptr)
        {
            if (start->data == current->next->data)
            {
                //PROCESSING - if duplicate, then delete
                duplicate = current->next;
                current->next = current->next->next;
                delete duplicate;
            }
            else
                current = current->next; //Incrementing current counter
        }
        start = start->next; //Incrementing start counter
    }
}

/**********************************************************
* Iterator operator++ | Iterator Class
* Overloaded Operator; Overloading preincrement operator.
* Preconditions:
*   none
* Postconditions:
*   Returns current->next
**********************************************************/
template<typename E>
typename LinkedList<E>::Iterator LinkedList<E>::Iterator::operator++()
{
    current = current->next;
    return *this;
}

/*****************************
** PRIVATE MEMBER FUNCTIONS **
*****************************/

/****************************************************************
* int countNodes(Node<E> *ptr) const | IntList Class
*
*   Private member funciton; This method returns the total number
*                            of nodes in the list.
* --------------------------------------------------------------
*   Preconditions:
*     Node<E>* ptr - head;
* --------------------------------------------------------------
*   Postcondtion:
*     Returns an int for the number of nodes int he list
***************************************************************/
template <typename E>
int LinkedList<E>::countNodes(Node<E> *ptr) const
{
    if(ptr != NULL)
        return 1 + countNodes(ptr->next);
    else
        return 0;
}

/****************************************************************
* E findSum(IntNode *ptr) const | IntList Class
*
*   Private member funciton; This method returns the sum of all
*                            the nodes
* --------------------------------------------------------------
*   Preconditions:
*     Node<E>* ptr - head;
* --------------------------------------------------------------
*   Postcondtion:
*     Returns an int for the sum of all nodes values
***************************************************************/
template <typename E>
E LinkedList<E>::findSum(Node<E> *ptr) const
{
    if(ptr != NULL)
        return ptr->data + findSum(ptr->next);
    else
        return 0;
}


#endif //LINKEDLIST_H
