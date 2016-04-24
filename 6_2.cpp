class b {
public:
    int f;
    int g;
};

class d : private b {
protected:
    int b::g;
public:
    int b::f;
};

int main() {
    return 0;
}

