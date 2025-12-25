#include <iostream>   // 표준 입출력 사용
#include <vector>     // vector 컨테이너 사용
#include <algorithm>  // sort 함수 사용

using namespace std;

int main() {
    int N;
    cin >> N;  // 약수(또는 수)의 개수 입력

    vector<int> num(N);  // N개의 정수를 저장할 벡터
    for (int i = 0; i < N; i++) {
        cin >> num[i];   // 수 입력
    }

    // 오름차순 정렬
    sort(num.begin(), num.end());

    int result;
    // N이 짝수인 경우
    if (N % 2 == 0) 
        result = num[0] * num[N - 1]; 
        // 1과 N이 아닌 수들만 주어졌으므로
        // 가장 작은 값 × 가장 큰 값

    // N이 홀수인 경우
    else 
        result = num[N / 2] * num[N / 2]; 
        // 완전 제곱 수
        // 가운데 값 × 가운데 값 (제곱)

    cout << result << "\n";  // 결과 출력

    return 0;
}
