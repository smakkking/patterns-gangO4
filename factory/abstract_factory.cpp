#include <iostream>

class AbstractProductA 
{
public:
    virtual void info() = 0;
    virtual ~AbstractProductA() {}
};

class AbstractProductB
{
public:
    virtual void info() = 0;
    virtual ~AbstractProductB() {}
};

// семейство2
class ProductA2 : public AbstractProductA 
{
public:
    void info() {
        std::cout << "productA2" << std::endl;
    }
};

class ProductB2 : public AbstractProductB 
{
public:
    void info() {
        std::cout << "productB2" << std::endl;
    }
};

// семейство1
class ProductA1 : public AbstractProductA 
{
public:
    void info() {
        std::cout << "productA1" << std::endl;
    }
};

class ProductB1 : public AbstractProductB 
{
public:
    void info() {
        std::cout << "productB1" << std::endl;
    }
};

class AbstractFactory 
{
public:
    virtual AbstractProductA *createProductA() = 0;
    virtual AbstractProductB *createProductB() = 0;
    virtual ~AbstractFactory() {}
};

// создание объекта семейства1
class ConcreteFactory1 : public AbstractFactory
{
public:
    AbstractProductA *createProductA() {
        return new ProductA1;
    }
    AbstractProductB *createProductB() {
        return new ProductB1;
    }
};

// создание объекта семейства2
class ConcreteFactory2 : public AbstractFactory
{
public:
    AbstractProductA *createProductA() {
        return new ProductA2;
    }
    AbstractProductB *createProductB() {
        return new ProductB2;
    }
};

class Client
{
    AbstractProductA *apA_array;
    AbstractProductB *apB_array;
    AbstractFactory *aF;
public: 
    Client(AbstractFactory *t) {
        aF = t;
        apA_array = aF->createProductA();
        apB_array = aF->createProductB();
    }
    void info() {
        apA_array->info();
        apB_array->info();
    }
};

int main() {
    ConcreteFactory1 *cF1 = new ConcreteFactory1;
    ConcreteFactory2 *cF2 = new ConcreteFactory2;
    Client c1(cF1), c2(cF2);

    c1.info();
    std::cout << std::endl;
    c2.info();

}