/*
Algorithm:
1. Read integers until EOF.
2. Compute the modulo 42 of each integer and store in a set.
3. Output the size of the set (number of distinct remainders).
*/
#include <iostream>
#include <set>
#include <map>

#include <numeric>
#include <functional>
#include <ranges>

using namespace std;

//  https://open.kattis.com/problems/modulo
//  Lab 9 - Arrays, Sets, Maps
int main() {
    set <int> mods;
    map <int, int> freq;
    int num;

    while (cin >> num) {
        mods.insert(num % 42);
        freq[num % 42]++;
    }

    for(int i : mods) cout << i << " ";
    cout << endl;
    for_each (begin(freq), end(freq), [](const pair<int, int>& pair) {
        cout << pair.first << ": " << pair.second << endl;
    });
    
    cout << mods.size() << endl;
}