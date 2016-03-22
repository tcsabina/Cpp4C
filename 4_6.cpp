#include <iostream>

struct listelem {
    char      data;
    listelem* next;
};

class list {
    listelem* h;
public:
    list() { h = 0; }
    ~list() { release(); }

    void add(char c);
    void del() { listelem* temp = h; h = h->next; delete temp; }
    listelem* first() { return h; }
    void print();
    void release();
};

void list::add(char c) {
    listelem* temp = new listelem;

    temp->next = h;
    temp->data = c;
    h          = temp;
}

void list::print() {
    listelem* temp = h;

    while (temp != 0) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }

    std::cout << "\n";
}

void list::release() {
    while (h != 0)
        del();
}

int main() {
    list* p;
    {
        list w;

        w.add('A');
        w.add('B');
        w.print();
        w.del();
        w.print();
        p = &w;
        p->print();
    }

    return 0;
}

