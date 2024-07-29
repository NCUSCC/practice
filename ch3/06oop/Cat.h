#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
    Cat(std::string n, int a) : Animal(n, a) {}

    void makeSound() const override {
        std::cout << name << " says Meow!" << std::endl;
    }
};

#endif