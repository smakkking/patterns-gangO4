#include <iostream>
#include <vector>

class Animal 
{
public:
    virtual Animal* clone() = 0;
    virtual ~Animal() {}
    virtual void info() = 0;
};

class Cat : public Animal {
    friend class PrototypeFactory;
public:
    Animal* clone() {
        return new Cat(*this); // такая штука возможна, потому что констрктор копирования создается по умл
    }
    void info() {
        std::cout << "i am cat\n";
    }
private:
    Cat() {} // нужен для запрета создания переменной, чтобы можно было только копировать от прототипа
};


class Dog : public Animal {
    friend class PrototypeFactory;
public:
    Animal* clone() {
        return new Dog(*this);
    }
    void info() {
        std::cout << "i am dog\n";
    }
private:
    Dog() {} 
};

class Cow : public Animal {
    friend class PrototypeFactory;
public:
    Animal* clone() {
        return new Cow(*this);
    }
    void info() {
        std::cout << "i am cow\n";
    }
private:
    Cow() {} 
};

class PrototypeFactory
{
public:
    Animal* createCat() {
        static Cat prototype;
        return prototype.clone();
    }

    Animal* createDog() {
        static Dog prototype;
        return prototype.clone();
    }

    Animal* createCow() {
        static Cow prototype;
        return prototype.clone();
    }
};

int main() {
    PrototypeFactory pf;
    std::vector<Animal*> v;
    v.push_back(pf.createCat());
    v.push_back(pf.createCow());
    v.push_back(pf.createDog());
    for(int i=0; i<v.size(); i++)
        v[i]->info();
}