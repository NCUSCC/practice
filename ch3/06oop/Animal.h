#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;
    int age;

public:
    Animal(std::string n, int a) : name(n), age(a) {}

    virtual void makeSound() const = 0; // 纯虚函数，使Animal成为抽象基类

    virtual void showInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    virtual ~Animal() {} // 虚析构函数，确保派生类的正确析构
};

#endif