#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort 사용
using namespace std;

int main() {
        int N, X;
        cin >> N >> X;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
        cin >> A[i];
        }
        
        vector<int> result;
        for (int i = 0; i < N; i++) {
            if (A[i] < X) {
                result.push_back(A[i]);
            }
        }

        for (int j = 0; j < (int)result.size(); j++) {
            cout << result[j];
            if (j != result.size() - 1) cout << " ";
        }
  }

