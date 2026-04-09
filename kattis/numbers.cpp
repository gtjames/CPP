/*
FIXME: add program and programmer information, date, etc.

The lab demostrates the use of array and some operations on array.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#include <iostream>
#include <cstdio>
#include <numeric>

// #include "utils.h"
using namespace std;

// https://open.kattis.com/problems/numbers
// Lab 9 - Arrays, Sets, Maps
int menu()
{
	cout << "===== Menu =====\n";
	cout << "1. Read data\n";
	cout << "2. Print max & min\n";
	cout << "3. Print sum\n";
	cout << "4. Sort data\n";
	cout << "5. Print all data\n";
	cout << "6. Delete data\n";
	cout << "7. Exit\n";
	int choice;
	cout << "Enter your choice: ";
	while (true)
	{
		cin >> choice;
		if (choice >= 1 && choice <= 7)
			break;
		cout << "Invalid choice. Enter again: ";
	}
	cin.clear();
	cin.ignore(1000, '\n');
	return choice;
}

// read data from a file and store it in into given nums array.
void read_data(int nums[], int size)
{
    cout << "You've asked to enter " << size << " integers.\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter an integer: ";
        // FIXED3: read each integer from user and store it into nums array
        cin >> nums[i];
    }
}

void print_array(int nums[], int len)
{
    cout << "[ ";
    for (int i = 0; i < len; i++)
        cout << nums[i] << " ";
    cout << "]" << endl;
}

void find_max_min(int nums[], int len, int &max, int &min)
{
    // max = *max_element(nums, nums + len);
    // min = *min_element(nums, nums + len);

    max = nums[0]; // say, max is the first element
    min = nums[0]; // say, min is the first element
    for (int i = 0; i < len; i++)
    {
        if (max < nums[i]) // compare max with each element and update max if necessary
            max = nums[i];

        // FIXED4: compare min with each element and update min
        if (min > nums[i])
            min = nums[i];        
    }
}

// Implements bubble sort
void bubble_sort(int nums[], int len)
{
    int i, j;   //, temp;
    bool sorted = false;
    for (i = 0; i < len; i++)
    {
        sorted = true;
        for (j = 0; j < len - i - 1; j++)
        {
            // if two adjacent numbers are not in order, swap 'em
            if (nums[j] > nums[j + 1])
            {
                // FIXED5: swap the values of nums[j] and nums[j+1]
                swap(nums[j], nums[j + 1]);
                //  can use built-in swap or implement your own swap
                // int temp = nums[j];
                // nums[j] = nums[j + 1];
                // nums[j + 1] = temp;
                sorted = false;
            }
        }
        if (sorted)
            break;
    }
}

int find_sum(int nums[], int len)
{
    int sum = 0;
    // FIXED6: iterate through nums array and add each element to sum
    for (int i = 0; i < len; i++)
        sum += nums[i];
    // accumulate(nums, nums + len, 0);        //  need <numeric> for accumulate function
    return sum;
}

int main(int argc, char *argv[])
{
	size_t size;
	int *nums = nullptr; // pointer to hold the dynamic array
	do
	{
		int choice = menu();
		switch (choice)
		{
		case 1:
			cout << "How many numbers would you like to enter? ";
			cin >> size;
			nums = new int[size];  // declare a dynamic int array of size
			read_data(nums, size); // read the data into nums array
			printf("Done reading %zu data numbers.\n", size);
			break;
		case 2:
			int max, min;
			find_max_min(nums, size, max, min);
			printf("Max = %u\n", max);
			// FIXED1: print Min value
			printf("Min = %u\n", min);
			break;
		case 3:
			printf("Sum = %d\n", find_sum(nums, size));
			break;
		case 4:
			// FIXED2: call bubble_sort to sort the array
			bubble_sort(nums, size);
			cout << "Array sorted successfully.\n";
			break;
		case 5:
			print_array(nums, size); // print the array to check if the values are there
			break;
		case 6:
			delete[] nums; // free the allocated memory
			cout << "Data deleted successfully.\n";
			break;
		case 7:
			cout << "Exiting program...\n";
			return 0;
		}
	} while (true);
	return 0;
}

