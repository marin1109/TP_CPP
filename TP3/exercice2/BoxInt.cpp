#include "BoxInt.hpp"

using namespace std;

int BoxInt::instance_count = 0;

BoxInt::BoxInt(): m_value{0}, last_access{std::time(nullptr)} {
    ++instance_count;
    cout << "BoxInt créée avec succès !" << endl;
}

BoxInt::BoxInt(int value): m_value{value}, last_access{std::time(nullptr)} {
    ++instance_count;
    cout << "BoxInt créée avec succès !" << endl;
}

BoxInt::~BoxInt() {
    --instance_count;
    cout << "BoxInt détruite avec succès !" << endl;
}

int BoxInt::getValue() const {
    last_access = std::time(nullptr);
    return m_value;
}

void BoxInt::setValue(int value) {
    m_value = value;
}

ostream& operator<<(ostream& os, const BoxInt& boxInt) {
    os << "BoxInt(" << boxInt.m_value << ")";
    return os;
}

int BoxInt::alive_instances() {
    return instance_count;
}