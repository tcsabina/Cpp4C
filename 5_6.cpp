#include <iostream>

class mclock {
    unsigned int tot_secs, secs, mins, hours, days;
public:
    mclock(unsigned int i);
    void print();
    void tick();
//    mclock operator ++() { this -> tick(); return *this; }
    friend mclock operator ++(mclock c) { c.tick(); return c; }
};

inline mclock::mclock(unsigned int i) {
    tot_secs = i;
    secs     = tot_secs % 60;
    mins     = (tot_secs / 60) % 60;
    hours    = (tot_secs / 3600) % 24;
    days     = tot_secs / 86400;
}

void mclock::tick() {
    mclock temp = mclock(++tot_secs);

    secs  = temp.secs;
    mins  = temp.mins;
    hours = temp.hours;
    days  = temp.days;
}

void mclock::print() {
    std::cout << days << " d :" << hours << " h :" << mins << " m :" << secs << " s\n";
}

int main() {
    mclock t1(59), t2(172799);

    std::cout << "initial times are\n";
    t1.print();
    t2.print();
    ++t1; ++t2;
    std::cout << "after one second\n";
    t1.print();
    t2.print();

    return 0;
}

