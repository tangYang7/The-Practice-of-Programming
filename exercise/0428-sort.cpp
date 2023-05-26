#include <iostream>
#include <algorithm>
using namespace std;

class Card {
    friend ostream & operator << (ostream &os, const Card &rhs);
    friend bool operator < (const Card &lhs, const Card &rhs);
public:
    void Set(char s, char d);
private:
    char suit_ = ' ', digit_ = ' ';
    int num_ = 0;
};
// ------------------------------------------------------------------
void Card::Set(char s, char d) {
    // TODO
    suit_ = s;
    digit_ = d;
    num_ = 14;
    switch (suit_) {
    case 'H':   num_ *= 4;  break;
    case 'S':   num_ *= 3;  break;
    case 'D':   num_ *= 2;  break;
    case 'C':   num_ *= 1;  break;
    default:                break;
    }

    switch (digit_) {
    case 'A':   num_ += 14; break;
    case 'K':   num_ += 13; break;
    case 'Q':   num_ += 12; break;
    case 'J':   num_ += 11; break;
    case 'T':   num_ += 10; break;
    case '1'...'9':
        num_ += digit_ - '0';break;
    default:    break;
    }
}
// ------------------------------------------------------------------
bool operator < (const Card &lhs, const Card &rhs) {
    // TODO
    return lhs.num_ < rhs.num_;
}
// ------------------------------------------------------------------
ostream & operator << (ostream &os, const Card &card) {
    os << card.suit_ << card.digit_;
    return os;
}
// ------------------------------------------------------------------
int main() {
    char start = ' ';
    while (cin >> start && start!='#') {
        constexpr char position[] = "NESW";
        constexpr size_t NumPeople = sizeof(position)-1;

        // determine the first player to get cards
        int j = 0;
        for (size_t i=0; i<NumPeople; i+=1) {
            if (position[i]==start) {
                j = (i+1)%NumPeople;
                break;
            }
        }

        // read in and distribute cards
        constexpr size_t NumCards = 13;
        Card cards[NumPeople][NumCards];
        for (size_t i=0; i<NumPeople*NumCards; i+=1) {
            char s, n;
            cin >> s >> n;
            cards[j][i/NumPeople].Set(s, n);
            j = (j+1)%NumPeople;
        }

        // sort cards of every player
        for (size_t i=0; i<NumPeople; i+=1) {
            sort(cards[i], end(cards[i]));
        }

        // find the first player to display
        for (size_t i=0; i<NumPeople; i+=1) {
            if (position[i]=='S') {
                j = i;
                break;
            }
        }

        // display cards of every player
        for (size_t t=0; t<NumPeople; t+=1, j=(j+1)%NumPeople) {
            cout << position[j] << ':';
            for (size_t i=0; i<NumCards; i+=1) {
                cout << ' ' << cards[j][i];
            }
            cout << endl;
        }
    }
}
/*
N
CQDTC4D8S7HTDAH7D2S3D6C6S6D9S4SAD7H2CKH5D3CTS8C9H3C3
DQS9SQDJH8HAS2SKD4H4S5C7SJC8DKC5C2CAHQCJSTH6HKH9D5HJ
S
CQDTC4D8S7HTDAH7D2S3D6C6S6D9S4SAD7H2CKH5D3CTS8C9H3C3
DQS9SQDJH8HAS2SKD4H4S5C7SJC8DKC5C2CAHQCJSTH6HKH9D5HJ
#
*/