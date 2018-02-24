/** @file
 *
 *  @course CS1521
 *  @section 3
 *
 *  Implementation file for the class LinkedSet.
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

#include<iostream>
#include<cstdlib>

#include "LinkedList.hpp"


int getPosition(LinkedList<int> alist,int aValue){
    
    /*
     while( alist != end && aValue <= getLength()){
     int i(0);
     bool = alist(getEntry(i))
     i++
     }
     */
        // Local variable declaration:
        int pos = 1;
        bool isFound(false);
        
        // do loop execution
        do {
            if (alist.getEntry(pos) == aValue)
                isFound = true;
            
            else if (isFound == false)
                pos++;
            
        }
    while((isFound == false) && (pos<=alist.getLength()));
    
        if(isFound ==false)
            pos = -1; //alist.getLength() + 1; - because it is not a posible indexs
        return pos;
}
        

