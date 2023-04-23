#include <iostream>
using namespace std;
class Duck
{
public:
    virtual void quack() {}
    virtual void fly() {}
};

class MallardDuck : public Duck
{
public:
    void quack()
    {
        cout << "Quack" << endl;
    }
    void fly()
    {
        cout << "I'm flying" << endl;
    }
};

class Turkey
{
public:
    virtual void gobble() {}
    virtual void fly() {}
};

class WildTurkey : public Turkey
{
public:
    void gobble()
    {
        cout << "Gobble gobble" << endl;
    }
    void fly()
    {
        cout << "I'm flying a short distance" << endl;
    }
};

class TurkeyAdapter : public Duck
{
    Turkey *turkey;

public:
    TurkeyAdapter(Turkey *turkey)
    {
        this->turkey = turkey;
    }
    void quack()
    {
        turkey->gobble();
    }
    void fly()
    {
        for (int i = 0; i < 5; i++)
        {
            turkey->fly();
        }
    }
};

int main()
{
    Duck *duck = new MallardDuck();
    Turkey *turkey = new WildTurkey();
    Duck *turkeyAdapter = new TurkeyAdapter(turkey);

    cout << "The MallardDuck says..." << std::endl;
    duck->quack();
    duck->fly();

    cout << "\nThe WildTurkey says..." << std::endl;
    turkey->gobble();
    turkey->fly();

    cout << "\nThe TurkeyAdapter says..." << std::endl;
    turkeyAdapter->quack();
    turkeyAdapter->fly();

    delete duck;
    delete turkey;
    delete turkeyAdapter;

    return 0;
}
