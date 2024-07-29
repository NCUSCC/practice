#ifndef MONKEY_H
#define MONKEY_H

#include "Animal.h"

class Monkey : public Animal {
public:
    Monkey(std::string n, int a) : Animal(n, a) {}

    void makeSound() const override {
        std::cout << name << " says Ooh ooh aah aah!" << std::endl;
    }
};

#endif