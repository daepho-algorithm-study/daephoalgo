#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    // 근무 시간 저장 해시
    unordered_map<string, int> h;
    // 근무 시간대별 근무 시간 저장 배열
    int t[4] = {4, 6, 4, 10};
    cin >> n;
    // 버퍼에 개행 제거
    cin.ignore();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
        {
            getline(cin, s);
            // 입력받은 문자열 스트림으로 변환
            stringstream ss(s);
            // 근무자가 존재할 때, 근무자의 근무 시간 합산
            while (ss >> s)
                if (s != "-")
                    h[s] += t[j];
        }
    // 아무도 근무하지 않을 경우 공평한 것으로 간주
    if (h.empty())
    {
        cout << "Yes";
        return 0;
    }
    // 최댓값과 최솟값 저장 변수 할당
    int mx = h.begin()->second, mn = mx;
    for (auto &e : h)
    {
        // 해시값 할당
        int val = e.second;
        // 최댓값과 최솟값 갱신
        if (val < mn)
            mn = val;
        if (val > mx)
            mx = val;
    }
    // 최대와 최소의 차이가 12 이하면 조건 만족
    if (mx - mn <= 12)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}