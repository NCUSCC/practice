#include "Cat.h"
#include "Dog.h"
#include "Monkey.h"
#include <vector>

int main() {
    std::vector<Animal*> zoo;

    zoo.push_back(new Cat("Whiskers", 3));
    zoo.push_back(new Dog("Fido", 5));
    zoo.push_back(new Monkey("George", 7));
    zoo.push_back(new Monkey("Mike", 3));

    for (auto animal : zoo) {
        animal->showInfo();
        animal->makeSound();
    }

    // 清理
    for (auto animal : zoo) {
        delete animal;
    }
    zoo.clear();

    return 0;
}