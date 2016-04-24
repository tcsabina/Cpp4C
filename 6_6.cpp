#include <iostream>
#include <string.h>

class proc_data {
public:
    virtual void print() { std::cout << "virtual\n"; }
};

struct X {
    int  age;
    char name[20];
};

class X_data : public proc_data {
    X* d;
public:
    X_data(int i, char* n) { d = new X; d->age = i; strcpy(d->name, n); }
    ~X_data() { delete d; }
    void print() { std::cout << d->name << " " << d->age << " yrs\n"; }
};

struct Y {
    int  salary;
    char name[20];
};

class Y_data : public proc_data {
    Y* d;
public:
    Y_data(int i, char* n) { d = new Y; d->salary = i; strcpy(d->name, n); }
    ~Y_data() { delete d; }
    void print() { std::cout << d->name << " " << d->salary << "\n"; }
};

struct Z {
    int  phone;
    char state[5];
};

class Z_data : public Y_data {
    Z* z;
public:
    Z_data(int i, char* n, int ph, char* st) : Y_data(i, n) { z = new Z; z->phone = ph; strcpy(z->state, st); }
    ~Z_data() { delete z; }
    void print() { Y_data::print(); std::cout << z->phone << " " << z->state << "\n"; }
};

typedef proc_data* p_type;

class stack {
    p_type* s;
    int     max_len;
    int     top;
public:
    stack(int size) { s = new p_type[size]; max_len = size; top = 0; }
    void reset() { top = 0; }
    void push(p_type& c) { s[top++] = c; }
    p_type pop() { return s[--top]; }
    p_type top_of() { return s[top]; }
    bool empty() { return top == 0; }
    bool full() { return top == (max_len - 1); }
};

int main() {
    proc_data* temp[10];
    stack      st(10);

    temp[0] = new Y_data(24000, "Sue Hawkins");
    temp[1] = new X_data(18, "Ken Hawkins");
    temp[2] = new Z_data(19990, "Igon Hawkins", 5551110, "CA");

    for (int i = 0; i < 3; i++) {
        st.push(temp[i]);
    }

    for (int i = 0; i < 3; i++) {
        st.pop()->print();
    }

    return 0;
}

