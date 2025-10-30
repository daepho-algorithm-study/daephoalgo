#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;  // N과 K를 입력받음

	vector<int> arr;  // N의 약수를 저장할 벡터

	// 1부터 N까지 반복하면서 약수 찾기
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {  // i가 N의 약수라면
			arr.push_back(i);  // 약수 벡터에 추가
		}
	}

	// 약수의 개수가 K개 이상이면 K번째 약수를 출력
	if ((int)arr.size() >= K) {
		cout << arr[K - 1] << "\n";
	}
	else {  // 약수의 개수가 K개 미만이면 0 출력
		cout << 0 << "\n";
	}
	
	return 0;
}
