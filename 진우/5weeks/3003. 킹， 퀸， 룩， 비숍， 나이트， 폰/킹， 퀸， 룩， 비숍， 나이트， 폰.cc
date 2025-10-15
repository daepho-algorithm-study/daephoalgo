#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<int> chess(6);
	for (int i = 0; i < 6; i++) {
		cin >> chess[i];
	}

	int king = chess[0];
	int queen = chess[1];
	int rook = chess[2];
	int bishop = chess[3];
	int knight = chess[4];
	int pone = chess[5];

	vector<int> num(6, 0);
	if (king != 1) {
		num[0] = (1 - king);
	}
	if (queen != 1) {
		num[1] = (1 - queen);
	}
	if (rook != 2) {
		num[2] = (2 - rook);
	}
	if (bishop != 2) {
		num[3] = (2 - bishop);
	}
	if (knight != 2) {
		num[4] = (2 - knight);
	}
	if (pone != 8) {
		num[5] = (8 - pone);
	}

	for (int i = 0; i < (int)num.size(); i++) {
		cout << num[i] << " ";
	}

	return 0;
}

