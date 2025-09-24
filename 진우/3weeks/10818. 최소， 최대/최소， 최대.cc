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
        
        // 벡터 전체에서 최소/최대 찾기
        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());

        cout << minVal << " " << maxVal << endl;

        return 0;
  }

