#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort 사용
using namespace std;

int main() {
        vector<int> arr(9);
        for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        }
        
        // 벡터 전체에서 최소/최대 찾기
        int mx = *max_element(arr.begin(), arr.end());

        for (int j = 0; j < (int)arr.size(); j++) {
            if (arr[j] == mx) {
                cout << mx << endl;
                cout << j + 1 << endl;
                break;
            }
        }
        return 0;
  }

