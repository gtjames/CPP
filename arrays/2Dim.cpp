#include <iostream>
#include <numeric>
#include <functional>
#include <numeric>

#include <algorithm>
#include <ranges>
#include <iomanip>

using namespace std;

int main() {
    int grid[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }

    //  2 rows 3 cols
   int nums[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int sum = 0;

    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            sum += nums[row][col];
        }
    }
    cout << "Sum: " << sum << endl;

    //  each row is an array. so we can sum them with accumulate
    sum = accumulate(begin(nums[0]), end(nums[0]), 0);
    sum = accumulate(begin(nums[1]), end(nums[1]), sum);
    cout << "Sum: " << sum << endl;

    //  dynamically create a 2D array
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // create array of pointers (each row)
    int** arr = new int*[rows];

    // allocate each row
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    // fill array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j + 1;  // example values
        }
    }

    // print array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(2) << arr[i][j] << " ";
        }
        cout << endl;
    }

    // free memory
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}