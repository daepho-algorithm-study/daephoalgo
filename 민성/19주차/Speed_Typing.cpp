#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string i, p;
    cin >> t;
    // 문자열 비교
    for (int c = 1; c <= t; c++)
    {
        cin >> i >> p;
        // 문자열 길이 할당
        int is = i.size(), ps = p.size();
        // 탐색 위치 할당 변수
        int idx = 0;
        for (int k = 0; k < ps; k++)
        {
            // P 문자열에서 I 문자열 탐색
            if (i[idx] == p[k])
                idx++;
            // I 문자열을 모두 찾았으면 탐색 종료
            if (idx == is)
                break;
        }
        cout << "Case #" << c << ": ";
        // I 문자열 탐색 여부 판별 후 정답 출력
        if (idx == is)
            cout << ps - is;
        else
            cout << "IMPOSSIBLE";
        cout << "\n";
    }
    return 0;
}