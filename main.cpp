#include <iostream>
#include <functional>
#include "helpers.h"
#include "Stack.h"

void searchSumIterative(int* arr, int n, int x) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] + arr[j] == x)
				cout << arr[i] << " " << arr[j] << endl;
}

void searchSumRecursive(int* arr, int n, int x, int y) {
	if (n == 1) {
		if (y != 0 && x == arr[0] + y)
			cout << arr[0] << " " << y << endl;

		return;
	}

	if (y != 0) {
		if (x == arr[n - 1] + y)
			cout << arr[n-1] << " " << y << endl;

		searchSumRecursive(arr, n - 1, x, y);
	}

	else {
		searchSumRecursive(arr, n - 1, x, arr[n - 1]);
		searchSumRecursive(arr, n - 1, x, 0);
	}

}

void searchSumRecStack(int* arr, int n, int x) {
	Stack st;
	Item current, next;

	current = { n, 0 };
	st.push(current);

	while (!st.isEmpty()) {
		current = st.pop();

		if (current.n == 1) {
			if (current.y != 0 && x == arr[0] + current.y)
				cout << arr[0] << " " << current.y << endl;

			continue;
		}

		if (current.y != 0) {
			if (x == arr[current.n - 1] + current.y)
				cout << arr[current.n - 1] << " " << current.y << endl;
			
			st.push({ current.n - 1, current.y });
		}

		else {
			st.push({ current.n - 1, 0 });
			st.push({ current.n - 1, arr[current.n - 1] });
		}
	}
}

void measureTimes(int* arr, int n, int x) {
	// unsync the I/O of C and C++ - for potentially faster execution.
	ios_base::sync_with_stdio(false);

	// Iterative
	cout << "Iterative algorithm:" << endl;
	auto start = CLOCK::now();
	searchSumIterative(arr, n, x);
	auto end = CLOCK::now();
	printTimeTaken(start, end);
	
	// Recursive
	cout << "Recursive algorithm (recursive version):" << endl;
	start = CLOCK::now();
	searchSumRecursive(arr, n, x, 0);
	end = CLOCK::now();
	printTimeTaken(start, end);

	// Iterative implenetation of recursive algorithm
	cout << "Recursive algorithm (iterative version):" << endl;
	start = CLOCK::now();
	searchSumRecStack(arr, n, x);
	end = CLOCK::now();
	printTimeTaken(start, end);	
}

int main() {
	int x, n;

	cin >> n;

	int* arr = new int[n + 1];
	bool is_valid = insertValues(arr, n);

	cin >> x;

	if (!is_valid) {
		cout << "Wrong Input" << endl;
		return 0;
	}

	measureTimes(arr, n, x);

	delete[] arr;
	return 0;
}
