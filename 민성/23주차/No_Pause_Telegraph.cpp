#include <iostream>
#include <string>

using namespace std;

// 알파벳 점자 저장 배열
string dot[7] = {".--", "-.", "---", "..", "--..", "--.-", ".-."};
// 점자 크기 저장 배열
int ds[7] = {3, 2, 3, 2, 4, 4, 3};
// 점자 해석 알파벳 저장 배열
string alpha[7] = {"A", "B", "C", "D", "E", "F", "G"};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (cin >> s)
    {
        // 탐색 위치와 문자열 크기,  번역된 문자열 저장 변수 할당
        int idx = 0, ss = s.size();
        string tl = "";
        // 번역 불가 체크 변수
        bool check = false;
        while (!check && idx < ss)
        {
            for (int i = 0; i < 7; i++)
            {
                // 문자열 내에서 알파벳이 탐색되었을 때, 번역 후 다음 위치에서 탐색
                if (idx + ds[i] <= ss && dot[i] == s.substr(idx, ds[i]))
                {
                    tl += alpha[i];
                    idx += ds[i];
                    break;
                }
                // 번역 불가 시 불가능 문구 저장
                if (i == 6)
                {
                    tl = "could not be translated";
                    check = true;
                }
            }
        }
        cout << tl << "\n";
    }
    return 0;
}