#include <iostream>
using namespace std;

template<class T>
class TraversalAbstracion {
public:
    virtual ~TraversalAbstracion() {}
    virtual T first() = 0;
    virtual T next() = 0;
    virtual bool isDone() = 0;
    virtual T currentItem() = 0;
};

template <class T>
class Collection {
public:
    virtual ~Collection() {}
    virtual TraversalAbstracion<T>* createTraversalObject() = 0;
};

class ListCollection;

template<class T>
class ListTraversal : public TraversalAbstracion<T>
{
    ListCollection *coll;
    int curr;
public:
    ListTraversal(ListCollection *tmp) : coll(tmp) {
        curr = 0;
    }
    T first() {
        return coll->ast[0];
    }
    T next() {
        return coll->ast[curr++];
    }
    bool isDone() {
        return curr == coll->_N;
    }
    T currentItem() {
        return coll->ast[curr];
    }
};

class ListCollection : public Collection<int> {
    friend ListTraversal<int>;

    int *ast;
    int _N;
public:
    ListCollection(int N) {
        _N = N;
        ast = new int[_N];
        for (int i = 0; i < _N; i++)
            ast[i] = i * i;
    }
    TraversalAbstracion<int>* createTraversalObject() {
        return new ListTraversal<int>(this);
    }

    ~ListCollection() {
        delete [] ast;
    }
};



class Client {
public: 
    void main() {
        const int N = 10;
        Collection<int> *c = new ListCollection(N);

        TraversalAbstracion<int> *it1 = c->createTraversalObject();

        while (!it1->isDone()) {
            cout << it1->next() << endl;
        }

        delete it1;
    }
};


int main() {
    Client c;
    c.main();
}

