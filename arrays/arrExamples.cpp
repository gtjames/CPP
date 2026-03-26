#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <ranges>

using namespace std;

//  helper function to use with XXX_if statements
bool isOdd(int x) { return x % 2 != 0; }

int main() {
    // Example 1: sort - Sort array in ascending order
    int arr1[] = {5, 2, 8, 1, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    //  sort with a for loop
    for (int i = 0; i < size1 - 1; i++) {
        for (int j = 0; j < size1 - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                // swap
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            } 
        }
    }
    // which would you rather use?? 
    int arr1a[] = {5, 2, 8, 1, 9};
    sort(arr1a, arr1a + size1);
    cout << "Sorted (ascending):  ";
    for (int x : arr1a) cout << x << " ";
    cout << "\n";

    // Example 2: sort - Sort in descending order
    int arr2[] = {5, 2, 8, 1, 9};
    sort(arr2, arr2 + 5, greater<int>());
    cout << "Sorted (descending): ";
    for (int x : arr2) cout << x << " ";
    cout << "\n\n";

    // Example 3: reverse - Reverse array
    int arr3[] = {1, 2, 3, 4, 5};
    cout << "Original: ";
    for (int x : arr3) cout << x << " ";
    cout << "\n";
    reverse(arr3, arr3 + 5);
    cout << "Reversed: ";
    for (int x : arr3) cout << x << " ";
    cout << "\n\n";

    // Example 4: find - Find element
    int arr4[] = {10, 20, 30, 40, 50};
    int* found = find(arr4, arr4 + 5, 30);
    cout << "Found " << *found << " at index: " << (found - arr4) << "\n";

    // Example 4a: find - Find If element
    int* found_if = find_if(arr4, arr4 + 5, [](int x) { return x > 30; });
    cout << "First element > 30         : " << *found_if << " at index: " << (found_if - arr4) << "\n";
    cout << "Values are memory addresses: " << found_if << " " << arr4 << "\n\n";

    // Example 5: count - Count occurrences
    int arr5[] = {1, 2, 2, 3, 2, 4};
    int cnt = count(begin(arr5), end(arr5), 2);
    cout << "Count of 2s: " << cnt << "\n";

    // Example 5a: count - Count occurrences of even numbers
    cnt = count_if(begin(arr5), end(arr5), [](int x) {
        return x % 2 == 0;
    });
    cout << "Count if even numbers: " << cnt << endl;

    cnt = count_if(begin(arr5), end(arr5), isOdd);
    cout << "Count if odd numbers : " << cnt << endl << endl;

    // Example 6: accumulate - Sum all elements
    int arr6[] = {1, 2, 3, 4, 5};
    int sum = accumulate(begin(arr6), end(arr6), 0);
    cout << "Sum of arr5     : " << sum << "\n";
    sum = accumulate(begin(arr5), end(arr5), sum);
    cout << "Sum of arr5/6   : " << sum << "\n\n";

    // Example 7: transform - Apply function to each element
    int arr7[] = {1, 2, 3, 4, 5};
    int result[5];
    transform(begin(arr7), end(arr7), result, [](int x) { return x * 2; });
    cout << "Transformed (x2): ";
    for (int x : result) cout << x << " ";
    cout << "\n\n";

    // Example 8: fill - Fill array with value
    int arr8[5];
    fill(begin(arr8), end(arr8), 7);
    cout << "Filled with 7: ";
    for (int x : arr8) cout << x << " ";
    cout << "\n\n";

    // Example 9: min_element / max_element
    int arr9[] = {3, 1, 9, 2, 5};
    cout << "Min: " << *min_element(begin(arr9), end(arr9)) << "\n";
    cout << "Max: " << *max_element(begin(arr9), end(arr9)) << "\n\n";

    string arrAlpha[] = {"apple", "banana", "cherry", "date", "elderberry"};
    cout << "Max Alpha: " << *max_element(arrAlpha, arrAlpha + 5) << "\n";
    cout << "Min Alpha: " << *min_element(arrAlpha, arrAlpha + 5) << "\n\n";

    // Example 10: modify each element using for_each
    cout << "Use for_each to transform and print an array\n";
    int arr10[] = {3, 1, 9, 2, 5};
    for_each(begin(arr10), end(arr10), [](int& x) {
        x *= 2;   // modify each element
        cout << x << " ";
    });
    cout << "\n\n";

    string names[5] = { "CMU", "Mavericks", "Grand", "Junction", "Colorado"};
    string * pNames = names;
    cout << pNames[1] << endl;
    cout << *pNames << endl;

    return 0;
}