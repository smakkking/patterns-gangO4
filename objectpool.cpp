class Reusable {
    // произвольный класс
};

class ReusablePool
{
    bool *state;
    Reusable *data;
    int _size;
private: 
    ReusablePool() {}
    ReusablePool( const ReusablePool&);  
    ReusablePool& operator=( ReusablePool& );
public:
    static ReusablePool& getInstance() {
        static ReusablePool instance;
        return instance;
    }    
    Reusable & acquireReusable() {
        for (int i = 0; i < _size; i++)
            if (state[i]) {
                state[i] = false;
                return data[i];
            }
    }
    void releaseReusable(Reusable & obj) {
        for (int i = 0; i < _size; i++)
            if (data[i] == obj) {
                state[i] = true;
            }
    }
    void setMaxPoolSize(int size) {
        _size = size;
        state = new bool[_size];
        for (int i = 0; i < _size; i++) {
            state[i] = true;
        }
        data = new Reusable[_size];
    }
    ~ReusablePool() {
        delete data [];
        delete state [];
    }
}; 