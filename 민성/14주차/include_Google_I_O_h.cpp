#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, b;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> b >> s;
        // 번역된 메시지 저장 변수
        string msg = "";
        for (int j = 0; j < b * 8; j += 8)
        {
            // 아스키 코드 값 저장 변수
            int ascii = 0;
            // 비트 연산 계산 변수
            int bt = 128;
            for (int k = 0; k < 8; k++)
            {
                // 해당 비트가 1에 해당하면 비트 합산
                if (s[j + k] == 'I')
                    ascii += bt;
                bt /= 2;
            }
            // 아스키 코드 문자로 번역 후 저장
            msg += ascii;
        }
        cout << "Case #" << i + 1 << ": " << msg << "\n";
    }
    return 0;
}