#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> num(31, 0);
        vector<int> arr(28);
        for (int idx = 0; idx < 28; idx++) {
        cin >> arr[idx];
        num[arr[idx]] = 1;
        }

        for (int i = 1; i < (int)num.size(); i++) {
            if (num[i] == 0) {
                cout << i << endl;
            }
        }

        return 0;
  }

