#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;  // 소인수분해할 정수 입력

	vector<int> arr;  // 소인수를 저장할 벡터

	int x = 2;  // 가장 작은 소수 2부터 시작
	while (N > 1) {  // N이 1이 될 때까지 반복
		if (N % x == 0) {   // x가 N의 약수(=소인수)라면
			arr.push_back(x); // 소인수 목록에 추가
			N = N / x;        // N을 x로 나누어 갱신
			x = 2;            // 다시 2부터 검사 (가장 작은 소수부터 재검사)
		}
		else {
			x++;  // x를 1 증가시켜 다음 수 검사
		}
	}

	// 저장된 모든 소인수를 출력 (오름차순)
	for (int i = 0; i < (int)arr.size(); i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}
