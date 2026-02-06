#include <iostream>
#include <string>

using namespace std;

// 비밀번호 구성 알파벳 체크 변수
int alpha[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string pw, msg;
    // 탐색 위치 변수
    int idx = 0;
    cin >> pw >> msg;
    // 문자열 길이 할당
    int pws = pw.size(), msgs = msg.size();
    // 비밀번호 구성 알파벳 체크
    for (int i = 0; i < pws; i++)
        alpha[pw[i] - 'A']++;
    // 메시지에서 비밀번호 탐색
    for (int i = 0; i < msgs; i++)
        if (alpha[msg[i] - 'A'])
        {
            // 현재 위치의 비밀번호와 매칭되면 다음 위치 탐색
            if (msg[i] == pw[idx])
            {
                idx++;
                alpha[msg[i] - 'A']--;
            }
            // 유효하지 않은 비밀번호면 즉각 반복 종료
            else
                break;
            // 유효한 비밀번호면 PASS 출력 후 종료
            if (idx == pws)
            {
                cout << "PASS";
                return 0;
            }
        }
    // 비밀번호 탐색 실패 시 FAIL 출력
    cout << "FAIL";
    return 0;
}