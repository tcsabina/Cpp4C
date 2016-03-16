#include <iostream>
#include <stdlib.h>

enum suit { clubs, diamonds, hearts, spades };

struct card {
    suit s;
    int  pips;
};

const int players = 6;
const int nc      = 5;

card hand[players][nc];

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

void pr_deck(card d[]) {
    for (int i = 0; i < 52; ++i) {
        if (i % 13 == 0)
            std::cout << "\n";

        pr_card(d[i]);
    }

    std::cout << "\n\n";
}

void pr_hand(card hand[][nc]) {
    for (int i = 0; i < players; i++) {
        for (int j = 0; j < nc; j++)
            pr_card(hand[i][j]);

        std::cout << "\n";
    }

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

int main() {
    card deck[52];

    init_deck(deck);
//    pr_deck(deck);
    shuffle(deck);
//    pr_deck(deck);

    int aCard = 0;
    for (int i = 0; i < players; i++) {
        for (int j = 0; j < nc; j++)
            hand[i][j] = deck[aCard++];
    }

    pr_hand(hand);

    return 0;
}

