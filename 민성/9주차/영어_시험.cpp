#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cout << s; // 정답 길이만큼 s 출력
    return 0;
}