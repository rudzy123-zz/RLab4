//
//  main.cpp
//  Lab3
//
//  Created by Rudolf Musika on 2/20/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "LinkedList.hpp"
#include "getPosition.h"

int main(){
    
    LinkedList<int> list;
    list.insert(1, 9);
    list.insert(2, 5);
    list.insert(1, 0);
    list.insert(2, 3);
    list.insert(4, 2);
    
    int position(0);
    int value(0);
    
    while (std::cin >> value) {
        
        if ((position = getPosition(list, value)) <= list.getLength() )
        {
            std::cout << "list["
            << position
            << "] = "
            << value
            << "."
            << std::endl;
        }
        else {
            std::cout << "The list does NOT contain "
            << value
            << "."
            << std::endl;
        }
    }
    
    return EXIT_SUCCESS;
}

