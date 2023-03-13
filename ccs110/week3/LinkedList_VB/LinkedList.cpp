//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.h"  // Header file
#include <cassert>
#include <string>
#include <cstdlib>
#include <iostream>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0), tailPtr(nullptr)
{
   headPtr = nullptr;
   itemCount = 0;
   tailPtr = nullptr;
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
   Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain

   if (origChainPtr == nullptr) {
      headPtr = nullptr;  // Original list is empty
      tailPtr = nullptr;
   }
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item 
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);  
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr); 
         
         // Advance pointer to new last node      
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert){
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
      if (newPosition == 1 ){
         // Insert new node at beginning of chain
         newNodePtr->setNext(headPtr);
         headPtr = newNodePtr;
         newNodePtr->setPrev(nullptr);
      }
      else if (newPosition == itemCount + 1){
         // Insert new node at end of chain
         Node<ItemType>* lastPtr = getNodeAt(itemCount);
         lastPtr->setNext(newNodePtr);
         newNodePtr->setPrev(lastPtr);
         tailPtr = newNodePtr;
      }
      else {
         // If not first or last, insert new node
         //Find node that will be before new node
         Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

         //Find node that will be after new node
         Node<ItemType>* aftPtr = prevPtr->getNext();
         
         //Insert new node between prevPtr and aftPtr
         newNodePtr->setNext(prevPtr->getNext());
         newNodePtr->setPrev(prevPtr);
         
         //Update pointers
         prevPtr->setNext(newNodePtr);
         aftPtr->setPrev(newNodePtr);
      }  // end if
      itemCount++;  // Increase count of entries
   }  // end if
   return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
         tailPtr = nullptr;
      }
      else
      {
         // Find node that is before the one to delete
         Node<ItemType>* prevPtr = getNodeAt(position - 1);
         
         // Point to node to delete
         curPtr = prevPtr->getNext();
         
         // Update prev ptr for node after curPtr
         curPtr->getNext()->setPrev(prevPtr);

         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
         
      }  // end if
      
      // Return node to system
      curPtr->setNext(nullptr);
      delete curPtr;
      curPtr = nullptr;
      
      itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "getEntry() called with an empty list or "; 
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end getEntry

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      nodePtr->setItem(newEntry);
   }
   else
   {
      string message = "setEntry() called with an invalid position."; 
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end setEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();
      
   return curPtr;
}  // end getNodeAt

template <class ItemType>
void LinkedList<ItemType>::reverse(){
   Node<ItemType>* curPtr = headPtr;
   Node<ItemType>* prevPtr = nullptr;
   Node<ItemType>* nextPtr = nullptr;
   while (curPtr != nullptr){
      nextPtr = curPtr->getNext();
      curPtr->setNext(prevPtr);
      curPtr->setPrev(nextPtr);
      prevPtr = curPtr;
      curPtr = nextPtr;
   }
   headPtr = prevPtr;
}  // end reverse

template <class ItemType>
void LinkedList<ItemType>::checkPtrs(){
   // This function prints out the pointers of each node in the list to ensure prev and next Ptrs are correct for each node
   Node<ItemType>* curPtr = headPtr;
   while (curPtr != nullptr){
      cout << "Node: " << curPtr->getItem() << " Address: " << curPtr->getCurrent() << " | "<< " Prev: " << curPtr->getPrev() << " Next: " << curPtr->getNext() << endl;
      curPtr = curPtr->getNext();
   }
}

// End of implementation file.  To get this to compile on hills,
// add definitions of template types we will use (int or string now,
// add more types if necessary)
template class LinkedList<int>;
template class LinkedList<string>;