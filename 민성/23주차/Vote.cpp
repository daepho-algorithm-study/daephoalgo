#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p, n, m;
    cin >> p;
    for (int k = 1; k <= p; k++)
    {
        // 투표 수 저장 해시 설정
        unordered_map<string, int> h;
        string x, c;
        int v;
        cin >> n >> m;
        // 해시에 공간 설정
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            h[x] = 0;
        }
        // 해시에 투표 수 저장
        for (int i = 0; i < m; i++)
        {
            cin >> x >> v >> c;
            h[x] += v;
        }
        // 승자의 이름과 투표 수 저장 변수 할당
        int mx = 0;
        string w;
        // 최고 투표 수를 받은 사람 정보 저장
        for (auto e : h)
            if (e.second > mx)
            {
                mx = e.second;
                w = e.first;
            }
        // 동률 체크 변수
        bool check = false;
        // 동률 체크
        for (auto e : h)
            if (e.second == mx && w != e.first)
            {
                check = true;
                break;
            }
        // 동률의 유무에 따라 출력
        cout << "VOTE " << k << ": ";
        if (check)
            cout << "THERE IS A DILEMMA";
        else
            cout << "THE WINNER IS " << w << " " << mx;
        cout << "\n";
    }
    return 0;
}