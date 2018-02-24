//
//  PrecondViolatedExcept.hpp
//  Lab3
//
//  Created by Rudolf Musika on 2/20/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#ifndef PrecondViolatedExcept_hpp
#define PrecondViolatedExcept_hpp

#include <stdexcept>
#include <string>

/** @class PrecondViolatedExcept PrecondViolatedExcept.hpp "PrecondViolatedExcept.hpp"
 *
 *  Specification for an object thrown on violation of precondition. */
class PrecondViolatedExcept : public std::logic_error {
public:
    explicit PrecondViolatedExcept(const std::string& message = "");
    
    virtual ~PrecondViolatedExcept() noexcept = default; //throw();
};// end PrecondViolatedExcept


#endif /* PrecondViolatedExcept_hpp */
