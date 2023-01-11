#include <string>
#include <string.h>
#include <iostream>

class Adatee 
{
public:
    std::string func1() {
        return "  dfgsdfgdfsg";
    }
    std::string func2() {
        return "pl[pasdsf]";
    }
};

class Target
{
public:
    virtual ~Target() {}
    // interface discribing
    virtual std::string func1() = 0; // возвращает строку без пробелов впереди
    virtual std::string func2() = 0; // возвращает строку без символов квадратных скобок
};

class Adapter : public Target
{
    Adatee *instance;
public:
    Adapter(Adatee *p) : instance(p) {}
    ~Adapter() {
        delete instance;
    }
    std::string func1() {
        std::string res = "", input = instance->func1();
        bool flag = false;
        for (int i = 0; i < input.length(); i++) {
            if (std::isspace(input[i]) && !flag)
                continue;
            else {
                flag = true;
                res += input[i];
            }
        }
        return res;
    }
    std::string func2() {
        std::string res = "", input = instance->func2();
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '[' || input[i] == ']')
                continue;
            else {
                res += input[i];
            }
        }
        return res;
    }
};

int main() {
    Target* p = new Adapter(new Adatee);
    std::cout << p->func1() << std::endl << p->func2() << std::endl;
    return 0;

}