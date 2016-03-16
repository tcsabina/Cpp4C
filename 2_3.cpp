#include <iostream>
#include <stdlib.h>

enum suit { clubs, diamonds, hearts, spades };

struct card {
    suit s;
    int  pips;
};

void pr_card(card cd) {
    switch (cd.pips) {
        case 1:  std::cout << "A"; break;
        case 11: std::cout << "J"; break;
        case 12: std::cout << "Q"; break;
        case 13: std::cout << "K"; break;
        default: std::cout << cd.pips; break;
    }

    switch (cd.s) {
        case clubs   : std::cout << "C"; break;
        case diamonds: std::cout << "D"; break;
        case hearts  : std::cout << "H"; break;
        case spades  : std::cout << "S"; break;
        default      : std::cout << "suit error\n"; exit(1);
    }

    std::cout << "  ";
}

void init_deck(card d[]) {
    for (int i = 0; i < 52; ++i) {
        d[i].s    = (suit)(i/13);
        d[i].pips = 1 + i % 13;
    }
}

void shuffle(card d[]) {
    for (int i = 0; i < 52; ++i) {
        int k  = random() % 52;
        card t = d[i];
        d[i]   = d[k];
        d[k]   = t;
    }
}

void pr_deck(card d[]) {
    for (int i = 0; i < 52; ++i) {
        if (i % 13 == 0)
            std::cout << "\n";

        pr_card(d[i]);
    }

    std::cout << "\n\n";
}

int main() {
    card deck[52];

    init_deck(deck);
    pr_deck(deck);
    shuffle(deck);
    pr_deck(deck);

    return 0;
}

