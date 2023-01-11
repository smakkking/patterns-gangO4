#include <iostream>

class Implementor
{
public:
    virtual void operationImp1() = 0;
    virtual ~Implementor() {}
};

class ConcreteImplementor1 : public Implementor
{
public:
    void operationImp1() {
        std::cout << "op1\n";
    }
};

class Abstraction
{
protected:
    Implementor *imp;
public:
    virtual void operation() = 0;
    virtual ~Abstraction() {
        delete imp;
    }
    Abstraction(Implementor *p) : imp(p) {}
};

class RefinedAbstraction1 : public Abstraction
{
public:
    RefinedAbstraction1() : Abstraction(new ConcreteImplementor1) {
        // вообще говоря здесь должны стоять правила, как и какая конкретная реализация создается
    }
    void operation() {
        imp->operationImp1();
    }
};

int main() {
    RefinedAbstraction1 *p = new RefinedAbstraction1();
    p->operation();
    delete p;
}