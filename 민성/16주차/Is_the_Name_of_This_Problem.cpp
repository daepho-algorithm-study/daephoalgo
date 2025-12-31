#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (1)
    {
        getline(cin, s);
        // END 입력 시 종료
        if (s == "END")
            break;
        // 문자열 길이 저장
        int ln = s.size();
        // 최소 조건 불만족 시 부정 출력
        if (ln < 5 || s[0] != '"' || s[(ln - 3) / 2 + 1] != '"' || s[(ln - 3) / 2 + 2] != ' ')
        {
            cout << "not a quine" << "\n";
            continue;
        }
        // quine 확인 대상 문자열 추출
        string q = s.substr(1, (ln - 3) / 2);
        // 대상 문자열에 따옴표 포함 시 부정 출력
        if (q.find('"') != string::npos)
        {
            cout << "not a quine" << "\n";
            continue;
        }
        // 조건 만족 시 quine 문자열 출력
        if (q == s.substr((ln - 3) / 2 + 3))
            cout << "Quine(" << q << ")\n";
        else
            cout << "not a quine" << "\n";
    }
    return 0;
}