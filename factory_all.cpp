#include <iostream>
#include <vector>

enum ENTITY_ID {CAT_ID = 0, MOUSE_ID, DOG_ID};

class Entity 
{
public:
    virtual void whoami() = 0; // pure virtual
    virtual ~Entity() {}
    static Entity *create_entity(ENTITY_ID);
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

Entity *Entity::create_entity(ENTITY_ID id) 
{
    Entity *res;
    switch (id) 
    {
        case CAT_ID:
            res = new Cat;
            break;
        case MOUSE_ID:
            res = new Mouse;
            break;
        case DOG_ID:
            res = new Mouse;
            break;
    }
    return res;
}

int main() 
{
    std::vector<Entity*> base;

    base.push_back(Entity::create_entity(CAT_ID));
    base.push_back(Entity::create_entity(MOUSE_ID));
    base.push_back(Entity::create_entity(DOG_ID));

    for (auto it = base.begin(); it != base.end(); it++)
        (*it)->whoami();

    return 0;
}