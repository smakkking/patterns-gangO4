class SingletonMayers
{
private: 
    SingletonMayers() {}
    SingletonMayers( const SingletonMayers&);  
    SingletonMayers& operator=( SingletonMayers& );
public:
    static SingletonMayers& getInstance() {
        static SingletonMayers instance;
        return instance;
    }    
}; 


int main() {
    SingletonMayers a = SingletonMayers::getInstance();
    return 0;
}