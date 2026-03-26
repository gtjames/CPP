#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int *numbers;
    int count;

    cin >> count;
    numbers = new int[count];
        // int arr[n];
        for (int i = 0; i < count; i++) {
            cin >> numbers[i];
    }

    // Sort the array
    sort(numbers, numbers + count);
 
    // Sum odd and even positions
    int oddSum = 0, evenSum = 0;
    
    for (int i = 0; i < count; i++) {
        if (i % 2 == 0) {
            evenSum += numbers[i];
        } else {
            oddSum += numbers[i];
        }
    }
    
    cout << endl;
    cout << oddSum << " " << evenSum << endl;
    
    return 0;
}
