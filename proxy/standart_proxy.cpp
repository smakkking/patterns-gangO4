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
        std::cout << "operation ended";
    }
    RealSubject() {
        std::cout << "realsubject created\n";
    }
};

class Proxy : public Subject
{
    RealSubject* p;
public:
    Proxy() {
        p = 0; // сначала ничего нет
    }
    void dolt() {
        // когда операция ывызывается, объект создается
        if (!p) {
            p = new RealSubject;
        }
        p->dolt();
    }
    ~Proxy() {
        delete p;
    }
};

int main() {
    Subject* tmp = new Proxy;

    // что-то поделали
    std::cout << "do smth\n";
    tmp->dolt();
}