#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            if (s[j] >= 65 && s[j] <= 90)
                s[j] += 32; // 대문자이면 소문자로 변환
        cout << s << "\n";
    }
    return 0;
}