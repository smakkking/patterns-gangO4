#include <iostream>
using namespace std;

class A {
    public:
    A() {
        cout << "create instance A\n";
    }
    ~A() {
        cout << "delete instance A\n";
    }
};

class B {
    private:
        static A *ptr;
public:
    B() {
        cout << "create instance B\n";
    }
    ~B() {
        cout << "delete instance B\n";
    }
};

A *B::ptr = new A;

int main() {
    B();
    return 0;
}