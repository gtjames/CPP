#include <cmath>
#include <iostream>
using namespace std;

void printArr(int * arr, int len) {
    for (int *it = arr; it !=(arr + len); ++it) {
        int x = *it;
        cout << x << " ";
    }
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int len = 4;

    for (int *it = &nums[0]; it !=(nums + len); ++it) {
        int x = *it;
        cout << x << " ";
    }


    for (auto it = begin(nums); it != end(nums); ++it) {
        int x = *it;
        cout << x << " ";
    }

    for (int x : nums)
        cout << x << " ";
    
    printArr(nums);
}
