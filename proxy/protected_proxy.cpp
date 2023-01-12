#include <iostream>

class Subject 
{
public:
    virtual void dolt() = 0;
};

class RealSubject : public Subject
{
public:
    void dolt() {
        std::cout << "operation ended\n";
    }
};

class Proxy : public Subject
{
    RealSubject* p;
    std::string name;
public:
    Proxy(std::string s) {
        p = new RealSubject;
        name = s;
    }
    void dolt() {
        // когда операция ывызывается, объект создается
        if (name == "Bob")
            std::cout << "can't evaluate operation\n";
        else 
            p->dolt();
    }
    ~Proxy() {
        delete p;
    }
};

int main() {
    // типа регистрация
    Subject* tmp1 = new Proxy("alma");
    Subject* tmp2 = new Proxy("Bob");

    tmp1->dolt();
    tmp2->dolt();

    delete tmp1;
    delete tmp2;

}