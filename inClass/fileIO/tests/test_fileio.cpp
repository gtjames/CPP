#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest/doctest.h" // FIXME: adjust the path as needed
#include "../src/fileio.hpp"

TEST_CASE("Testing read_data function")
{
    SUBCASE("Sub Case 1: Valid file with numbers")
    {
        // assume data/sample_input.txt exists with 7 test data
        int *numbers = new int[1000];                // assuming we will read at most 1000 numbers from the file
        string input_file = "data/sample_input.txt"; // make sure this file exists with test data
        size_t arr_len = read_data(numbers, input_file);
        CHECK(arr_len == 7);      // assuming sample_input.txt has 7 numbers
        CHECK(numbers[0] == 100); // adjust expected values as per your input test file
        CHECK(numbers[1] == 10);
        CHECK(numbers[arr_len - 1] == 99);
        delete[] numbers;
    }
    // FIXME7: Write 2nd test case for read_data function
}

TEST_CASE("Testing find_min function")
{
    SUBCASE("Sub Case 1: Distinct values")
    {
        int numbers[] = {5, 3, 8, 1, 4};
        int expected = 1;
        int result = find_min(numbers, 5);
        CHECK(result == expected);
    }
    // FIXME8: Write 2nd test case for find_min function
}

TEST_CASE("Testing find_range function")
{
    SUBCASE("Sub Case 1: Distinct values")
    {
        int *numbers = new int[5]{5, 3, 8, 1, 4};
        int expected = 7; // 8 - 1
        int result = find_range(numbers, 5);
        CHECK(result == expected);
        delete[] numbers;
    }
    // FIXME9: Write 2nd test case for find_range function
}

TEST_CASE("Testing find_mean function")
{
    SUBCASE("Sub Case 1: Distinct values")
    {
        int numbers[] = {5, 3, 8, 1, 4};
        float expected = 4.2f; // (5+3+8+1+4)/5
        float result = find_mean(numbers, 5);
        CHECK(fabs(result - expected) <= EPSILON);
    }
    // FIXME10: Write 2nd test case for find_mean function
}

TEST_CASE("Testing find_median function")
{
    SUBCASE("Sub Case 1: Odd number of elements")
    {
        int numbers[] = {5, 3, 8, 1, 4};
        float expected = 4.0f; // sorted: {1,3,4,5,8}
        float result = find_median(numbers, 5);
        CHECK(fabs(result - expected) <= EPSILON);
    }
    // FIXME11: Write 2nd test case for find_median function
}