#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(const vector<int>& nums) {
    for (int n : nums) {
        cout << n << " ";
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    vector<int> nums2(5);        // 5 zeros
    vector<int> nums3(5, 10);    // five 10s

    vector<double> grades = {85.5, 92.0, 78.3};

    double sum = 0;

    for (double g : grades) {
        sum += g;
    }

    cout << "Average: " << sum / grades.size();

     vector<int> nums;  // empty vector

    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);

    cout << nums[0]; // 10

    cout << nums.at(0);     // safer (throws error if invalid)

    for (int n : nums) {
        cout << n << " ";
    }

    // nums.size();        // number of elements
    // nums.empty();       // true if empty
    // nums.clear();       // remove all elements
    // nums.pop_back();    // remove last
    // nums.front();       // first element
    // nums.back();        // last element
    
    sort(nums.begin(), nums.end()); // ascending

    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b; // descending
    });
}