#ifndef _VALEURSADMISES_HPP
#define _VALEURSADMISES_HPP

#include <iostream>

class ValeursAdmises {
public:
    virtual bool operator()(char val) const = 0;
    virtual ~ValeursAdmises() {}
};

#endif
