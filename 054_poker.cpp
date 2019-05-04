//this one got a little long... :)
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

enum rank {
    high_card, one_pair, two_pairs, three_kind, straight, Flush, full_house,
    four_kind, straight_flush, royal_flush
};

class poker_hand {
    vector<int> values;
    vector<char> suits;
    rank the_rank;
    //int highest_val;
public:
    void input_hand(istream &instream) {
        string card;
        values.clear();
        suits.clear();
        for(int i = 0; i<5; i++) {
            instream>>card;
            if(card[0]>='A') {
                switch(card[0]) {
                    case 'T': values.push_back(10); break;
                    case 'J': values.push_back(11); break;
                    case 'Q': values.push_back(12); break;
                    case 'K': values.push_back(13); break;
                    case 'A': values.push_back(14); break;
                }
            }
            else
                values.push_back(card[0]-'0');
            suits.push_back(card[1]);
        }
        assign_rank();
        //highest_val = *max_element(values.begin(), values.end());
    }
    void display_hand() {
        for(int i = 0; i<5; i++) {
            cout<<values[i]<<":"<<suits[i]<<" ";
        }
        cout<<endl;
    }
    void print_rank() {
        string names[] = {"High Card", "One Pair", "Two Pairs",
         "Three of a kind", "Straight", "Flush", "Full House",
         "Four of a kind", "Straight Flush", "Royal Flush"
        };
        cout<<names[the_rank];
    }
    int assign_rank();
    bool is_samesuit();
    bool all_consecutive();
    bool is_royal();
    bool four_of_kind();
    bool three_of_kind();
    bool is_two_pair();
    bool is_one_pair();
    friend int judge(poker_hand, poker_hand);
    int get_rankval();
};

bool poker_hand::is_samesuit() {
    char initial = suits.at(0);
    for(int i = 1; i<5; i++)
        if(suits.at(i)!=initial)
            return false;
    return true;
}

bool poker_hand::all_consecutive() {
    vector<int> sorted_vals = values;
    sort(sorted_vals.begin(), sorted_vals.end());
    for(int i = 1; i<5; i++)
        if(sorted_vals.at(i)-sorted_vals.at(i-1)!=1)
            return false;
    return true;
}

bool poker_hand::is_royal() {
    vector<int> sorted_vals = values;
    sort(sorted_vals.begin(), sorted_vals.end());
    if(sorted_vals.at(0)==10) {
        for(int i = 1; i<5; i++)
            if(sorted_vals.at(i)-sorted_vals.at(i-1)==1)
                return true;
    }
    return false;
}

bool poker_hand::four_of_kind() {
    int counts[13] = {0};
    for(int i = 0; i<5 ; i++) {
        counts[values.at(i)-2]++;   //vals range from 2 to 14 so we subtract 2
    }
    for(int i = 0; i<13; i++) {
        if(counts[i]==4)
            return true;
    }
    return false;
}

bool poker_hand::three_of_kind() {
    int counts[13] = {0};
    for(int i = 0; i<5 ; i++) {
        counts[values.at(i)-2]++;
    }
    for(int i = 0; i<13; i++) {
        if(counts[i]==3)
            return true;
    }
    return false;
}

bool poker_hand::is_two_pair() {
    int counts[13] = {0};
    for(int i = 0; i<5 ; i++) {
        counts[values.at(i)-2]++;
    }
    int pair_count = 0;
    for(int i = 0; i<13; i++) {
        if(counts[i]==2)
            pair_count++;
    }
    if(pair_count == 2)
        return true;
    return false;
}

bool poker_hand::is_one_pair() {    //checks for at least one pair
    int counts[13] = {0};
    for(int i = 0; i<5 ; i++) {
        counts[values.at(i)-2]++;
    }
    for(int i = 0; i<13; i++) {
        if(counts[i]==2)
            return true;
    }
    return false;
}

int poker_hand::assign_rank() {
    if(is_royal()&&is_samesuit()) {
        the_rank = royal_flush;
        return 9;
    }
    if(is_samesuit()&&all_consecutive()) {
        the_rank = straight_flush;
        return 8;
    }
    if(four_of_kind()){
        the_rank = four_kind;
        return 7;
    }
    if(three_of_kind()&&is_one_pair()) {
        the_rank = full_house;
        return 6;
    }
    if(is_samesuit()) {
        the_rank = Flush;
        return 5;
    }
    if(all_consecutive()) {
        the_rank = straight;
        return 4;
    }
    if(three_of_kind()) {
        the_rank = three_kind;
        return 3;
    }
    if(is_two_pair()) {
        the_rank = two_pairs;
        return 2;
    }
    if(is_one_pair()) {
        the_rank = one_pair;
        return 1;
    }
    the_rank = high_card;
    return 0;
}

int poker_hand::get_rankval() {
    switch(the_rank) {
        case 9: return 50;
        case 0:
        case 4:
        case 5:
        case 8: return *max_element(values.begin(), values.end());
        case 6:
        case 1:
        case 3:
        case 7: {
                int maxcount = 0;
                int maxi = 0;
                int counts[13] = {0};
                for(int i = 0; i<5 ; i++) {
                    counts[values.at(i)-2]++;
                }
                for(int i = 0; i<13; i++) {
                    if(counts[i]>maxcount) {
                        maxcount = counts[i];
                        maxi = i;
                    }
                }
                return maxi+2;
                }
        case 2: int counts[13] = {0};
                int val;
                for(int i = 0; i<5 ; i++) {
                    counts[values.at(i)-2]++;
                }
                for(int i = 0; i<13; i++) {
                    if(counts[i]==2) {
                        val = i+2;
                    }
                }
                return val;
    }
}

int judge(poker_hand player1, poker_hand player2) {
    if(player1.the_rank>player2.the_rank)
        return 1;
    if(player2.the_rank>player1.the_rank)
        return 2;
    int p1_rankval = player1.get_rankval();
    int p2_rankval = player2.get_rankval();
    if(p1_rankval>p2_rankval)
        return 1;
    if(p2_rankval>p1_rankval)
        return 2;
    if(player1.the_rank == full_house||player1.the_rank == two_pairs) {
        int counts1[13] = {0};
        int counts2[13] = {0};
        for(int i = 0; i<5 ; i++) {
            counts1[player1.values.at(i)-2]++;
            counts2[player2.values.at(i)-2]++;
        }
        for(int i = 0; i<13; i++) {
            if(counts1[i]==2) {
                p1_rankval = i+2;
                break;
            }
        }
        for(int i = 0; i<13; i++) {
            if(counts2[i]==2) {
                p2_rankval = i+2;
                break;
            }
        }
        if(p1_rankval>p2_rankval)
            return 1;
        if(p2_rankval>p1_rankval)
            return 2;
    }
    vector<int> p1_sortedvals = player1.values;
    vector<int> p2_sortedvals = player2.values;
    sort(p1_sortedvals.begin(), p1_sortedvals.end());
    sort(p2_sortedvals.begin(), p2_sortedvals.end());
    for(int i = 4; i>=0; i--) {
        if(p1_sortedvals[i]>p2_sortedvals[i])
            return 1;
        if(p2_sortedvals[i]>p1_sortedvals[i])
            return 2;
    }
    return 0;
}

int main() {
    ifstream infile("input/p054_poker.txt");
    int p1_count = 0;
    poker_hand p1, p2;
    p1.input_hand(infile);
    p2.input_hand(infile);
    while(!infile.eof()) {
        if(judge(p1, p2)==1)
            p1_count++;
        p1.input_hand(infile);
        p2.input_hand(infile);
    }
    cout<<p1_count;
    infile.close();
    return 0;
}
