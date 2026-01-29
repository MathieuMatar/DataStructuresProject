/*-- NodePool.h ---------------------------------------------------------------
 
  This header file defines the data type NodePool for managing memory allocation
  in linked in an array data structures . The NodePool acts as a resource manager, providing 
  nodes when needed and reclaiming them when no longer in use.
  
  Basic operations are:
     Constructor
     newNode:     Allocate a new node from the pool
     deleteNode:  Return a node to the pool
     getData:     Access data in a node
     setData:     Modify data in a node
     getNext:     Access the next pointer in a node
     setNext:     Modify the next pointer in a node

    !!-- Destructor and copy constructor are not needed as no dinamic memory is beiing used
-------------------------------------------------------------------------*/

#include <iostream>
#include <cassert>
#include <stdexcept>
using namespace std;

#ifndef NODEPOOL_H
#define NODEPOOL_H

template <typename ElementType>
class NodePool
{
 public:
   /******** Public Constants ********/
   static const int NULL_VALUE = -1; // Represents a nonexistent location
   
   /******** Function Members ********/
   /***** Class constructor *****/
   NodePool();
   /*----------------------------------------------------------------------
     Construct a NodePool object.

     Precondition:  None
     Postcondition: An empty NodePool of size NUM_NODES has been constructed;
                    all nodes are initialized and available in the free list.
   -----------------------------------------------------------------------*/

   /***** newNode operation *****/
   int newNode();
   /*----------------------------------------------------------------------
     Allocate a node from the pool.

     Precondition:  The free list is not empty.
     Postcondition: If a free node is available, its index is returned and
                    it is removed from the free list. If no nodes are available,
                    NULL_VALUE is returned.
   -----------------------------------------------------------------------*/

   /***** deleteNode operation *****/
   void deleteNode(int position);
   /*----------------------------------------------------------------------
     Return a node to the free list.

     Precondition:  'position' is a valid node index previously returned by newNode().
     Postcondition: The node at 'position' has been returned to the free list
                    and can be reused.
     Throws:        std::out_of_range if position is invalid (< 0 or >= NUM_NODES).
   -----------------------------------------------------------------------*/

   /***** Data access and modification *****/
   const ElementType& getData(int position) const;
   /*----------------------------------------------------------------------
     Retrieve the data stored in a node.

     Precondition:  'position' is a valid node index.
     Postcondition: The data stored in the node at 'position' is returned.
     Throws:        std::out_of_range if position is invalid (< 0 or >= NUM_NODES).
   -----------------------------------------------------------------------*/

   void setData(int position, const ElementType &data);
   /*----------------------------------------------------------------------
     Modify the data stored in a node.

     Precondition:  'position' is a valid node index.
     Postcondition: The data in the node at 'position' has been set to 'data'.
     Throws:        std::out_of_range if position is invalid (< 0 or >= NUM_NODES).
   -----------------------------------------------------------------------*/

   int getNext(int position) const;
   /*----------------------------------------------------------------------
     Retrieve the next pointer from a node.

     Precondition:  'position' is a valid node index.
     Postcondition: The next wich is the position of the next node (an index) stored in the node at 'position' is returned.
     Throws:        std::out_of_range if position is invalid (< 0 or >= NUM_NODES).
   -----------------------------------------------------------------------*/

   void setNext(int position, int nextPosition);
   /*----------------------------------------------------------------------
     Modify the next pointer in a node.

     Precondition:  'position' is a valid node index.
     Postcondition: The next in the node at 'position' has been set to 'nextPosition' the index of the next node.
     Throws:        std::out_of_range if position is invalid (< 0 or >= NUM_NODES).
   -----------------------------------------------------------------------*/

 private:
   /******** Node Structure ********/
   struct NodeType
   {
       ElementType data;  // The data stored in this node
       int next;          // The index of the next node, or NULL_VALUE if none
   };

   /******** Private Constants ********/
   static const int NUM_NODES = 2048;  // Size of the node pool

   /******** Data Members ********/
   NodeType nodes[NUM_NODES];  // Array of nodes
   int free;                   // Index of the first free node

}; //--- end of NodePool class

/*-- NodePool.cpp------------------------------------------------------------
 
   This file implements NodePool member functions.

-------------------------------------------------------------------------*/

//--- Definition of the constructor
template <typename ElementType>
NodePool<ElementType>::NodePool()
{
    // Initialize the free list
    for (int i = 0; i < NUM_NODES - 1; i++)
    {
        nodes[i].next = i + 1;
    }
    nodes[NUM_NODES - 1].next = NULL_VALUE; // Last node points to NULL_VALUE
    free = 0; // The first free node is at index 0
}

//--- Definition of newNode()
template <typename ElementType>
int NodePool<ElementType>::newNode()
{
    if (free == NULL_VALUE)    
    {
        cout << "No free nodes available." << endl;
        return NULL_VALUE; // No free nodes available
    }
    else
    {
        int newNodeIndex = free; // Get the index of the new node
        free = nodes[free].next; // Update the free list
        return newNodeIndex; // Return the index of the new node
    }
}

//--- Definition of deleteNode()
template <typename ElementType>
void NodePool<ElementType>::deleteNode(int position)
{
    // Check if position is valid
    if (position < 0 || position >= NUM_NODES) {
        throw out_of_range("position out of range");
    }
    nodes[position].next = free; // Add the node back to the free list
    free = position; // Update the free list
}

//--- Definition of getData()
template <typename ElementType>
const ElementType& NodePool<ElementType>::getData(int position) const
{
    // Check if position is valid
    if (position < 0 || position >= NUM_NODES) {
        //throw out_of_range("position out of range");
    }
    return nodes[position].data; // Return the data at the specified index
}

//--- Definition of setData()
template <typename ElementType>
void NodePool<ElementType>::setData(int position, const ElementType &data)
{
    // Check if position is valid
    if (position < 0 || position >= NUM_NODES) {
        throw out_of_range("position out of range");
    }
    nodes[position].data = data; // Set the data at the specified index
}

//--- Definition of getNext()
template <typename ElementType>
int NodePool<ElementType>::getNext(int position) const
{
    // Check if position is valid
    if (position < 0 || position >= NUM_NODES) {
        throw out_of_range("position out of range");
    }
    return nodes[position].next; // Return the next index
}

//--- Definition of setNext()
template <typename ElementType>
void NodePool<ElementType>::setNext(int position, int nextPosition)
{
    // Check if position is valid
    if (position < 0 || position >= NUM_NODES) {
        throw out_of_range("position out of range");
    }
    nodes[position].next = nextPosition; // Set the next index
}

#endif /* END OF NODEPOOL_H */