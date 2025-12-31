#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    // 정답 개수 저장 변수
    int cnt = 0;
    // 입력 파일의 끝까지 반복
    while (cin >> s)
        // 문자열에 존재하는 joke 수 합산
        if (s.size() >= 4)
            for (int i = 0; i < s.size() - 3; i++)
                if (s[i] == 'j' && s[i + 1] == 'o' && s[i + 2] == 'k' && s[i + 3] == 'e')
                    cnt++;
    cout << cnt;
    return 0;
}