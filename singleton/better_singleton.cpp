#include <iostream>
class Singleton;  // опережающее объявление

class SingletonDestroyer
{
private:
    Singleton* p_instance;
public:    
    ~SingletonDestroyer();
    void initialize( Singleton* p );
};

class Singleton
{
private:
    static Singleton* p_instance;
    static SingletonDestroyer destroyer;
protected: 
    Singleton() { }
    Singleton( const Singleton& );
    Singleton& operator=( Singleton& );
    ~Singleton() { }
    friend class SingletonDestroyer;
public:
    static Singleton& getInstance();    
};

Singleton * Singleton::p_instance = 0;
SingletonDestroyer Singleton::destroyer;

SingletonDestroyer::~SingletonDestroyer() {   
    std::cout << "instance deleted\n";
    delete p_instance; 
}

void SingletonDestroyer::initialize( Singleton* p ) {
    std::cout << "instance created\n";
    p_instance = p; 
}

Singleton& Singleton::getInstance() {
    if(!p_instance) {
        p_instance = new Singleton();
        destroyer.initialize( p_instance);     
    }
    return *p_instance;
}

int main() {
    Singleton &t = Singleton::getInstance();
}