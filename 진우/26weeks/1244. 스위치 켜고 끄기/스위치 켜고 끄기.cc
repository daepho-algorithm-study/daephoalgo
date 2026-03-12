#include <iostream>
#include <cmath>  // abs() 함수 사용
using namespace std;

int arr[101];  // 스위치 상태를 저장하는 배열 (1번부터 사용)

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);                  

    int N;  // 스위치 개수
    cin >> N;

    // 스위치 초기 상태 입력 (0: 꺼짐, 1: 켜짐)
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    int M;  // 학생 수
    cin >> M;

    // 학생별 스위치 조작 처리
    for (int i = 0; i < M; i++) {
        int x, num;
        cin >> x >> num;  // x: 성별 (1=남, 2=여), num: 학생이 받은 번호

        if (x == 1) {  // 남학생
            // 남학생은 자신의 번호 배수 스위치를 모두 뒤집음
            for (int j = num; j <= N; j += num) {
                arr[j] = abs(arr[j] - 1);  // 0 ↔ 1 토글
            }
        }
        else {  // 여학생
            int left = num;   // 좌측 범위
            int right = num;  // 우측 범위

            // 중심 스위치 기준 좌우 대칭으로 같은 값이면 범위 확장
            while (left - 1 >= 1 && right + 1 <= N) {  // 배열 범위 체크
                if (arr[left - 1] == arr[right + 1]) { // 좌우 값이 같으면
                    left--;   // 왼쪽 확장
                    right++;  // 오른쪽 확장
                }
                else {
                    break;    // 대칭 깨지면 확장 종료
                }
            }

            // 좌우 확장 범위 스위치 뒤집기
            for (int k = left; k <= right; k++) {
                arr[k] = abs(arr[k] - 1);  // 0 ↔ 1 토글
            }
        }
    }

    // 결과 출력 (한 줄에 20개씩 출력)
    for (int i = 1; i <= N; i++) {
        cout << arr[i] << " ";
        
        if (i % 20 == 0) {
            cout << '\n';  // 20개마다 줄바꿈
        }
    }

    return 0;
}