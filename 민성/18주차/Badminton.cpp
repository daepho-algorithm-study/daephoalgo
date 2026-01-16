#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    // A와 B의 점수 저장 변수
    int a = 0, b = 0;
    // 매치승 저장 변수
    int ma = 0, mb = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // 이긴 사람의 점수 추가
        if (s[i] == 'A')
            a++;
        else
            b++;
        // 경기 종료 시
        if (a == 21 || b == 21)
        {
            // 매치 승 기록
            if (a > b)
                ma++;
            else
                mb++;
            // 매치 점수 출력 후 점수 리셋
            cout << a << "-" << b << "\n";
            a = 0, b = 0;
        }
    }
    // 승자 출력
    if (ma > mb)
        cout << "A";
    else
        cout << "B";
    return 0;
}