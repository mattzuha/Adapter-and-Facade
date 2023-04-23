#include <iostream>
#include <stdexcept>

using namespace std;
// Enumeration interface
class Enumeration {
public:
    virtual bool hasMoreElements() = 0;
    virtual int nextElement() = 0;
};

// Iterator interface
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual int next() = 0;
    virtual void remove() = 0;
};

// EnumerationIterator adapter
class EnumerationIterator : public Iterator {
public:
    EnumerationIterator(Enumeration* enumeration) : _enumeration(enumeration) {}

    bool hasNext() {
        return _enumeration->hasMoreElements();
    }

    int next() {
        return _enumeration->nextElement();
    }

    void remove() {
        throw runtime_error("remove() is not supported by EnumerationIterator");
    }

private:
    Enumeration* _enumeration;
};

// Concrete Enumeration implementation
class ConcreteEnumeration : public Enumeration {
public:
    ConcreteEnumeration(int data[], int size) : _data(data), _size(size), _position(0) {}

    bool hasMoreElements() {
        return _position < _size;
    }

    int nextElement() {
        if (!hasMoreElements()) {
            throw runtime_error("no more elements");
        }
        return _data[_position++];
    }

private:
    int* _data;
    int _size;
    int _position;
};

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(int);

    // Create an Enumeration
    ConcreteEnumeration enumeration(data, size);

    // Create an EnumerationIterator adapter
    EnumerationIterator iterator(&enumeration);

    // Use the adapter as an Iterator
    cout << "Iterating through the data using EnumerationIterator:\n";
    while (iterator.hasNext()) {
        int element = iterator.next();
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
