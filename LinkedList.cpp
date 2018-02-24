//
//  LinkedList.cpp
//  Lab3
//
//  Created by Rudolf Musika on 2/20/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//
/** @file
 *
 *  @course CS1521
 *  @section 3
 *
 *  Implementation file for the class LinkedList.
 *
 *  Adapted from pages 139-148 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Rudolf Musika
 *
 *  @date 17  2018
 *
 *  @version 7.0 */

#include "Node.hpp"
#include <cstddef>
#include "LinkedList.hpp"
#include <vector>
#include <cassert>

/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Implementation file for a pointer-based implementation of the ADT
 *  list.
 *
 *  Adapted from pages 274-281 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 7 Feb 2018
 *
 *  @version 7.0 */

// #define NDEBUG

#include <string>
#include <new>

#include <cassert>

#include "PrecondViolatedExcept.hpp"

template <typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) {
    
    itemCount = 0; // Empty linked chain
    
    if (!aList.headPtr) {
        headPtr = nullptr;
    }
    else {
        NodePtr aListPtr(aList.headPtr);
        
        try {
            headPtr = new Node<ItemType>(aListPtr->getItem() );
            
            ++itemCount; // Increment after successful call to new
            
            NodePtr thisListPtr(headPtr);
            
            aListPtr = aListPtr->getNext();
            
            while (aListPtr) {
                thisListPtr->setNext(new Node<ItemType>(aListPtr->getItem()) );
                
                ++itemCount; // Increment after each successful call to new
                
                thisListPtr = thisListPtr->getNext();
                aListPtr = aListPtr->getNext();
            }
        }
        catch (const std::bad_alloc&) {
            clear();
            throw;
        }
    }
}

template <typename ItemType>
LinkedList<ItemType>::~LinkedList() {
    
    clear();
}

template <typename ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    
    return !itemCount;
}

template <typename ItemType>
int LinkedList<ItemType>::getLength() const {
    
    return itemCount;
}

template <typename ItemType>
bool LinkedList<ItemType>::insert(int newPosition,
                                  const ItemType& newEntry) {
    
    bool ableToInsert(newPosition >= 1 &&
                      newPosition <= itemCount + 1);
    
    if (ableToInsert) {
        try {
            if (newPosition == 1) {
                headPtr = new Node<ItemType>(newEntry,
                                             headPtr);
            }
            else {
                NodePtr prevPtr(getNodeAt(newPosition - 1) );
                
                prevPtr->setNext(new Node<ItemType>(newEntry,
                                                    prevPtr->getNext()) );
            }
            
            ++itemCount;
        }
        catch (const std::bad_alloc&) {
            ableToInsert = false;
        }
    }
    
    return ableToInsert;
}

template <typename ItemType>
bool LinkedList<ItemType>::remove(int position) {
    
    bool ableToRemove(position >= 1 &&
                      position <= itemCount);
    
    if (ableToRemove) {
        NodePtr nodeToDeletePtr(nullptr);
        
        if (position == 1) {
            nodeToDeletePtr = headPtr;
            headPtr = headPtr->getNext();
        }
        else {
            NodePtr prevPtr(getNodeAt(position - 1) );
            
            nodeToDeletePtr = prevPtr->getNext();
            
            prevPtr->setNext(nodeToDeletePtr->getNext() );
        }
        
        delete nodeToDeletePtr;
        
        --itemCount;
    }
    
    return ableToRemove;
}

template <typename ItemType>
void LinkedList<ItemType>::clear() {
    
    while (!isEmpty() ) {
        remove(1);
    }
}

template <typename ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
    
    bool ableToGet(position >= 1 &&
                   position <= itemCount);
    
    if (!ableToGet) {
        std::string message("LinkedList::getEntry() called with an empty ");
        message += "list or an invalid position.";
        
        throw PrecondViolatedExcept(message);
    }
    
    NodePtr nodePtr(getNodeAt(position) );
    
    return nodePtr->getItem();
}

template <typename ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry) {
    
    bool ableToSet(position >= 1 &&
                   position <= itemCount);
    
    if (!ableToSet) {
        std::string message("LinkedList::setEntry() called with an empty ");
        message += "list or an invalid position.";
        
        throw PrecondViolatedExcept(message);
    }
    
    NodePtr nodePtr(getNodeAt(position) );
    
    ItemType oldEntry(nodePtr->getItem() );
    
    nodePtr->setItem(newEntry);
    
    return oldEntry;
}

template <typename ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const {
    
    assert(position >= 1 && position <= itemCount);
    
    NodePtr curPtr(headPtr);
    
    for (int skip(1); skip < position; ++skip) {
        curPtr = curPtr->getNext();
    }
    
    return curPtr;
}


/*
template <typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) {
    
    itemCount = aList.itemCount;
    
    if (!aList.headPtr) { // if (aBag.headPtr == nullptr) {
        headPtr = nullptr;
    }
    else {
        NodePtr origChainPtr(aList.headPtr);
        
        headPtr = new Node<ItemType>(origChainPtr->getItem() );
        
        NodePtr newChainPtr(headPtr);
        
        origChainPtr = origChainPtr->getNext();
        
        while (origChainPtr) { // while (origChainPtr != nullptr) {
            newChainPtr->setNext(new Node<ItemType>(origChainPtr->getItem()) );
            
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }
    }
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
} // end destructor

template<class ItemType>
int LinkedList<ItemType>::getLength() const{
    return itemCount;
}// end getLength

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
    return itemCount==0;
}// end is Empty

template <class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount+1);
    if(ableToInsert){
        // Create a new node containing the new Entry
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        //Attach new node to chain
        if (newPosition==1){
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else{
            Node<ItemType>* prevPtr = getNodeAt(newPosition-1);
            //insert new node after node to which prevPtr points
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }//end if
        itemCount++; //Increase count of entries
    }//end if
    return ableToInsert;
}//end insert

template <class ItemType>
bool LinkedList<ItemType>::remove(int position){
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove){
        Node<ItemType>* curPtr = nullptr;
        if (position == 1){
            //Remove the first node in the chain
            curPtr = headPtr;// Save pointer to node
            headPtr = headPtr->getNext();
        }
        else{
            //Find node that is before the one to move
            Node<ItemType>* prevPtr = getNodeAt(position -1);
            //Point to node to remove
            curPtr = prevPtr->getNext();
            //Disconnect indicated node from chain by connecting the
            //prior node with the one after
            prevPtr->setNext(curPtr->getNext());
        }// end if
        //return node to system
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
        itemCount--;
    }// end if
    return ableToRemove;
}//end remove

template <class ItemType>
void LinkedList<ItemType>::clear(){
    while (!isEmpty())
        remove(1);
}//end clear

template <typename ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
    
    bool ableToGet(position >= 1 &&
                   position <= itemCount);
    
    if (!ableToGet) {
        std::string message("LinkedList::getEntry() called with an empty ");
        message += "list or an invalid position.";
        
        throw PrecondViolatedExcept(message);
    }
    
    NodePtr nodePtr(getNodeAt(position) );
    
    return nodePtr->getItem();
}// end getEntry

template <class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const{
    //Debugging check of precondition
    assert((position >= 1) && (position <= itemCount));
    //Count from the beginning of the chain
    Node<ItemType>* curPtr = headPtr;
    for (int skip =1; skip< position; ++skip)
        curPtr = curPtr->getNext();
    return curPtr;
}// end get Node At

*/
