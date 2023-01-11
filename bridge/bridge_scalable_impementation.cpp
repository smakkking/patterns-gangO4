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
        std::cout << "op1, imp1\n";
    }
};

class ConcreteImplementor2 : public Implementor
{
public:
    void operationImp1() {
        std::cout << "op1, imp2\n";
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
    RefinedAbstraction1(Implementor *p) : Abstraction(p) {
        // вообще говоря здесь должны стоять правила, как и какая конкретная реализация создается
    }
    void operation() {
        imp->operationImp1();
    }
};

int main() {
    RefinedAbstraction1 *p1 = new RefinedAbstraction1(new ConcreteImplementor1);
    p1->operation();

    RefinedAbstraction1 *p2 = new RefinedAbstraction1(new ConcreteImplementor2);
    p2->operation();
    
    delete p1;
    delete p2;
}