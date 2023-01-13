#include <iostream>
#include <string>

class Interface
{
public:
    virtual ~Interface() {}
    virtual std::string doThis() = 0;
};

class CoreFunctionality : public Interface
{
public:
    std::string doThis() {
        std::string a = "a";
        return a;
    }
};

class OptionalWrapper : public Interface
{
    Interface *wrapper;
public:
    OptionalWrapper(Interface *p) : wrapper(p) {}
    ~OptionalWrapper() {
        delete wrapper;
    }
    std::string doThis() {
        return wrapper->doThis();
    }
};

class Optional1 : public OptionalWrapper
{
public:
    Optional1(Interface *p) : OptionalWrapper(p) {}
    std::string doThis() {
        return "optional1(" + OptionalWrapper::doThis() + ")";
    }
};

class Optional2 : public OptionalWrapper
{
public:
    Optional2(Interface *p) : OptionalWrapper(p) {}
    std::string doThis() {
        return "optional2(" + OptionalWrapper::doThis() + ")";
    }
};

class Optional3 : public OptionalWrapper
{
public:
    Optional3(Interface *p) : OptionalWrapper(p) {}
    std::string doThis() {
        return "optional3(" + OptionalWrapper::doThis() + ")";
    }
};

int main() {
    Interface *p1 = new Optional3(new Optional2(new CoreFunctionality));
    std::cout << p1->doThis() << std::endl;
    delete p1;

    Interface *p2 = new Optional1(new Optional3(new CoreFunctionality));
    std::cout << p2->doThis() << std::endl;
    delete p2;

    return 0;
}
