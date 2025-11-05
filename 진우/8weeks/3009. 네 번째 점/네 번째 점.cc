#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int x, y;

	int xp[3];
	int yp[3];
 
	for (int i = 0; i < 3; i++){
		cin >> x >> y;

		xp[i] = x;
		yp[i] = y;
	}

	int x4, y4;

	if (xp[0] == xp[1]) {
		x4 = xp[2];
	}
	else if (xp[0] == xp[2]) {
		x4 = xp[1];
	}
	else {
		x4 = xp[0];
	}

	if (yp[0] == yp[1]) {
		y4 = yp[2];
	}
	else if (yp[0] == yp[2]) {
		y4 = yp[1];
	}
	else {
		y4 = yp[0];
	}

	cout << x4 << " " << y4 << "\n";

	return 0;
}