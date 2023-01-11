#include <iostream>

class Product1
{
    public:
    void info() {
        std::cout << "i am product1\n";
    }
};

class Product2 
{
public:
    void info() {
        std::cout << "i am product2\n";
    }
};

// тот самый объект, который мы создаем по частям
class Entity
{
public:
    Product1 *pr1;
    Product2 *pr2;
    void info() {
        pr1->info();
        pr2->info();
    }
};

class Builder
{
protected:
    Entity *ent;
public:
    void createEntity() {
        ent = new Entity;
    }
    virtual void buildProduct1() {};
    virtual void buildProduct2() {};
    virtual Entity* getProduct() = 0;
    virtual ~Builder() {delete ent;}
};

class ConcreteBuilder : public Builder 
{
public:
    void buildProduct1() {
        std::cout << "product1 created!\n";
        ent->pr1 = new Product1;
    }
    void buildProduct2() {
        std::cout << "product2 created!\n";
        ent->pr2 = new Product2;
    }
    Entity* getProduct() {
        return ent;
    }
};

class Director
{
public: 
    Entity* construct(Builder *b) {
        b->createEntity();
        b->buildProduct1();
        b->buildProduct2();
        return b->getProduct();
    }
};

int main() {
    ConcreteBuilder *cb = new ConcreteBuilder;
    Director dr;

    Entity *ent = dr.construct(cb);
    ent->info();
    return 0;
}