#include <iostream>  // 입출력 관련 라이브러리 포함

using namespace std;

int CY = 100;  // CY(창영)의 초기 체력 100
int SD = 100;  // SD(상덕)의 초기 체력 100

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);                

    int N;         // 라운드 수 입력 받을 변수
    cin >> N;      // N 입력

    for (int i = 0; i < N; i++) {  // N번 반복 (각 라운드)
        int x, y;                  // 각 라운드에서 CY와 SD가 낸 숫자
        cin >> x >> y;             // x = CY, y = SD 입력

        if (x > y) {               // CY가 SD보다 크면
            SD -= x;               // SD 체력 감소 (CY 숫자만큼)
        }
        else if (x < y) {          // CY가 SD보다 작으면
            CY -= y;               // CY 체력 감소 (SD 숫자만큼)
        }
        else {                     // x == y인 경우 (비김)
            continue;              // 아무 일도 일어나지 않음
        }
    }

    cout << CY << "\n";  // 최종 CY 체력 출력
    cout << SD << "\n";  // 최종 SD 체력 출력

    return 0;             
}