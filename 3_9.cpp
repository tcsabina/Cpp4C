#include <iostream>
#include <stdlib.h>

long int random(void);
void srandom(unsigned int seed);
unsigned seed;

enum suit { clubs, diamonds, hearts, spades };

class pips {
    int p;
public:
    void assign(int n) { p = n % 13 + 1; }
    int getpip() { return p; }
    void print();
};

class card {
    int cd;
public:
    suit s;
    pips p;
    void assign(int n) { cd = n; s = (suit)(n / 13); p.assign(n); }
    void pr_card();
};

class deck {
    card d[52];
public:
    void init_deck();
    void shuffle();
    void deal(int, int, card*);
    void pr_deck();
};

void deck::init_deck() {
    for (int i = 0; i < 52; i++)
        d[i].assign(i);
}

void deck::shuffle() {
    for (int i = 0; i < 52; i++) {
        int k = random() % 52;
        card t = d[i];
        d[i] = d[k];
        d[k] = t;
    }
}

void deck::deal(int n, int pos, card* hand) {
    for (int i = pos; i < pos + n; i++) {
        hand[i - pos] = d[i];
    }
}

int main() {
    card one_hand[9];
    deck dk;
    int i, j, k, fcnt = 0, sval[4], ndeal, nc, nhand;

    // these can be input parameters from user
    nc    = 5;
    nhand = 52 / nc;
    ndeal = 10000;
    seed  = 123456;

    srandom(seed);
    dk.init_deck();
    for (k = 0; k < ndeal; k += nhand) {
        if ((nhand + k) > ndeal)
            nhand = ndeal - k;

        dk.shuffle();
        for (i = 0; i < nc * nhand; i += nc) {
            for (j = 0; j < 4; j++)
                sval[j] = 0;

            dk.deal(nc, i, one_hand);
            for (j = 0; j < nc; j++)
                ++sval[one_hand[j].s];

            for (j = 0; j < 4; j++) {
                if (sval[j] >= 5)
                    ++fcnt;
            }
        }
    }

    std::cout << "In " << ndeal << " " << nc << "-card hands there were " << fcnt << " flushes" << std::endl;

    return 0;
}

