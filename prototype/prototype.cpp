#include <iostream>
#include <map>
#include <vector>

enum ANIMAL_ID{CAT_ID, DOG_ID, COW_ID};

// создаем единое (через singleton мейерса) хранилище прототипов
class Animal;
typedef std::map<ANIMAL_ID, Animal*> Registry;

Registry& getRegistry() {
    static Registry _abc;
    return _abc;
}

class InicializerHelper{}; // нужен только для того, чтобы инициализировать прототипы

// базовый класс для объектов
class Animal 
{
public:
    virtual Animal* clone() = 0;
    virtual ~Animal() {}
    virtual void info() = 0;
    static Animal* createAnimal(ANIMAL_ID id) {
        Registry &reg = getRegistry();
        if (reg.find(id) != reg.end()) {
            return reg[id]->clone();
        }
        return nullptr;
    }
protected:
    static void addProtorype(ANIMAL_ID id, Animal* prototype) {
        Registry &reg = getRegistry();
        reg[id] = prototype;
    }
};

class Cat : public Animal {
public:
    Animal* clone() {
        return new Cat(*this); // такая штука возможна, потому что констрктор копирования создается по умл
    }
    void info() {
        std::cout << "i am cat\n";
    }
private:
    Cat(InicializerHelper x) {
        Animal::addProtorype(CAT_ID, &this->prototype);
    }
    Cat() {} // нужен для запрета создания переменной, чтобы можно было только копировать от прототипа
    static Cat prototype; // фактически нужен для создания одного прототипа на весь класс.
};

class Dog : public Animal {
public:
    Animal* clone() {
        return new Dog(*this);
    }
    void info() {
        std::cout << "i am dog\n";
    }
private:
    Dog(InicializerHelper x) {
        Animal::addProtorype(DOG_ID, &this->prototype);
    }
    Dog() {} 
    static Dog prototype; 
};

class Cow : public Animal {
public:
    Animal* clone() {
        return new Cow(*this);
    }
    void info() {
        std::cout << "i am cow\n";
    }
private:
    Cow(InicializerHelper x) {
        Animal::addProtorype(COW_ID, &this->prototype);
    }
    Cow() {} 
    static Cow prototype; 
};

// поле для инициализации статических членов прототипов для каждого класса
Cat Cat::prototype = Cat(InicializerHelper());
Cow Cow::prototype = Cow(InicializerHelper());
Dog Dog::prototype = Dog(InicializerHelper());

int main()
{       
    std::vector<Animal*> v;
    v.push_back( Animal::createAnimal(CAT_ID));
    v.push_back( Animal::createAnimal(DOG_ID));
    v.push_back( Animal::createAnimal(COW_ID));
    for(int i=0; i<v.size(); i++)
        v[i]->info();
}











