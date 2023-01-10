#include <iostream>
#include <vector>

enum ENTITY_ID {CAT_ID = 0, MOUSE_ID, DOG_ID};

// создаем иерархию, может лежать вообще говоря в разных пакетах
class Entity 
{
public:
    virtual void whoami() = 0; // pure virtual
    virtual ~Entity() {}
};

class Cat : public Entity 
{
    void whoami() {
        std::cout << "i am cat\n";
    }
};

class Mouse : public Entity 
{
    void whoami() {
        std::cout << "i am mouse\n";
    }
};

class Dog : public Entity 
{
    void whoami() {
        std::cout << "i am dog\n";
    }
};

// общий класс фабрики, иерархия фабрик
class Factory
{
public:
    virtual Entity* create_entity() = 0;
    virtual ~Factory() {}
};

class CatFactory 
{
public:
    Entity *create_entity() {
        return new Cat;
    }
};

class MouseFactory 
{
public:
    Entity *create_entity() {
        return new Mouse;
    }
};

class DogFactory 
{
public:
    Dog *create_entity() {
        return new Dog;
    }
};

int main() 
{
    MouseFactory* mF = new MouseFactory;
    CatFactory* cF = new CatFactory;
    DogFactory* dF = new DogFactory;

    std::vector<Entity*> base;

    base.push_back(cF->create_entity());
    base.push_back(mF->create_entity());
    base.push_back(dF->create_entity());

    for (auto it = base.begin(); it != base.end(); it++)
        (*it)->whoami();

    return 0;
}