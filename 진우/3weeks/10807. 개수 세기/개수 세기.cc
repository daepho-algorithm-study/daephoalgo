#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort 사용
using namespace std;

int main() {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
        cin >> arr[i];
        }

        int v;
        cin >> v;
        
        int result = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] == v) {
                result += 1;
            }
        }
        cout << result << endl;
  }

