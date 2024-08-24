#ifndef _OBSERVATEUR_HPP
#define _OBSERVATEUR_HPP

#include <iostream>
#include <memory>

template <typename T>
class Observateur {
public:
    virtual ~Observateur() = default;
    virtual void update(const T& data) = 0;
};

#endif
