#include <iostream>
#include <vector>

class BaseClass
{
public:
    virtual void operation() = 0;
};

class Primitive1 : public BaseClass 
{
public:
    void operation() {
        std::cout << "primitive1\n";
    };
};

class Primitive2 : public BaseClass 
{
public:
    void operation() {
        std::cout << "primitive2\n";
    };
};

class Composite : public BaseClass
{
    std::vector<BaseClass*> p;
public:

    void operation() {
        for (int i = 0; i < p.size(); i++)
            p[i]->operation();
    }
    void add(BaseClass *item) {
        p.push_back(item);
    }
    void remove(BaseClass *item) {
        // типа должно быть реализовано
    }
    ~Composite() {
        for (int i = 0; i < p.size(); i++)
            delete p[i];
    }
};

Composite* createlevel1() {
    Composite* tmp = new Composite;

    for (int i = 0; i < 2; i++) 
        tmp->add(new Primitive1);
    for (int i = 0; i < 2; i++) 
        tmp->add(new Primitive2);

    return tmp;
}

Composite* createlevel2() {
    Composite* tmp = new Composite;

    for (int i = 0; i < 4; i++) 
        tmp->add(createlevel1());

    return tmp;
}

int main() {
    Composite* fina = createlevel2();

    fina->operation();

    delete fina;
}
