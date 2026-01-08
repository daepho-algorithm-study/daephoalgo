#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        // 접두사나 접미사 존재 여부 확인 변수
        bool check = false;
        // 문자열 길이 a < b < c 순으로 문자열 정렬
        if (a.size() > b.size())
            swap(a, b);
        if (a.size() > c.size())
            swap(a, c);
        if (b.size() > c.size())
            swap(b, c);
        // a과 b 비교
        if (a == b.substr(0, a.size()))
            check = true;
        if (a == b.substr(b.size() - a.size()))
            check = true;
        // a과 c 비교
        if (a == c.substr(0, a.size()))
            check = true;
        if (a == c.substr(c.size() - a.size()))
            check = true;
        // b와 c 비교
        if (b == c.substr(0, b.size()))
            check = true;
        if (b == c.substr(c.size() - b.size()))
            check = true;
        if (!check)
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";
    }
    return 0;
}