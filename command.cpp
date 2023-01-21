#include <iostream>
#include <vector>

using namespace std;

// хотя Receiver может быть много
class Receiver
{
public:
    virtual ~Receiver() {}
    void action1() {
        cout << "action1" << endl;
    }
    void action2() {
        cout << "action2" << endl;
    }
};

class Command
{
protected:
    Receiver *r;
    Command(Receiver *tmp) : r(tmp) {}
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

class Command1 : public Command
{
public:
    Command1(Receiver *tmp) : Command(tmp) {}
    void execute() {
        r->action1();
    }
};

class Command2 : public Command
{
public:
    Command2(Receiver *tmp) : Command(tmp) {}
    void execute() {
        r->action2();
    }
};

class Invoker
{
    vector<Command*> command_seq;
public:
    void go() {
        for (int i = 0; i < command_seq.size(); i++)
            command_seq[i]->execute();
    }
    void insert_command(Command *com) {
        command_seq.push_back(com);
    }
    ~Invoker() {
        for (int i = 0; i < command_seq.size(); i++)
            delete command_seq[i];
    }
};

int main() {
    Invoker t;
    Receiver *r = new Receiver;
    t.insert_command(new Command1(r));
    t.insert_command(new Command2(r));
    t.insert_command(new Command2(r));
    t.insert_command(new Command1(r));

    t.go();
    delete r;
}