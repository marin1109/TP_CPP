#ifndef BOXINT_HPP
#define BOXINT_HPP

#include <iostream>
#include <ctime>

class BoxInt {
    private:
        int m_value;
        mutable std::time_t last_access;
        static int instance_count;

    public:
        BoxInt();
        BoxInt(int value);
        ~BoxInt();

        int getValue() const;
        void setValue(int value);

        friend std::ostream& operator<<(std::ostream& os, const BoxInt& boxInt);

        static int alive_instances();

};

#endif // BOXINT_HPP
