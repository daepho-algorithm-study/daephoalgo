#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int x, y;
	
	vector<int> x_point;
	vector<int> y_point;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;

		x_point.push_back(x);
		y_point.push_back(y);
	}

	int row = 0;
	int col = 0;

	if (n >= 2) {
		row = *max_element(x_point.begin(), x_point.end()) - *min_element(x_point.begin(), x_point.end());
		col = *max_element(y_point.begin(), y_point.end()) - *min_element(y_point.begin(), y_point.end());
	}

	int result = row * col;

	cout << result << "\n";

	return 0;
}