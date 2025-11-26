#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string s1, s2;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        set<char> b1, b2;  // 문자 비교 set
        bool check = true; // 문자 체크 변수
        cin >> s1 >> s2;
        for (int j = 0; j < s1.size(); j++)
            b1.insert(s1[j]);
        for (int j = 0; j < s2.size(); j++) // 문자 삽입
            b2.insert(s2[j]);
        if (b1 == b2)
            cout << "YES"; // set의 구성요소가 모두 같을 때 YES 출력
        else
            cout << "NO"; // 아니면 NO 출력
        cout << "\n";
    }
    return 0;
}