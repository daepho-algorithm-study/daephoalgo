#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void bt(int cnt);     // 수열을 출력하기 위한 백트래킹 함수 정의
vector<int> seq;      // 출력할 수열을 저장할 변수
set<vector<int>> dup; // 똑같이 생긴 수열 제외 변수
int num[8];           // 수열에 사용될 수를 저장할 배열
bool check[8];        // 해당 번호에 저장된 수가 사용되었는지 체크하기 위한 배열
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n); // 수열을 사전 순으로 출력하기 위해 수를 오름차순 정렬
    bt(0);
    for (auto it = dup.begin(); it != dup.end(); it++)
    {
        vector<int> temp = *it;
        for (int i = 0; i < m; i++)
            cout << temp[i] << " "; // set에 남은 수열을 차례대로 출력
        cout << "\n";
    }
    return 0;
}

void bt(int cnt)
{
    if (cnt == m)
    {
        dup.insert(seq); // set에 수열을 저장하여 중복 수열 제거
        return;
    }
    for (int i = 0; i < n; i++)
        if (!check[i])
        {
            check[i] = true;
            seq.push_back(num[i]); // 수열에 사용되지 않은 수이면 수열에 추가
            bt(cnt + 1);           // 수열 다음 자리에 올 수를 탐색
            check[i] = false;
            seq.pop_back(); // 완성된 수열을 출력한 다음은 다시 수열에서 제거
        }
}