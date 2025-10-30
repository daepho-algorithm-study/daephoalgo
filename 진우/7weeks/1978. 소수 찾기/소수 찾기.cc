#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;  
    // 입력: 검사할 수의 개수 N을 입력받음

    vector<int> arr(N);  
    // N개의 정수를 저장할 벡터 생성

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    // N개의 정수를 벡터 arr에 입력받음

    int result = 0;  
    // 소수의 개수를 저장할 변수

    for (int i = 0; i < N; i++) {  
        int cnt = 0;  
        // 현재 숫자의 약수 개수를 세기 위한 변수 초기화

        for (int j = 1; j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                cnt += 1;  
                // j가 arr[i]의 약수라면 카운트 증가
            }
        }

        if (cnt == 2) {
            result += 1;  
            // 약수가 1과 자기 자신 두 개뿐이면 소수이므로 개수 증가
        }
    }

    cout << result << "\n";  
    // 최종적으로 입력된 숫자 중 소수의 개수 출력

    return 0;
}
