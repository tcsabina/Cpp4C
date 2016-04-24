#include <iostream>
#include <string.h>

class bnode;

typedef void  (*pfct)(bnode*);
typedef void* p_gen;

int comp(p_gen i, p_gen j);

class bnode {
    friend class bstree;
    bnode* left;
    bnode* right;
    p_gen  data;
    int    count;
    bnode(p_gen d, bnode* l, bnode* r) { data = d; left = l; right = r; count = 1; }
    friend int comp(p_gen a, p_gen b);
    friend void prt(bnode* n);
};

class bstree {
    bnode* root;
public:
    bstree() { root = 0; }
    void insert(p_gen d);
    p_gen find(p_gen d) { return find(root, d); }
    p_gen find(bnode* r, p_gen d);
    void apply(pfct f) { traverse(root, f); }
    void traverse(bnode* r, pfct f);
};

void bstree::insert(p_gen d) {
    bnode* temp = root;
    bnode* old;

    if (root = 0) {
        root = new bnode(d, 0, 0);
        return;
    }

    while (temp != 0) {
        old = temp;
        if (comp(temp->data, 0) == 0) {
            ++temp->count;
            return;
        }

        if (comp(temp->data, d) > 0) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    if (comp(old->data, d) > 0) {
        old->left = new bnode(d, 0, 0);
    }
    else {
        old->right = new bnode(d, 0, 0);
    }
}

p_gen bstree::find(bnode* r, p_gen d) {
    if (r == 0) {
        return 0;
    }
    else
    if (comp(r->data, d) == 0) {
        return r->data;
    }
    else
    if (comp(r->data, d) > 0) {
        return find(r->left, d);
    }
    else {
        return find(r->right, d);
    }
}

void bstree::traverse(bnode* r, pfct f) {
    if (r != 0) {
        traverse(r->left, f);
        (*f)(r);
        traverse(r->right, f);
    }
}

void prt(bnode* n) {
    std::cout << (char*)n->data << "\t";
    std::cout << n->count << "\t";
}

class s_tree : public bstree {
public:
    s_tree();
    void insert(char* d) { bstree::insert(p_gen(d)); }
    char* find(char* d) { return (char*)bstree::find(p_gen(d)); }
    void print() { bstree::apply(prt); }
};

int comp(p_gen i, p_gen j) {
    return strcmp((char*)i, (char*)j);
}

int main() {
    return 0;
}

