#include <iostream>     // 표준 입출력 사용
#include <vector>       // 동적 배열(vector) 사용
#include <algorithm>    // sort() 함수 사용

using namespace std;

int main() {
	vector<int> arr;    // 입력받은 정수를 저장할 벡터

	int n;
	// EOF(입력 종료) 전까지 반복해서 정수 입력 받기
	// Windows에서는 Ctrl+Z, mac/Linux에서는 Ctrl+D로 종료
	while (cin >> n) {
		arr.push_back(n);   // 입력받은 정수를 벡터에 추가
	}

	int len = arr.size();   // 입력된 데이터 개수 저장

	// 입력이 1개 이상일 때만 정렬 수행
	if (len > 0) {
		sort(arr.begin(), arr.end());   // 오름차순 정렬
	}

	int sum = 0;   // 합계를 저장할 변수
	for (int i = 0; i < len; i++) {
		sum += arr[i];      // 모든 원소의 합 구하기
	}

	int avg = sum / len;    // 평균 계산 (정수 나눗셈 → 소수점 버려짐)

	// 평균값 출력
	cout << avg << "\n";

	// 중앙값 출력 (정렬되어 있으므로 중간 인덱스의 값)
	cout << arr[len / 2] << "\n";

	return 0;   // 프로그램 종료
}
