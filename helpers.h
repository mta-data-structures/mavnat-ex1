#pragma once
#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std;

typedef chrono::system_clock::time_point TIME_POINT;
typedef chrono::high_resolution_clock CLOCK;

struct Item {
	int n;
	int y;
};

void printTimeTaken(TIME_POINT, TIME_POINT);
bool insertValues(int arr[], int n);