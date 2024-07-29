#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
    Dog(std::string n, int a) : Animal(n, a) {}

    void makeSound() const override {
        std::cout << name << " says Woof!" << std::endl;
    }
};

#endif