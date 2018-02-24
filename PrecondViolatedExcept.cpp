//
//  PrecondViolatedExcept.cpp
//  Lab3
//
//  Created by Rudolf Musika on 2/20/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//
#include <stdexcept>
#include <string>
#include "PrecondViolatedExcept.hpp"
/** @file PrecondViolatedExcept.cpp */

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message)
    : std::logic_error( message.c_str() ) {
}
// end constructor
