#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
 
class Component
{
    int value;
    // 1. Указатель "next" в базовом классе
    Component *next; 
public:
    Component(int v, Component *n)
    {
        value = v;
        next = n;
    }
    void setNext(Component *n)
    {
        next = n;
    }
    virtual void traverse()
    {
        cout << value << ' ';
    }
    // 2. Метод базового класса, делегирующий запрос next-объекту
    virtual void volunteer()
    {
        next->volunteer();
    }
};
 
class Primitive: public Component
{
public:
    Primitive(int val, Component *n = 0): Component(val, n){}
    void volunteer()
    {
        Component::traverse();
        // 3. Примитивные объекты не обрабатывают 5 из 6 запросов
        if (rand() *100 % 6 != 0)
        // 3. Делегируем запрос в базовый класс
        Component::volunteer();
    }
};
 
class Composite: public Component
{
    vector < Component * > children;
public:
    Composite(int val, Component *n = 0): Component(val, n){}
    void add(Component *c)
    {
        children.push_back(c);
    }
    void traverse()
    {
        Component::traverse();
        for (int i = 0; i < children.size(); i++)
            children[i]->traverse();
    }
    // 3. Составные объекты никогда не обрабатывают запросы
    void volunteer()
    {
        Component::volunteer();
    }
};
 
int main()
{
    srand(time(0));                 // 1
    Primitive seven(7);             // |
    Primitive six(6, &seven);       // +-- 2
    Composite three(3, &six);       // |   |
    three.add(&six);
    three.add(&seven);              // |   +-- 4 5
    Primitive five(5, &three);      // |
    Primitive four(4, &five);       // +-- 3
    Composite two(2, &four);        // |   |
    two.add(&four);
    two.add(&five);                 // |   +-- 6 7
    Composite one(1, &two);         // |
    Primitive nine(9, &one);        // +-- 8 9
    Primitive eight(8, &nine);
    one.add(&two);
    one.add(&three);
    one.add(&eight);
    one.add(&nine);
    seven.setNext(&eight);
    cout << "traverse: ";
    one.traverse();
    cout << '\n';
    for (int i = 0; i < 8; i++)
    {
        one.volunteer();
        cout << '\n';
    }
}