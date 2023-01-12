#include <iostream>

class Intrenal
{
    friend class Facade12;
private:
    Intrenal() {};
    Intrenal(const Intrenal&);
    Intrenal& operator=(Intrenal&);
public:
    void func1() {
        std::cout << "func1\n";
    }
    void func2() {
        std::cout << "func2\n";
    }
    void func3() {
        std::cout << "func3\n";
    }
};

class Facade12
{
    Intrenal *p;
public:
    Facade() {
        p = new Intrenal;
    }
    void func1() {
        p->func1();
    }
    void func2() {
        p->func2();
    }
    ~Facade() {
        delete p;
    }
};

int main() {
    Facade12 p;
    p.func1();
    p.func2();
    // p.func3();
    return 0;
}