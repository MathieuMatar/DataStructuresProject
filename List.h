/* List.h contains the declarations of class template List

  This header file defines the data type List for implementing a linked list 
  data structure using a NodePool for memory management. The List class provides
  basic operations for managing a linked list with efficient memory usage.

    Basic Operations:
      Constructor: Constructs a List object
      Copy Constructor: Constructs a List object from an existing object and its value
      Destructor: Deletes the List object
      isEmpty: Checks if List is empty
      getSize: Gets size of all used nodes in a list
      insertAtFirst: Inserts data at the beginning of list
      insertAtPosition: Inserts data at a given position
      insertAtEnd: Inserts data at the end of list
      deleteFirst: deletes node from the beginning of list
      deleteAt: deletes node from a given position
      deleteEnd: deletes node from the end of list
      deleteValue: Removes nodes containing a given data
      search: Searches and gets the position of the first node containing the given data
      getDataAtPos: Gets the data at a given node position
      arrange: Arranges node's data by defragmenting them and putting them in order in the memory
      clear: Deletes all nodes in a List without deleting the list
      reverse: Reverses all nodes of a List
      displayList: Displays the List each item on a new line
      Assignment Operator: Assigns values of an existing List object from another List object
      Addition Operator: Adds an Element to the list with insert at end
      Subtraction Operator: Deletes an Element from the list with deleteValue
      Multiplication Operator: Add 2 lists together with insert at end
      Modulos Operator: Deletes all nodes in the current list that exist in another list
      Division Operator: Divides the current into many other and return an array of lists
      Comparison operators < and >: compare the size of two lists and return true or false

      Additional Functions:
        Overloaded cout operator "<<": Outputs List objects

------------------------------------------------------------------------------------------------*/

#ifndef LIST_H
#define LIST_H

#include "NodePool.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename ElementType>
class List {

public:
    /******** Function Members ********/
    /***** Class constructor *****/
    List();
    /*----------------------------------------------------------------------
      Construct a List object.

      Precondition:  None.
      Postcondition: An empty List object has been constructed with
                     size initialized to 0 and first set to NULL_VALUE.
    -----------------------------------------------------------------------*/
   
    /***** Copy constructor *****/
    List(const List<ElementType>& other);
    /*----------------------------------------------------------------------
      Construct a List object with the values of an existing List object.

      Precondition:  None.
      Postcondition: A new List object has been constructed as an exact copy
                     of the 'other' List object.
    -----------------------------------------------------------------------*/

    /*~List();
    ------------------------------------------------------------------------
    Destructs a List object.

    Precondition: None.
    Postcondition: List has been destructed.
   ---------------------------------------------------------------------------*/


    /***** isEmpty operation *****/
    bool isEmpty() const;
    /*----------------------------------------------------------------------
      Check if List is empty.

      Precondition:  None.
      Postcondition: Returns true if the List contains no elements, and
                     false otherwise.
    -----------------------------------------------------------------------*/

    /***** getSize operation *****/
    int getSize() const;
    /*----------------------------------------------------------------------
      Get the number of elements in the List.

      Precondition:  None.
      Postcondition: The number of elements in the List is returned.
    -----------------------------------------------------------------------*/

    /***** insertFirst operation *****/
    void insertFirst(const ElementType& item);
    /*----------------------------------------------------------------------
      Insert an element at the beginning of the List.

      Precondition:  None.
      Postcondition: 'item' is inserted at the beginning of the List and size
                     is incremented by 1.
      Throws:        runtime_error if no free nodes are available in NodePool.
    -----------------------------------------------------------------------*/

    /***** insertAtPosition operation *****/
    void insertAtPosition(int position, const ElementType& item);
    /*----------------------------------------------------------------------
      Insert an element at a specified position in the List.

      Precondition:  A valid position (1 <= position <= size).
      Postcondition: 'item' is inserted at the specified position in the List
                     and size is incremented by 1.
      Throws:        out_of_range if position is invalid.
                     runtime_error if no free nodes are available in NodePool.
    -----------------------------------------------------------------------*/

    /***** insertAtEnd operation *****/
    void insertAtEnd(const ElementType& item);
    /*----------------------------------------------------------------------
      Insert an element at the end of the List.

      Precondition:  None.
      Postcondition: 'item' is inserted at the end of the List and size
                     is incremented by 1.
      Throws:        runtime_error if no free nodes are available in NodePool.
    -----------------------------------------------------------------------*/

    /***** deleteFirst operation *****/
    void deleteFirst();
    /*----------------------------------------------------------------------
      Delete the first element of the List.

      Precondition:  List is not empty.
      Postcondition: The first element is removed from the List and returned
                     to the NodePool. Size is decremented by 1.
      Throws:        runtime_error if the List is empty.
    -----------------------------------------------------------------------*/

    /***** deleteAt operation *****/
    void deleteAt(int position);
    /*----------------------------------------------------------------------
      Delete an element at a specified position in the List.

      Precondition:  A valid position (1 <= position <= size).
      Postcondition: The element at the specified position is removed
                     from the List and returned to the NodePool.
                     Size is decremented by 1.
      Throws:        out_of_range if position is invalid.
                     runtime_error if the List is empty.
    -----------------------------------------------------------------------*/

    /***** deleteLast operation *****/
    void deleteLast();
    /*----------------------------------------------------------------------
      Delete the last element of the List.

      Precondition:  List is not empty.
      Postcondition: The last element is removed from the List and returned
                     to the NodePool. Size is decremented by 1.
      Throws:        runtime_error if the List is empty.
    -----------------------------------------------------------------------*/

    /***** deleteValue operation *****/
    int deleteValue(const ElementType& value);
    /*----------------------------------------------------------------------
      Delete all occurrences of a specified value in the List.

      Precondition:  None.
      Postcondition: All elements with data equal to 'value' are removed
                     from the List and returned to the NodePool.
                     Returns the number of elements deleted.
    -----------------------------------------------------------------------*/

    /***** search operation *****/
    int search(const ElementType& item) const;
    /*----------------------------------------------------------------------
      Search for an element in the List.

      Precondition:  None.
      Postcondition: Returns the position of the first occurrence of
                     'item' in the List, or -1 if 'item' is not found.
    -----------------------------------------------------------------------*/

    /***** getDataAtPos operation *****/
    const ElementType& getDataAtPos(int position) const;
    /*----------------------------------------------------------------------
      Get the data at a specified position in the List.

      Precondition:  A valid position (1 <= position <= size).
      Postcondition: The data at the specified position is returned.
      Throws:        out_of_range if position is invalid.
    -----------------------------------------------------------------------*/

    /***** arrange operation *****/
    void arrange();
    /*----------------------------------------------------------------------
      Arrange nodes by defragmenting them and putting them in order in memory.

      Precondition:  None.
      Postcondition: The nodes are now ordered in memory with position matching
                     index+1 (position starts at 1, index at 0) this is to defragment the list.
    -----------------------------------------------------------------------*/

    /***** clear operation *****/
    void clear();
    /*----------------------------------------------------------------------
      Delete all elements in the List.

      Precondition:  None.
      Postcondition: All nodes are returned to the NodePool. The List is empty
                     with size set to 0.
    -----------------------------------------------------------------------*/

    /***** reverse operation *****/
    void reverse();
    /*----------------------------------------------------------------------
      Reverse the order of elements in the List.

      Precondition:  None.
      Postcondition: The order of elements in the List is reversed, with the
                     first element becoming the last and vice versa.
    -----------------------------------------------------------------------*/

    /***** Assignment operator *****/
    List<ElementType>& operator=(const List<ElementType>& other);
    /*----------------------------------------------------------------------
      Assign the values of another List to this List.

      Precondition:  None.
      Postcondition: This List contains a copy of the elements in 'other'.
                     Returns a reference to this List.
    -----------------------------------------------------------------------*/

    /***** Addition operator *****/
    List<ElementType>& operator+(const ElementType& item);
    /*----------------------------------------------------------------------
      Add an element to the end of the List.

      Precondition:  None.
      Postcondition: 'item' is added to the end of the List.
                     Returns a reference to this List.
      Throws:        runtime_error if no free nodes are available in NodePool.
    -----------------------------------------------------------------------*/

    /***** Subtraction operator *****/
    List<ElementType>& operator-(const ElementType& item);
    /*----------------------------------------------------------------------
      Remove all occurrences of an element from the List.

      Precondition:  None.
      Postcondition: All occurrences of 'item' are removed from the List.
                     Returns a reference to this List.
    -----------------------------------------------------------------------*/

    /***** Multiplication operator *****/
    List<ElementType> operator*(const List<ElementType>& other);
    /*----------------------------------------------------------------------
      Concatenate two Lists.

      Precondition:  None.
      Postcondition: Returns a new List containing all elements from this List
                     followed by all elements from 'other'.
      Throws:        runtime_error if no free nodes are available in NodePool.
    -----------------------------------------------------------------------*/

    /***** Modulus operator *****/
    List<ElementType>& operator%(const List<ElementType>& other);
    /*----------------------------------------------------------------------
      Remove elements that exist in another List.

      Precondition:  None.
      Postcondition: All elements that appear in 'other' are removed from this List.
                     Returns a reference to this List.
    -----------------------------------------------------------------------*/

    /***** Division operator *****/
    List<ElementType>* operator/(unsigned divisor);
    /*----------------------------------------------------------------------
      Divide the List into multiple Lists.

      Precondition:  divisor > 0
      Postcondition: Returns an array of 'divisor' Lists, where this List
                     is divided into approximately equal parts.
      Throws:        runtime_error if no free nodes are available in NodePool.
    -----------------------------------------------------------------------*/

    /***** Less than operator *****/
    bool operator<(const List<ElementType>& other) const;
    /*----------------------------------------------------------------------
      Compare if this List has fewer elements than another List.

      Precondition:  None.
      Postcondition: Returns true if this List has fewer elements than 'other',
                     false otherwise.
    -----------------------------------------------------------------------*/

    /***** Greater than operator *****/
    bool operator>(const List<ElementType>& other) const;
    /*----------------------------------------------------------------------
      Compare if this List has more elements than another List.

      Precondition:  None.
      Postcondition: Returns true if this List has more elements than 'other',
                     false otherwise.
    -----------------------------------------------------------------------*/

    /***** displayList operation *****/
    ostream &displayList(ostream &out) const;
    /*----------------------------------------------------------------------
      Display the contents of the List to an output stream.

      Precondition:  'out' is an open output stream.
      Postcondition: The contents of the List are written to 'out'.
                     Returns a reference to 'out'.
    -----------------------------------------------------------------------*/

   private:
    /******** Data Members ********/
    NodePool<ElementType> nodePool;  // Node pool to manage storage
    int first;                       // Index of the first node in the list           
    int size;                        // Number of elements in the list
};

/***** Output operator *****/
template <typename ElementType>
ostream &operator<<(ostream &out, const List<ElementType> &list);
/*----------------------------------------------------------------------
  Output the contents of a List to an output stream.

  Precondition:  'out' is an open output stream.
  Postcondition: The contents of 'list' are written to 'out'.
                 Returns a reference to 'out'.
-----------------------------------------------------------------------*/

#endif // END OF LIST_H DECLARATION

/*-- List.cpp ------------------------------------------------------------
 
   This file implements List member functions.

-------------------------------------------------------------------------*/

//--- Definition of the constructor
template <typename ElementType>
List<ElementType>::List() {
    first = NodePool<ElementType>::NULL_VALUE;
    size = 0;
}

//--- Definition of the copy constructor
template <typename ElementType>
List<ElementType>::List(const List<ElementType>& other) {
    first = NodePool<ElementType>::NULL_VALUE;
    size = 0;
    for (int i = 0; i < other.getSize(); i++) {
        //data is inserted in a defragmented ordered way.
        insertAtEnd(other.getDataAtPos(i));
    }
}

// DESTRUCTOR
/*template <typename ElementType>
List<ElementType>::~List() {
    while (!isEmpty()) {
        deleteFirst();
    }
}*/

//--- Definition of isEmpty()
template <typename ElementType>
bool List<ElementType>::isEmpty() const {
    return first == NodePool<ElementType>::NULL_VALUE;
}

//--- Definition of getSize()
template <typename ElementType>
int List<ElementType>::getSize() const {
    return size;
}

//--- Definition of insertFirst()
template <typename ElementType>
void List<ElementType>::insertFirst(const ElementType& item) {
    int newNode = nodePool.newNode();

    if (newNode == NodePool<ElementType>::NULL_VALUE) {
        throw runtime_error("Error: No free nodes available");
    }
    
    nodePool.setData(newNode, item);
    nodePool.setNext(newNode, first);
    first = newNode;
    ++size;
}

//--- Definition of insertAtPosition()
template <typename ElementType>
void List<ElementType>::insertAtPosition(int position, const ElementType& item) {
    if (position <= 0 || position > size) {
        throw out_of_range("Error: Position out of range");
    }
    
    if (position == 1) {
        insertFirst(item);
        return;
    }
    
    int newNode = nodePool.newNode();

    if (newNode == NodePool<ElementType>::NULL_VALUE) {
        throw runtime_error("Error: No free nodes available");
    }

    nodePool.setData(newNode, item);
    
    int current = first;
    for (int i = 1; i <= position; i++) {
        current = nodePool.getNext(current);
    }
    
    nodePool.setNext(newNode, nodePool.getNext(current));
    nodePool.setNext(current, newNode);
    ++size;
}

//--- Definition of insertAtEnd()
template <typename ElementType>
void List<ElementType>::insertAtEnd(const ElementType& item) {
    if (isEmpty()) {
        insertFirst(item);
        return;
    }
    
    int current = first;
    while (nodePool.getNext(current) != NodePool<ElementType>::NULL_VALUE) {
        current = nodePool.getNext(current);
    }
    
    int newNode = nodePool.newNode();

    if (newNode == NodePool<ElementType>::NULL_VALUE) {
        throw runtime_error("Error: No free nodes available");
    }

    nodePool.setData(newNode, item);
    nodePool.setNext(newNode, NodePool<ElementType>::NULL_VALUE);
    nodePool.setNext(current, newNode);
    ++size;
}

//--- Definition of deleteFirst()
template <typename ElementType>
void List<ElementType>::deleteFirst() {
    if (isEmpty()) {
        throw runtime_error("Error: Cannot delete from an empty list");
    }
    
    int temp = first;
    first = nodePool.getNext(first);
    nodePool.deleteNode(temp);
    --size;
}

//--- Definition of deleteLast()
template <typename ElementType>
void List<ElementType>::deleteLast() {
    if (isEmpty()) {
        throw runtime_error("Error: Cannot delete from an empty list");
    }
    
    if (size == 1) {
        deleteFirst();
        return;
    }
    
    int current = first;
    while (nodePool.getNext(nodePool.getNext(current)) != NodePool<ElementType>::NULL_VALUE) {
        current = nodePool.getNext(current);
    }
    
    int temp = nodePool.getNext(current);
    nodePool.setNext(current, NodePool<ElementType>::NULL_VALUE);
    nodePool.deleteNode(temp);
    --size;
}

//--- Definition of deleteAt()
template <typename ElementType>
void List<ElementType>::deleteAt(int position) {
    if (isEmpty()) {
        //throw runtime_error("Error: Cannot delete from an empty list");
    }
    
    if (position <= 0 || position > size) {
        throw out_of_range("Error: Position out of range");
    }
    
    if (position == 1) {
        deleteFirst();
        return;
    }
    
    int current = first;
    for (int i = 0; i < position - 1; i++) {
        current = nodePool.getNext(current);
    }
    
    int temp = nodePool.getNext(current);
    nodePool.setNext(current, nodePool.getNext(temp));
    nodePool.deleteNode(temp);
    --size;
}

//--- Definition of deleteValue()
template <typename ElementType>
int List<ElementType>::deleteValue(const ElementType& value) {
    int removedCount = 0;

    int prev = NodePool<ElementType>::NULL_VALUE;
    int curr = first;

    while (curr != NodePool<ElementType>::NULL_VALUE) {
        if (nodePool.getData(curr) == value) {
            
            int nextNode = nodePool.getNext(curr);
            if (prev == NodePool<ElementType>::NULL_VALUE) {
               
                first = nextNode;
            } else {
                nodePool.setNext(prev, nextNode);
            }
           
            nodePool.deleteNode(curr);
            curr = nextNode;

            ++removedCount;
            --size;
        }
        else {
            
            prev = curr;
            curr = nodePool.getNext(curr);
        }
    }

    return removedCount;
}

//--- Definition of search()
template <typename ElementType>
int List<ElementType>::search(const ElementType& item) const {
    int current = first;
    int position = 0;
    
    while (current != NodePool<ElementType>::NULL_VALUE) {
        if (nodePool.getData(current) == item) {
            return position;
        }
        current = nodePool.getNext(current);
        ++position;
    }
    
    return -1; // Item not found
}

//--- Definition of getDataAtPos()
template <typename ElementType>
const ElementType& List<ElementType>::getDataAtPos(int position) const {
    if (position <= 0 || position > size) {
        //throw std::out_of_range("Error: Position out of range (list level)");
    }
    
    int current = first;
    for (int i = 1; i <= position; i++) {
        current = nodePool.getNext(current);
    }
    
    return nodePool.getData(current);
}

//--- Definition of arrange()
template <typename ElementType>
void List<ElementType>::arrange() {
    if (isEmpty()) {
        return;
    }
    // making a dynamic copy of this with copy constructor
    List<ElementType>* temp = new List<ElementType>(*this);

    // clearing the current list
    clear();
    // rearranging the data in the new list
    for (int i = 0; i < temp->getSize(); i++) {
        // inserting the data in the current list in a defragmented ordered way.
        insertAtEnd(temp->getDataAtPos(i+1));
    }
}

//--- Definition of clear()
template <typename ElementType>
void List<ElementType>::clear() {
    while (!isEmpty())
        deleteFirst();
}

//--- Definition of reverse()
template <typename ElementType>
void List<ElementType>::reverse() {
    int prev = NodePool<ElementType>::NULL_VALUE;
    int curr = first;
    while (curr != NodePool<ElementType>::NULL_VALUE) {
        int nxt = nodePool.getNext(curr);
        nodePool.setNext(curr, prev);
        prev = curr;
        curr = nxt;
    }
    first = prev;
}

//--- Definition of assignment operator
template <typename ElementType>
List<ElementType>& List<ElementType>::operator=(const List<ElementType>& other) {
    if (this != &other) {
        while (!isEmpty()) {
            deleteFirst();
        }
        
        for (int i = 1; i <= other.getSize(); i++) {
            insertAtEnd(other.getDataAtPos(i));
        }
    }
    return *this;
}

//--- Definition of addition operator
//!--this adjust the current list
template <typename ElementType>
List<ElementType>& List<ElementType>::operator+(const ElementType& item) {
    insertAtEnd(item);
    return *this;
}

//--- Definition of subtraction operator
//!--this adjust the current list
template <typename ElementType>
List<ElementType>& List<ElementType>::operator-(const ElementType& item) {
    deleteValue(item);
    return *this;
}

//--- Definition of multiplication operator
//!--this return a new list
template <typename ElementType>
List<ElementType> List<ElementType>::operator*(const List<ElementType>& other) {
    List<ElementType> result;
    for (int i = 1; i <= size; i++) {
        result.insertAtEnd(getDataAtPos(i));
    }
    for (int i = 0; i < other.getSize(); i++) {
        result.insertAtEnd(other.getDataAtPos(i));
    }
    return result;
}

//--- Definition of modulus operator
//!--this adjust the current list
template <typename ElementType>
List<ElementType>& List<ElementType>::operator%(const List<ElementType>& other) {
    int current = first;
    while (current != NodePool<ElementType>::NULL_VALUE) {
        if (other.search(nodePool.getData(current)) != -1) {
            deleteValue(nodePool.getData(current));
        }
        current = nodePool.getNext(current);
    }
    return *this;
}

//--- Definition of division operator
template <typename ElementType>
List<ElementType>* List<ElementType>::operator/(unsigned divisor) {
    int partSize = size / divisor;
    List<ElementType>* lists = new List<ElementType>[divisor];
    
    int current = first;
    for (int i = 0; i < divisor; i++) {
        for (int j = 0; j < partSize && current != NodePool<ElementType>::NULL_VALUE; j++) {
            lists[i].insertAtEnd(nodePool.getData(current));
            current = nodePool.getNext(current);
        }
    }
    return lists;
}

//--- Definition of less than operator
template <typename ElementType>
bool List<ElementType>::operator<(const List<ElementType>& other) const {
    return size < other.size;
}

//--- Definition of greater than operator
template <typename ElementType>
bool List<ElementType>::operator>(const List<ElementType>& other) const {
    return size > other.size;
}

//--- Definition of displayList()
template <typename ElementType>
ostream& List<ElementType>::displayList(ostream &out) const {
    int current = first;
    while (current != NodePool<ElementType>::NULL_VALUE) {
        out << nodePool.getData(current) << endl;
        current = nodePool.getNext(current);
    }
        

    return out;
}

//--- Definition of output operator
template <typename ElementType>
ostream &operator<<(ostream &out, const List<ElementType> &list) {
    return list.displayList(out);
}