#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;  
    cin >> N;  // N번째로 등장하는 "666"이 포함된 수를 찾기 위해 입력받음

    int cnt = 0;  // 지금까지 발견한 "666" 시리즈의 개수
    int num = 666;  // 첫 번째 "666" 시리즈 숫자부터 시작

    while (true) {
        string s = to_string(num);  // 숫자를 문자열로 변환하여 "666" 포함 여부를 확인하기 위해 변환

        // 문자열 안에 "666"이 포함되어 있다면 (string::npos는 "못 찾았다"는 뜻)
        if (s.find("666") != string::npos) {
            cnt++;  // 666 시리즈 발견 시 개수 증가
        }

        // 만약 지금까지 센 개수가 입력받은 N과 같다면 → N번째 666 시리즈 도달
        if (cnt == N) {
            cout << num << "\n";  // 그때의 숫자를 출력
            break;  // 반복 종료
        }

        num++;  // 다음 숫자로 이동
    }

    return 0;
}
