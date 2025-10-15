#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string word;
	cin >> word;

	string re_word = word;
	reverse(re_word.begin(), re_word.end());
	
	if (word == re_word) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	
}