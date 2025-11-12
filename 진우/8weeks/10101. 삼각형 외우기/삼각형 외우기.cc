#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int arr[3];

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += arr[i];
	}

	if (sum != 180) {
		cout << "Error" << "\n";
	}
	else if (arr[0] == arr[1] && arr[1] == arr[2]) {
		cout << "Equilateral" << "\n";
	}
	else if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2]) {
		cout << "Isosceles" << "\n";
	}
	else {
		cout << "Scalene" << "\n";
	}

	return 0;
}
