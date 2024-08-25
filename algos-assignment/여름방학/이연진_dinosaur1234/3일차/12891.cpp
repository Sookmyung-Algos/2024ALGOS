#include <iostream>
#include <vector>
using namespace std;

int main() {
    int S, P;
    string DNA;
    int A, C, G, T;
    vector<int> v(4, 0);
    int possible_dna = 0;
    
    cin >> S >> P;
    cin >> DNA;
    cin >> A >> C >> G >> T;

    for (int i = 0; i < P; i++) {
        if (DNA[i] == 'A') 
            v[0]++;
        if (DNA[i] == 'C') 
            v[1]++;
        if (DNA[i] == 'G') 
            v[2]++;
        if (DNA[i] == 'T') 
            v[3]++;
    }

    if (v[0] >= A && v[1] >= C && v[2] >= G && v[3] >= T) {
        possible_dna++;
    }

    for (int i = P; i < S; i++) {
        if (DNA[i - P] == 'A') 
            v[0]--;
        if (DNA[i - P] == 'C') 
            v[1]--;
        if (DNA[i - P] == 'G') 
            v[2]--;
        if (DNA[i - P] == 'T') 
            v[3]--;

        if (DNA[i] == 'A') 
            v[0]++;
        if (DNA[i] == 'C') 
            v[1]++;
        if (DNA[i] == 'G') 
            v[2]++;
        if (DNA[i] == 'T') 
            v[3]++;

        if (v[0] >= A && v[1] >= C && v[2] >= G && v[3] >= T) {
            possible_dna++;
        }
    }

    cout << possible_dna << '\n';

    return 0;
}
