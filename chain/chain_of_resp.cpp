#include <iostream>

class Base
{
    Base *next;
public:
    Base() {
        next = 0;
    }
    void setNext(Base *n) {
        next = n;
    }
    void add(Base *n) {
        if (next) {
            next->add(n);
        } else {
            setNext(n);
        }
    }
    virtual void handle(int value) {
        if (next)
            next->handle(value);
    }
};

class HandlerMoney : public Base
{
    int del;
public:
    HandlerMoney(int d) : del(d) {}
    void handle(int value) {
        if (value / del != 0)
            std::cout << del << ": " << value / del << std::endl;
        Base::handle(value % del);
    }
};

int main() {
    // инициализируем сами обработчики
    HandlerMoney a5000(5000), a1000(1000), a500(500), a100(100);
    Base root;
    // составляем очередь из обработчиков
    root.add(&a5000);
    root.add(&a1000);
    root.add(&a500);
    root.add(&a100);
    root.handle(112352300); // запускаем
    return 0;
}