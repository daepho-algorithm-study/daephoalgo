#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    // 방향 확인 변수(false는 왼쪽)
    bool dir = false;
    while (1)
    {
        cin >> s;
        // 입력된 문자열이 99999면 반복 종료
        if (s == "99999")
            break;
        // 앞 두자리 숫자 합 저장 변수
        int sm = s[0] + s[1] - '0' * 2;
        // 합이 짝수냐 홀수냐에 따라 방향 전환
        if (sm % 2 != 0)
            dir = false;
        else if (sm != 0)
            dir = true;
        // 방향에 따라 출력
        if (dir)
            cout << "right ";
        else
            cout << "left ";
        // 나머지 3자리 숫자도 출력
        cout << s.substr(2) << "\n";
    }
    return 0;
}