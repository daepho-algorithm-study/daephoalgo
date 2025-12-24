#include <iostream>   
#include <vector>     
#include <algorithm>  
#include <cmath> // round 함수 사용

using namespace std;

int main() {
    int N;
    cin >> N;  // 입력되는 수의 개수

    vector<int> arr(N);   // 입력 숫자를 저장할 배열
    int cnt[8001] = { 0 };  // -4000~4000 범위 숫자의 빈도를 저장하는 배열
    long long sum = 0;    // 합계를 저장할 변수

    // 입력과 동시에 합계 및 빈도 계산
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];          // 합계 누적
        cnt[arr[i] + 4000]++;   // 음수는 +4000으로 배열 인덱스 보정
    }

    // 1. 산술평균: sum / N 후 소수 첫째 자리 반올림
    double avg = (double)sum / N;
    cout << (int)round(avg) << "\n";

    // 2. 중앙값: 오름차순 정렬 후 중앙값 출력
    sort(arr.begin(), arr.end());
    cout << arr[N / 2] << "\n";

    // 3. 최빈값 계산: 최대 빈도 찾기
    int mx = 0;  // 최대 빈도 저장
    for (int i = 0; i <= 8000; i++) {   // 배열 전체 순회
        if (cnt[i] > mx) {
            mx = cnt[i];   // 최대 빈도 갱신
        }
    }

    // 최대 빈도에 해당하는 값들을 num 벡터에 저장
    vector<int> num;
    for (int i = 0; i <= 8000; i++) {
        if (cnt[i] == mx) {
            num.push_back(i - 4000);  // 인덱스를 원래 숫자로 변환하여 후보 추가
        }
    }

    // 최빈값 출력: 여러 개면 두 번째로 작은 값, 하나면 그 값
    if (num.size() > 1) cout << num[1] << "\n";
    else cout << num[0] << "\n";

    // 4. 범위: 최대값 - 최소값
    cout << arr[N - 1] - arr[0] << "\n";

    return 0;
}
