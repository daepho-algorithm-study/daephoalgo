#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    // 문자열 크기 할당
    int i = 0, ss = s.size();
    while (i < ss)
    {
        int cnt = 0;
        // w 개수 카운팅
        while (s[i] == 'w')
        {
            cnt++;
            i++;
        }
        // w로 시작하지 않으면 0 출력
        if (!cnt)
        {
            cout << 0;
            return 0;
        }
        // w 개수만큼 o,l,f가 순서대로 있는 지 확인
        for (int j = 0; j < cnt && i < ss; j++, i++)
            // 개수가 다르면 즉시 0 출력
            if (i == ss || s[i] != 'o')
            {
                cout << 0;
                return 0;
            }
        for (int j = 0; j < cnt && i < ss; j++, i++)
            if (i == ss || s[i] != 'l')
            {
                cout << 0;
                return 0;
            }
        for (int j = 0; j < cnt; j++, i++)
            if (i == ss || s[i] != 'f')
            {
                cout << 0;
                return 0;
            }
    }
    cout << 1;
    return 0;
}