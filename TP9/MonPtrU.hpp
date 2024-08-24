#ifndef _MONPTRU_HPP
#define _MONPTRU_HPP

#include <set>
#include <stdexcept>

template <typename T>
class Mon_ptr_u {
private:
    T* ptr;  // Pointeur vers l'objet de type T
    static std::set<T*> addresses;  // Liste statique des adresses encapsulées

public:
    // Constructeur prenant un pointeur en argument
    explicit Mon_ptr_u(T* p = nullptr) : ptr(p) {
        if (ptr) {
            if (addresses.find(ptr) != addresses.end()) {
                throw std::runtime_error("L'adresse de cet objet est déjà encapsulée !");
            }
            addresses.insert(ptr);
        }
    }

    // Destructeur
    ~Mon_ptr_u() {
        addresses.erase(static_cast<T*>(ptr));
        delete ptr;
    }

    // Move constructor (constructeur par déplacement)
    Mon_ptr_u(Mon_ptr_u&& other) noexcept : ptr(other.ptr) {
        addresses.erase(other.ptr);
        other.ptr = nullptr;
    }

    Mon_ptr_u& operator=(Mon_ptr_u& p) {
        if (this != &p) {
            if (ptr) {
                addresses.erase(static_cast<T*>(ptr));
                delete ptr;
            }
            ptr = p.ptr;
            p.ptr = nullptr;
        }
        return *this;
    }

    // Move assignment operator
    Mon_ptr_u& operator=(Mon_ptr_u&& other) noexcept {
        if (this != &other) {
            addresses.erase(ptr);
            delete ptr;
            ptr = other.ptr;
            addresses.insert(ptr);
            other.ptr = nullptr;
        }
        return *this;
    }

    // Conversion en bool pour vérifier si le pointeur est non nul
    operator bool() const {
        return ptr != nullptr;
    }

    // Surcharge de l'opérateur * pour accéder à l'objet pointé
    T& operator*() const {
        if (!ptr) {
            throw std::runtime_error("Déréférencement d'un pointeur nul.");
        }
        return *ptr;
    }

    // Surcharge de l'opérateur -> pour accéder aux membres de l'objet pointé
    T* operator->() const {
        if (!ptr) {
            throw std::runtime_error("Accès aux membres via un pointeur nul.");
        }
        return ptr;
    }

    // Méthode release() pour libérer l'objet géré
    T* release() {
        T* old_ptr = ptr;
        ptr = nullptr;
        return old_ptr;
    }

    // Échange des pointeurs encapsulés
    void echange(Mon_ptr_u& other) {
        std::swap(ptr, other.ptr);
    }

};

// Initialisation du membre statique
template <typename T>
std::set<T*> Mon_ptr_u<T>::addresses;

#endif
