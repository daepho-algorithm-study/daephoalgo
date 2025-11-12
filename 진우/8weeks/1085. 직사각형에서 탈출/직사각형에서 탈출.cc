#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	
	int left = x;
	int right = w - x;
	int bottom = y;
	int top = h - y;

	int mn = min({ left, right, bottom, top });

	cout << mn << "\n";

	
}