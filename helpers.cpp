#include "helpers.h"

bool insertValues(int arr[], int n) {
	if (n <= 0)
		return false;
		
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		if (arr[i] <= 0 || cin.fail())
			return false;
	}

	return true;
}

void printTimeTaken(TIME_POINT start, TIME_POINT end) {
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	
	cout << fixed << time_taken << setprecision(9) << " seconds" << endl;
}
