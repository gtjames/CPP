#pragma once
#include <vector>
#include <string>
using namespace std;

const float EPSILON = 1e-4; // accuracy upto 4 decimal points

// function prototypes
int read_data(int *, const string);
int find_max(const int *, size_t);
int find_min(const int *, size_t);
float find_mean(const int *, size_t); // average
int find_range(const int *, size_t);
float find_median(int *, size_t);
// bonus implement findMode function
int find_mode(const int *, size_t);
void write_data(const int *, size_t);