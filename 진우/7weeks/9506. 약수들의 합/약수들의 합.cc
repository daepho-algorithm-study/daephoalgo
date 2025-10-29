#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	while (true) {
		cin >> n;  // 정수 n 입력받기

		if (n == -1) {  // 입력이 -1이면 프로그램 종료
			break;
		}
		else {
			vector<int> arr;  // n의 약수를 저장할 벡터

			// 1부터 n까지 반복하면서 약수 찾기
			for (int i = 1; i <= n; i++) {
				if (n % i == 0) {  // i가 n의 약수이면
					arr.push_back(i);  // 벡터에 추가
				}
			}

			int sum = 0;  // 약수의 합을 저장할 변수

			// 마지막 약수(n 자신)는 제외하고 합산
			for (int i = 0; i < (int)arr.size() - 1; i++) {
				sum += arr[i];
			}

			string result = "";  // 결과 문자열

			// 완전수(perfect number) 판별
			// 완전수란 '자기 자신을 제외한 약수의 합 == 자기 자신'인 수
			if (n == sum) {
				result += to_string(n);  // 예: "6"
				result += " = ";          // 예: "6 = "

				// 약수들을 " + "로 연결하여 출력 문자열 구성
				for (int i = 0; i < (int)arr.size() - 1; i++) {
					result += to_string(arr[i]);  // 예: "1", "2", "3"
					if (i < (int)arr.size() - 2) {  // 마지막 약수 전까지만 "+” 추가
						result += " + ";
					}
				}
			}
			else {
				// 완전수가 아닐 경우 메시지 출력
				result += to_string(n);
				result += " is NOT perfect.";
			}

			cout << result << "\n";  // 결과 출력
		}
	}

	return 0;
}
