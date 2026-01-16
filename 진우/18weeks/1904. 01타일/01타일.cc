#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;   // 타일 길이 입력

    // DP 배열 생성 (0번부터 N번까지 사용)
    vector<int> arr(N + 1);

    // 초기값 설정
    // 길이가 0일 때 경우의 수: 1
    // 길이가 1일 때 경우의 수: 1
    arr[0] = 1;
    arr[1] = 1;

    // 점화식을 이용한 반복문 계산
    // arr[n] = arr[n-1] + arr[n-2]
    // 경우의 수가 커지므로 15746으로 나눈 나머지를 저장
    for (int i = 2; i <= N; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
    }
    
    // N 길이일 때 만들 수 있는 경우의 수 출력
    cout << arr[N] << "\n";

    return 0;
}
