// pass by value demo
#include <iostream>
using namespace std;

int main() {
    //  size is determined by the number of elements in the initializer list
    char   letters[]  = {'a', 'b', 'c', 'd', 'e'};
    //  or we create the array with size and init the values individually
    string letters2[5];
    letters2[0] = letters[4];
    letters2[1] = "b";
    letters2[2] = "c";
    letters2[3] = "d";
    letters2[4] = "e";

    //  strings can be treated like arrays
    string strLtrs = "ABCDE";
    strLtrs[0] = 'X';
    cout << "strLtrs: " << strLtrs << endl;
    cout << "strLtrs[0]: " << strLtrs[0] << endl;

    //  arrays do not know their own size
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(int);
    cout << "size of arr: " << size << endl;

    //  using array nameby itself is just to use the array address in memory
    int * pArr = arr;
    cout << "Adrs arr:  " << &arr[0] << endl;
    cout << "Adrs pArr: " << pArr << endl;
    //  this is the same as arr[0] = 100;
    *pArr = 100;
    //  this is the same as arr[1] = 200;
    *(pArr+1) = 200;
    
    cout << "arr[1]: " << arr[1] << endl;
    cout << "Adrs pArr+1: " << pArr << endl;
    for(int i=0; i<size; i++)
        cout << *(pArr+i) << " " << pArr[i] << endl;

    float grades[] = {90.5f, 34.5f, 56, 81.f, 99.f, 100, 89.9};
    // size_t is an unsigned integral type, which is the result of the sizeof operator and is used to represent sizes and counts.
    size_t arr_size = sizeof(grades)/sizeof(float);
    cout << "Address of grades:    " << grades << endl;
    cout << "Address of grades:    " << grades+1 << endl;
    cout << "Address of grades:    " << grades+2 << endl;
    *(grades+1) = 111.1f;

    cout << "Address of grades[0]: " << &grades[0] << endl;
    cout << "Address of grades[1]: " << &grades[1] << " " << grades[1] <<endl;
    cout << "size of grades: " << sizeof(grades) << " bytes" << endl;
    cout << "number of elements in grades: " << arr_size << endl;
 
  return 0;
}