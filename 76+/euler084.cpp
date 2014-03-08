#include <iostream>
#include <iomanip>
#include <time.h>
#include <algorithm>

using namespace std;

int afterLanding(int sq, int CC[16], int CH[16], int& CC_idx, int& CH_idx)
{
    if (sq == 30) return 10;
    if (sq == 2 || sq == 16 || sq == 33) {
        int card = CC[CC_idx];
        CC_idx = (CC_idx+1)%16;
        return (card == -1 ? sq : card);
    }
    if (sq == 7 || sq == 22 || sq == 36) {
        int card = CH[CH_idx];
        CH_idx = (CH_idx+1)%16;
        if (card == -1) return sq;
        if (card == 40) {
            if (sq == 7) return 15;
            if (sq == 22) return 25;
            return 5;
        }
        if (card == 41) {
            if (sq == 22) return 28;
            return 12;
        }
        if (card == 42) return sq-3;
        return card;
    }
    return sq;
}

int main()
{
    //Cheating by not shuffling and ignoring possible CC3 after CH3
    srand((unsigned)time(0));
    int CC[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 10};
    int CH[] = {-1, -1, -1, -1, -1, -1, 0, 10, 11, 24, 39, 5, 40, 40, 41, 42};
    int CC_idx = 0, CH_idx = 0;
    int freq[40] = {0};
    for (int pos = 0, count = 0; count < 1000000; count++) {
        pos = (pos + rand() % 4 + 1 + rand() % 4 + 1) % 40;
        pos = afterLanding(pos, CC, CH, CC_idx, CH_idx);
        freq[(unsigned)pos]++;
    }
    //3 iteration bubble sort
    int sq[40];
    for (int i = 0; i < 40; i++) sq[i] = i;
    for (int i = 0; i < 3; i++) {
        for (int j = 40-1; j > i; j--) {
            if (freq[j] > freq[j-1]) {
                swap(freq[j], freq[j-1]);
                swap(sq[j], sq[j-1]);
            }
        }
    }
    cout << setfill('0');
    for (int i = 0; i < 3; i++)
        cout << setw(2) << sq[i];
    cout << endl;
}